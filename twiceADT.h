#pragma once
#include <iostream>
using namespace std;

typedef int ElemType;

typedef class LNode
{
public:
	LNode* front;
	ElemType data;
	LNode* next;
	LNode(ElemType nums) :front(NULL), data(nums), next(NULL)
	{
	}
}LNode, * LinkedList;

class twiceList//双向链表与单向基本相同，就偷点懒
{
public:
	//构造函数
	twiceList();
	twiceList(int data[], int osize);
	twiceList(const twiceList& other);
	//重载运算符
	twiceList operator=(const twiceList& other);
	twiceList operator+(const twiceList& other);
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

	LinkedList head;
	int size;
};