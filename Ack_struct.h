#ifndef ACK_STRUCT_H
#define ACK_STRUCT_H
#include<iostream>
//  от клиента идет

#pragma pack (push, 1)

struct Ack   // подтверждение от клиента
{
    int send_packet;
    int recv_packet;
    std::string Ip_Multicast;
    std::string id_test;
};

#pragma pack (pop)























#endif // ACK_STRUCT_H
