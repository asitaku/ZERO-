#pragma once
#include <iostream>
using namespace std;

typedef int ElemType;

typedef class LNode
{
public:
	ElemType data;
	LNode* next = NULL;
	LNode(ElemType nums) :data(nums), next(NULL)
	{
	}
}LNode, * LinkedList;

class List
{
public:
	//构造函数
	List();
	List(int data[], int osize);
	List(const List& other);
	//重载运算符
	List operator=(const List& other);
	List operator+(const List& other);
	//查找节点
	ElemType search(int pos);
	//删除节点
	//void detele_data(ElemType data);
	void detele_pos(int pos);
	//插入节点
	void insert(ElemType data, int pos);
	void insert(ElemType data);

	void clean();//销毁
	void reverse();//反转链表
	void print();//输出

	void addPos();
	void serarchPos();
	void detelePos();
	void change_oddeven();
	void find_middle();

	LinkedList head;
	int size;
};
