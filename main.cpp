#include "mainwindow.h"
#include "ribbonmainwindows.h"

#include <QApplication>
#include<iostream>
//#include <WinSock2.h>
//#include "winsock.h"
//#include <WS2tcpip.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //WSADATA wsaData;
    //int result = WSAStartup(MAKEWORD(2, 2), &wsaData);
   //  if (result != 0)
    //   {
    //     std::cout<<"Failed. Error Code: "<< WSAGetLastError()<<std::endl;
    //   }
    MainWindow w;
    w.show();
    return a.exec();
}
