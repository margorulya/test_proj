#ifndef SERVER_H
#define SERVER_H

#include <vector>
#include <thread>
#include <mutex>
#include <WinSock2.h>

#include"application.h"
#include "session.h"

class Server
{
public:
    Server();
   ~Server();

    Application app;

private:
    std::thread* mainThread;
    std::atomic<bool> isWork;
    //SOCKET ServSocket;
    fd_set rset;
    fd_set active_fd_set;

    // проверка сокета на чтение
    void SelectThread();

};

#endif // SERVER_H
