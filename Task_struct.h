#ifndef TASK_STRUCT_H
#define TASK_STRUCT_H
#include<iostream>

#pragma pack (push, 1)

enum type_task
{
    UDP=1,

    IGMP=2
};

struct Task   //задача
{

 type_task task;
 int num_packet;
 std::string Ip_Multicast;
 std::string command_IGMP;
 //void*session;//??
};

#pragma pack (pop)

#endif // TASK_STRUCT_H
