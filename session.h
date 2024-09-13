#ifndef SESSION_H
#define SESSION_H

#include <QObject>
#include<vector>
#include <mutex>
#include <WinSock.h>
#include<Task_struct.h>
#include <Ack_struct.h>

class Application;
class Session:public QObject
{
    Q_OBJECT
public:
    explicit Session(QObject *parent = 0);

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
    void parseBuffer(Ack & ack);

};

#endif // SESSION_H
