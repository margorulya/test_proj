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

 void Session:: parseBuffer(Ack & ack)
{
  uint32_t buffer_offset=0;

  memcpy(&ack.send_packet,buffer.data()+buffer_offset,sizeof (int));

  buffer_offset+=sizeof(int);

  memcpy(&ack.recv_packet,buffer.data()+buffer_offset,sizeof (int));

  buffer_offset+=sizeof(int);

  memcpy(&ack.Ip_Multicast,buffer.data()+buffer_offset,sizeof (ack.Ip_Multicast));  //? размер

  buffer_offset+=sizeof(ack.Ip_Multicast);

  memcpy(&ack.id_test,buffer.data()+buffer_offset,sizeof (ack.id_test));  //? размер

}
