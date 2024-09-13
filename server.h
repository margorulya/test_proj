#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <vector>
#include <thread>
#include <mutex>
#include "application.h"

class Server:public QObject
{
        Q_OBJECT
public:
    explicit Server(QObject *parent = 0);
   // Server();
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
private slots:
    void send_task();

};

#endif // SERVER_H
