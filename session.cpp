 #include "session.h"
#include "application.h"

//ЗДЕСЬ БУДЕТ РЕАЛИЗАЦИЯ ПОДКЛЮЧЕНИЯ КЛИЕНТА
Session::Session(Application *app)
{
    this->app = app;

}

Session::~Session()
{
    closesocket(socket);
}
