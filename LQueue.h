#pragma once
#include <iostream>
#include <typeinfo>
using namespace std;

class Node
{
public:
    void* data;                   //数据域指针
    Node* next;                   //指向当前结点的下一结点
    int datatype;
    Node(void* data, int datatype) : data(data), next(NULL), datatype(datatype)
    {
    }
};// Node;

typedef enum
{
    FALSE = 0, TRUE = 1
} Status;
//char type;
//char datatype[30];
enum
{
    CHAR = 1
};

class LQueue
{
public:
    Node* front;                   //队头
    Node* rear;                    //队尾
    int length;            //队列长度

    LQueue();//构造函数初始化
    //void DestoryLQueue();不知道怎么销毁类
    Status IsEmptyLQueue();//判断是否为空
    Node* GetHeadLQueue();//获取队头
    Status LengthLQueue();//检测队列长度
    Status EnLQueue(void* data, int datatype);//入队
    Status DeLQueue();//出队
    void ClearLQueue();//清空队列
    Status TraverseLQueue();//遍历，不知道怎么表现，此处通过打印
    void LPrint();//打印所有数据
    void NPrint(Node* node);//打印单个数据
    void AddNode();//面向用户的入队操作
};// LQueue;

void show_LQueue_Menu();


