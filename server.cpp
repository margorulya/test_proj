#include "server.h"

bool init_socket(int port, SOCKET& socket)
{
    SOCKADDR_IN  servaddr;
    WSADATA wsaData;

    WSAStartup(MAKEWORD(2, 2), &wsaData);
    socket = (AF_INET, SOCK_STREAM, 0);
    if (socket == INVALID_SOCKET) {
        std::cerr << "Error creating server socket" << std::endl;
        WSACleanup();
        return false;
    }
    bool enable = true;
    if (setsockopt(socket, SOL_SOCKET, SO_REUSEADDR, (char*)&enable, sizeof(BOOL)) < 0)
    {
        return false;
    }
    memset(&servaddr, 0, sizeof(sockaddr_in));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = INADDR_ANY;
    servaddr.sin_port = htons(port);

    if (bind(socket, (SOCKADDR*)&servaddr, sizeof(servaddr)) == SOCKET_ERROR)
    {
        std::cerr << "Error binding server socket" << std::endl;
        closesocket(socket);
        WSACleanup();
        return false;
    }

    BOOL l = TRUE;
    ioctlsocket (socket, FIONBIO, (unsigned long* ) &l); // неблокирующий режим

    if (listen(socket, SOMAXCONN) == SOCKET_ERROR)
    {
        std::cerr << "Error listening on server socket" << std::endl;
        closesocket(socket);
        WSACleanup();
        return false;
    }
    return true;
 }

Server::Server(QObject *parent) : QObject(parent), app()
{
   init_socket(4444, app.tcp_server);

   /* Initialize the set of active sockets. */
   FD_ZERO(&active_fd_set);
   FD_SET(app.tcp_server, &active_fd_set);

   std::atomic_init(&isWork, true);
   mainThread = new std::thread(&Server::SelectThread, this);
}

Server::~Server()
{
    isWork = false;
    mainThread->join();
    {
        std::lock_guard<std::mutex>(app.app_mutex);
       // for (const auto& [ key, session ] : app.session_list) стиль с++17
        for (const auto &session :  app.session_list)
        {
            if (session.second->counter == 0)
            {
                //app.session_list.erase(key);
                delete session.second;
                //app.session_list.clear();
                //FD_CLR(s, *set) - удаляет дескриптор из набора
            }
        }
    }
   delete mainThread;
}

void Server::SelectThread()
{    
   // int smax = (ServSocket)+1;
    timeval time_out; // Таймаут
    time_out.tv_sec = 1000;
    struct sockaddr_in clientname;
    int size = sizeof (clientname);

    while (isWork)
    {
          rset = active_fd_set;

          if (select(FD_SETSIZE, &rset, NULL, NULL, &time_out) == SOCKET_ERROR)
          {
            std::cerr << "Select failed: " << WSAGetLastError() << std::endl;
            // closesocket(serverSocket);
            WSACleanup();

          }
          /* if( (nready= select(FD_SETSIZE,&rset, NULL, NULL, NULL))<0)
      {
          std::cout<<" Ошибка";
      }  */
          else
        {
            if (FD_ISSET(app.tcp_server, &rset))// FD_ISSET(s, *set) - проверяет, находится ли дескриптор в наборе. Не ноль, если находится.
            {
                SOCKET clientSocket = accept(app.tcp_server,  (struct sockaddr *) &clientname, &size);
                if (clientSocket == INVALID_SOCKET)
                {
                   std::cerr << "Accept failed: " << WSAGetLastError() << std::endl;
                  // closesocket(serverSocket);
                   WSACleanup();
                }
                std::cout<<"Client connected"<< std::endl;
                std::lock_guard<std::mutex>(app.app_mutex);
                Session* session = new Session(&app);//создаем сессию
                session->socket = clientSocket; //сохраняем сокет
                app.session_list[clientSocket] = session;//добавляем в лист сессий
                FD_SET(clientSocket,&active_fd_set); //добавляем в селект
            } else {
                //чтение?
                 for (u_int i = 0; i < rset.fd_count; i++)
                 {
                     SOCKET clientSocket = rset.fd_array[i];
                     char buf[1024];

                     Session* session = NULL;
                     {
                         std::lock_guard<std::mutex>(app.app_mutex);
                         session = app.session_list[clientSocket]; //вытаскиваем сессию из списка
                     }

                     {
                         std::lock_guard<std::mutex>(session->session_mutex);
                         session->counter++;

                         Ack ack;
                         int res = 0;
                         while (res != 0)
                         {
                             res =  recv(clientSocket, (char*)(session->buffer.data() + session->buffer_offset), session->buffer.size() - session->buffer_offset, 0);
                             session->parseBuffer(ack);

                             if(res>0)
                             {
                                 session->buffer_offset += res;
                             }

                         }
                       session->counter--;
                     }
                     session = NULL;
                 }
             }
          }
    }
}

void Server::send_task()
{



}


