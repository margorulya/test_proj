#ifndef SESSION_H
#define SESSION_H

#include<vector>
#include <mutex>
#include <WinSock2.h>


class Application;
class Session
{
public:
    Session(Application* app);
    ~Session();

    // сигнал в mainwinsod новые данные таблица
    Application* app;

    uint64_t counter;
    std::mutex session_mutex;

    //bool inUse =false;

    SOCKET socket;
    std::vector<uint8_t> buffer;
    uint32_t buffer_offset= 0;
    uint32_t buffer_step =1024*64;

};

#endif // SESSION_H
