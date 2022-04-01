#pragma once
#include <iostream>
using namespace std;
#include <string>

typedef enum Status
{
	ERROR = 0,
	SUCCESS = 1
} Status;


template<class T>
class StackNode
{
public:
	T data;
	StackNode<T>* next;
	StackNode(T data) :data(data), next(NULL)
	{
	}
};

//#define LinkStackPtr StackNode*

void CalculateForUser();
int calculator();

void show_Menu();

template<class T>
class  LinkStack
{
public:
	LinkStack()//初始化栈
	{
		this->count = 0;
		this->top = NULL;
	}
	Status isEmptyLStack()//判断栈是否为空
	{
		return (this->top == NULL) ? SUCCESS : ERROR;
	}
	T& getTopLStack()//得到栈顶元素
	{
		return top->data;
	}

	void getTop()
	{
		if (isEmptyLStack())
		{
			cout << "该链栈为空！" << endl;
			return;
		}
		cout << getTopLStack() << endl;
	}

	void clearLStack()//清空栈
	{
		if (isEmptyLStack())
		{
			cout << "该链栈为空！" << endl;
			return;
		}
		while (popLStack());
		cout << "清空完毕" << endl;
	}
	//void destroyLStack();//销毁栈不会
	Status LStackLength()//检测栈长度
	{
		if (isEmptyLStack())
		{
			cout << "此链栈为空！" << endl;
			return ERROR;
		}
		cout << count << endl;
		return count;
	}
	void pushLStack(const T& data)//入栈
	{
		if (top == NULL)
		{
			top = new StackNode<T>(data);
		}
		else
		{
			StackNode<T>* now = new StackNode<T>(data);
			now->next = top;
			top = now;
		}
		count++;
	}
	Status popLStack()//出栈
	{
		if (isEmptyLStack())
		{
			return ERROR;
		}
		StackNode<T>* now = top;
		top = top->next;
		delete now;
		return SUCCESS;
	}

	void pop()//出栈面向用户的界面
	{
		if (popLStack())
		{
			cout << "出栈成功！" << endl;
		}
		cout << "该链栈为空！" << endl;
	}

	void AddNode()//入栈面向用户的界面
	{
		cout << "请问需要输入几个数据：" << endl;
		int num;
		cin >> num;
		for (int i = 0; i < num; i++)
		{
			cout << "请输入第" << i + 1 << "个数据" << endl;
			T data;
			cin >> data;
			pushLStack(data);
		}
		cout << "入栈完成！" << endl;
	}

	StackNode<T>* top;
	int	count;
};

template<class T>
void FaceUser(T& s)
{
	while (true)
	{

		int select;
		while (true)
		{
			show_Menu();
			cin >> select;
			if (select >= 0 && select <= 6)
				break;
			cout << "输入有误！请重新输入！" << endl;
			system("pause");
			system("cls");
		}
		switch (select)
		{
		case 1:
			s.AddNode();
			break;
		case 2:
			s.pop();
			break;
		case 3:
			s.getTop();
			break;
		case 4:
			s.clearLStack();
			break;
			/*case 5:
				s.destroyLStack();
				break;*/
		case 5:
			CalculateForUser();
			break;
		case 6:
			cout << "更换成功！" << endl;
			system("pause");
			system("cls");
			return;
		case 0:
			cout << "退出成功！" << endl;
			system("pause");
			exit(0);
		}
		system("pause");
		system("cls");
	}
}
