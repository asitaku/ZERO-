#include "AnADT.h"

List::List()
{
	size = 0;
	head = NULL;
}

List::List(ElemType data[], int osize)
{
	head = NULL;
	size = 0;
	for (int i = 0; i < osize; i++)
	{
		(*this).insert(data[i]);//利用添加函数
	}
}

List::List(const List& other)
{
	head = NULL;
	size = 0;
	LinkedList now = other.head;
	while (now != NULL)
	{
		(*this).insert(now->data);
		now = now->next;
	}
}

List List::operator=(const List& other)//重载=
{
	if (size)
		(*this).clean();//清空防止内存泄漏
	LinkedList now = other.head;
	while (now != NULL)
	{
		(*this).insert(now->data);
		now = now->next;
	}
	size = other.size;
	return (*this);
}

List List::operator+(const List& other)//重载+
{
	LinkedList now = other.head;
	while (now != NULL)
	{
		(*this).insert(now->data);//直接在链表结尾进行添加
		now = now->next;
	}
	size += other.size;
	return (*this);
}

ElemType List::search(int pos)
{
	LinkedList now = head;
	for (int i = 0; i < pos; i++)
	{
		now = now->next;
	}
	return now->data;
}

//void List::detele_data(ElemType data)//根据数据删除//有BUG，之后在debug
//{
//	LinkedList now = head;
//	while (now != NULL)
//	{
//		if (now->data == data)
//		{
//			if (now == head)
//			{
//				LinkedList bedel = head;
//				head = now;
//				size--;
//				delete bedel;
//			}
//			else
//			{
//				LinkedList back = head;
//				while (back->next != now)
//				{
//					back = back->next;
//				}
//				back->next = now->next;
//				LinkedList bedel = now;
//				size--;
//				delete bedel;
//			}
//		}
//		now = now->next;
//	}
//}

void List::detele_pos(int pos)//根据节点位置删除
{
	if (pos == 0)//在第一节点
	{
		if (size == 1)//只有一个LNode
		{
			delete head;
			head = NULL;
			size = 0;
		}
		else
		{
			LinkedList bedel = head;
			head = head->next;
			size--;
			delete bedel;
		}
	}
	else
	{
		LinkedList back = head;
		LinkedList now = head->next;
		for (int i = 0; i < pos - 1; i++)
		{
			back = back->next;
			now = now->next;
		}
		back->next = now->next;//绕过now
		size--;
		delete now;
	}
}

void List::insert(ElemType data)//用于初始化与类相加
{
	if (head == NULL)
	{
		head = new LNode(data);
	}
	else
	{
		LinkedList now = head;
		while (now->next != NULL)
			now = now->next;
		now->next = new LNode(data);
	}
	size++;
}

void List::insert(ElemType data, int pos)
{
	if (pos == 0)//在链表头
	{
		LinkedList temp = head;
		head = new LNode(data);
		head->next = temp;
	}
	else if (pos == size)//在尾部
	{
		LinkedList now = head;
		while (now->next != NULL)
		{
			now = now->next;
		}
		now->next = new LNode(data);//在尾部创造新节点
	}
	else//在链表中间
	{
		LinkedList back = head;
		for (int i = 0; i < pos - 1; i++)//到达要插入节点的前一位
		{
			back = back->next;
		}
		LinkedList now = new LNode(data);
		LinkedList next = back->next;
		back->next = now;
		now->next = next;
	}
}

void List::clean()//销毁
{
	LinkedList now = head;
	while (now != NULL)
	{
		LinkedList temp = now;
		now = now->next;
		delete temp;
	}
	size = 0;
	head = NULL;
}

void List::reverse()//反转链表
{
	if (head == NULL)//若空链表直接跳出
	{
		return;
	}
	LinkedList back = head;
	LinkedList now = head->next;
	while (now != NULL)
	{
		LinkedList temp = now->next;
		now->next = back;//将后一位的next指向上一位
		back = now;
		now = temp;//now, back向前一位
	}
	head->next = NULL;
	head = back;
}

void List::print()//输出链表数据
{
	if (head == NULL)
	{
		cout << "链表无数据！" << endl;
		return;
	}
	LinkedList now = head;
	while (now != NULL)
	{
		cout << now->data << " ";
		now = now->next;
	}
	cout << endl;
}

void List::addPos()
{
	if (head == NULL)
	{
		cout << "当前链表数据为空，添加值顺序由用户决定，无法指定添加点！" << endl;
	}
	cout << "请输入想要添加的一串数据的个数：" << endl;
	int num;
	cin >> num;
	if (num <= 0)
		return;
	if (head)
	{
		cout << "想要输入的位置：（链表头为0）" << endl;
		int pos;
		cin >> pos;
		cout << "请输入数据：(当前数据类型为整数)" << endl;
		for (int i = 0; i < num; i++)
		{
			ElemType in;
			cin >> in;
			(*this).insert(in, pos + i);
		}
		cout << "添加成功！" << endl;
		return;
	}
	cout << "请输入数据：(当前数据类型为整数)" << endl;
	for (int i = 0; i < num; i++)
	{
		ElemType in;
		cin >> in;
		(*this).insert(in);
	}
	cout << "添加成功！" << endl;
}

void List::serarchPos()
{
	if (!head)
	{
		cout << "当前链表为空！" << endl;
		return;
	}
	cout << "请输入想要查找的节点位置：（链表头为0）" << endl;
	int pos;
	cin >> pos;
	if (pos < 0 || pos >= size)
	{
		cout << "输入不在链表范围内" << endl;
		return;
	}
	cout << (*this).search(pos) << endl;
	cout << "查找成功" << endl;
}

void List::detelePos()
{
	if (!head)
	{
		cout << "当前链表为空！" << endl;
		return;
	}
	/*cout << "选择根据节点位置还是所含数据删除：\n1.节点位置\t2.数据" << endl;
	int select;
	cin >> select;*/
	//if (select == 1)
	//{
	cout << "请输入节点位置：（链表头为0）" << endl;
	int pos;
	cin >> pos;
	detele_pos(pos);
	//}
	/*else if (select == 2)
	{
		cout << "请输入删除内容：" << endl;
		ElemType data;
		cin >> data;
		detele_data(data);
	}*/
	cout << "删除成功！" << endl;
}

void List::change_oddeven()
{
	LinkedList back = head;
	LinkedList now = head->next;
	head = now;
	back->next = now->next;
	now->next = back;
	back = back->next;
	now = now->next;
	while (now&&back)
	{
		LinkedList swap = now;
		now = back;
		back = swap;
		LinkedList temp = now->next;
		now->next = temp->next;
		back->next = temp;
		temp->next = now;
		back = temp;
		now = now->next;
	}
}