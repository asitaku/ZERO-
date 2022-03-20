#include "twiceADT.h"

//构造函数
twiceList::twiceList()
{
	size = 0;
	head = NULL;
}

twiceList::twiceList(int data[], int osize)
{
	head = NULL;
	size = 0;
	for (int i = 0; i < osize; i++)
	{
		(*this).insert(data[i]);
	}
}

twiceList::twiceList(const twiceList& other)
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

//重载运算符
twiceList twiceList::operator=(const twiceList& other)
{
	if (size)
		(*this).clean();
	LinkedList now = other.head;
	while (now != NULL)
	{
		(*this).insert(now->data);
		now->next->front = now;
		now = now->next;
	}
	size = other.size;
	return (*this);
}

twiceList twiceList::operator+(const twiceList& other)
{
	LinkedList now = other.head;
	LinkedList back = head;
	while (back->next)
		back = back->next;
	now->front = back;
	while (now != NULL)
	{
		(*this).insert(now->data);
		now = now->next;
	}
	size += other.size;
	return (*this);
}

//查找节点
ElemType twiceList::search(int pos)
{
	LinkedList now = head;
	for (int i = 0; i < pos; i++)
	{
		now = now->next;
	}
	return now->data;

}

//删除节点
//void twiceList::detele_data(ElemType data)
//{
//	LinkedList now = head;
//	now->front = NULL;
//	while (now->next)
//	{
//		if (now->data == data)
//		{
//			if (now == head)
//			{
//				//if (size != 1)
//				//{
//					LinkedList bedel = head;
//					head = now;
//					head->front = NULL;
//					size--;
//					delete bedel;
//				//}
//				//else
//				//{
//				//	delete now;
//				//	now = NULL;
//				//	size--;
//				//	return;
//				//}
//			}
//			else
//			{
//				LinkedList back = head;
//				while (back->next != now)
//				{
//					back = back->next;
//				}
//				back->next = now->next;
//				back->next->front = back;
//				LinkedList bedel = now;
//				size--;
//				delete bedel;
//			}
//		}
//		now = now->next;
//	}
//	now = NULL;
//}

void twiceList::detele_pos(int pos)
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
			head->front = NULL;
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
		now->next->front = back;
		size--;
		delete now;
	}

}
//插入节点
void twiceList::insert(ElemType data, int pos)
{
	if (pos == 0)//在链表头
	{
		LinkedList temp = head;
		head = new LNode(data);
		temp->front = head;
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
		now->next->front = now;
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
		next->front = now;
		back->next = now;
		now->front = back;
		now->next = next;
	}
}

void twiceList::insert(ElemType data)
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
		now->next->front = now;
	}
	size++;
}

void twiceList::clean()//销毁
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

void twiceList::reverse()//反转链表
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
		back->front = now;
		back = now;
		now = temp;//now, back向前一位
	}
	head->next = NULL;
	head = back;
}

void twiceList::print()//输出
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

void twiceList::addPos()
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

void twiceList::serarchPos()
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

void twiceList::detelePos()
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