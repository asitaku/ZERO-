#include "LQueue.h" 

LQueue::LQueue()//构造函数初始化
{
	front = NULL;
	rear = NULL;
	length = 0;
}

//void LQueue::DestoryLQueue()
//{
//	ClearLQueue();
//	//不知道怎么销毁类
//}

Status LQueue::IsEmptyLQueue()//判断是否为空
{
	if (length == 0)
		return TRUE;
	else
		return FALSE;
}

Node* LQueue::GetHeadLQueue()//获取队头
{
	return front;
}

Status LQueue::LengthLQueue()//检测队列长度
{
	if (IsEmptyLQueue())
	{
		cout << "队列为空！" << endl;
		return FALSE;
	}
	cout << length << endl;
	return TRUE;
}

Status LQueue::EnLQueue(void* data, int datatype)//入队
{
	if (IsEmptyLQueue())
	{
		rear = new Node(data, datatype);
		front = rear;
	}
	else
	{
		Node* now = new Node(data, datatype);
		rear->next = now;
		rear = now;
	}
	length++;
	return TRUE;
}

Status LQueue::DeLQueue()//出队
{
	if (IsEmptyLQueue())
	{
		cout << "队列为空！" << endl;
		return FALSE;
	}
	Node* now = front;
	if (length == 1)
	{
		front = NULL;
		rear = NULL;
	}
	else
	{
		front = front->next;
	}
	delete now;
	length--;
	return TRUE;
}

void LQueue::ClearLQueue()//清空队列
{
	if (IsEmptyLQueue())
	{
		std::cout << "该队列为空！" << endl;
		return;
	}
	while (DeLQueue());
	cout << "已清空队列！" << endl;
}

Status LQueue::TraverseLQueue()//遍历，不知道怎么表现，此处通过打印
{
	if (IsEmptyLQueue())
	{
		std::cout << "该队列为空！" << endl;
		return FALSE;
	}
	std::cout << "遍历结果：" << endl;
	Node* now = front;
	while (now)
	{
		if (now->datatype == 1)
		{
			string* stringdata = static_cast<string*>(now->data);
			cout << *stringdata << ' ';
		}
		else if (now->datatype == 2)
		{
			int* intdata = static_cast<int*>(now->data);
			cout << *intdata << ' ';
		}
		else if (now->datatype == 3)
		{
			float* floatdata = static_cast<float*>(now->data);
			cout << *floatdata << ' ';
		}
		now = now->next;
	}
	std::cout << endl;
	return TRUE;
}

void LQueue::LPrint()//打印所有数据
{
	if (IsEmptyLQueue())
	{
		std::cout << "该队列为空！" << endl;
		return;
	}
	Node* now = front;
	while (now)
	{
		if (now->datatype == 1)
		{
			string* stringdata = static_cast<string*>(now->data);
			cout << *stringdata << ' ';
		}
		else if (now->datatype == 2)
		{
			int* intdata = static_cast<int*>(now->data);
			cout << *intdata << ' ';
		}
		else if (now->datatype == 3)
		{
			float* floatdata = static_cast<float*>(now->data);
			cout << *floatdata << ' ';
		}
		now = now->next;
	}
	std::cout << endl;
}

void LQueue::NPrint(Node* node)//打印单个数据
{
	if (node->datatype == 1)
	{
		string* stringdata = static_cast<string*>(node->data);
		cout << *stringdata << ' ';
	}
	else if (node->datatype == 2)
	{
		int* intdata = static_cast<int*>(node->data);
		cout << *intdata << ' ';
	}
	else if (node->datatype == 3)
	{
		float* floatdata = static_cast<float*>(node->data);
		cout << *floatdata << ' ';
	}
}

void LQueue::AddNode()//面向用户的入队操作
{
	int stringselect, intselect, floatselect;
	while (true)
	{
		cout << "请问有想要入队的字词句(即字符或字符串)吗？\n1.有\t2.无" << endl;
		cin >> stringselect;
		if (stringselect == 1 || stringselect == 2)
			break;
		cout << "输入有误！请重新输入。" << endl;
	}
	if (stringselect == 1)
	{
		int num1;
		while (true)
		{
			cout << "请问要输入几个字词句:\nnum1=";
			cin >> num1;
			if (num1 > 0 && num1 < 100)
				break;
			cout << "输入有误！请重新输入。" << endl;
		}
		for (int i = 0; i < num1; i++)
		{
			cout << "请输入第" << i + 1 << "个字词句数据" << endl;
			string data;
			cin >> data;
			string* stringdata = new string(data);
			EnLQueue(stringdata, 1);
		}
	}
	while (true)
	{
		cout << "请问有想要入队的整数吗？\n1.有\t2.无" << endl;
		cin >> intselect;
		if (intselect == 1 || intselect == 2)
			break;
		cout << "输入有误！请重新输入。" << endl;
	}
	if (intselect == 1)
	{
		int num2;
		while (true)
		{
			cout << "请问要输入几个整数:\nnum2=";
			cin >> num2;
			if (num2 > 0 && num2 < 100)
				break;
			cout << "输入有误！请重新输入。" << endl;
		}
		for (int i = 0; i < num2; i++)
		{
			cout << "请输入第" << i + 1 << "个整数数据" << endl;
			int data;
			cin >> data;
			int* intdata = new int(data);
			EnLQueue(intdata, 2);
		}
	}
	while (true)
	{
		cout << "请问有想要入队的小数吗？\n1.有\t2.无" << endl;
		cin >> floatselect;
		if (floatselect == 1 || floatselect == 2)
			break;
		cout << "输入有误！请重新输入。" << endl;
	}
	if (floatselect == 1)
	{
		int num3;
		while (true)
		{
			cout << "请问要输入几个小数:\nnum3=";
			cin >> num3;
			if (num3 > 0 && num3 < 100)
				break;
			cout << "输入有误！请重新输入。" << endl;
		}
		for (int i = 0; i < num3; i++)
		{
			cout << "请输入第" << i + 1 << "个小数数据" << endl;
			float data;
			cin >> data;
			float* floatdata = new float(data);
			EnLQueue(floatdata, 3);
		}
	}
	cout << "入队已完成！" << endl;
}

void show_LQueue_Menu()
{
	std::cout << "**************************************************************" << endl;
	std::cout << "**************欢迎来到QG第二次大组作业队列!****************" << endl;
	std::cout << "**********************请输入需要进行的操作：********************" << endl;
	std::cout << "********************1.入队*********************************" << endl;
	std::cout << "********************2.出队*********************************" << endl;
	std::cout << "********************3.清空队列*********************************" << endl;
	//std::cout << "********************4.销毁队列*********************************" << endl;
	std::cout << "********************4.遍历队列*********************************" << endl;
	std::cout << "********************5.打印队列*********************************" << endl;
	std::cout << "********************6.获取队列长度*********************************" << endl;
	std::cout << "********************7.获取队头数据*********************************" << endl;
	std::cout << "********************0.退出当前队列*********************************" << endl;
	std::cout << "**************************************************************" << endl;
}