#ifndef APPLICATION_H
#define APPLICATION_H

#include <mutex>
#include "string.h"
//#include "map"
#include<iostream>
#include <unordered_map>
#include<session.h>

class Session;

class Application
{
public:
    Application();

    std::unordered_map<SOCKET, Session*> session_list;
    std::mutex app_mutex;
    SOCKET tcp_server;

};

#endif // APPLICATION_H
