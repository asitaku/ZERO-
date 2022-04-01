#include "LinkStack.h"
//#include "LinkStack.cpp"

int main()
{
	while (true)
	{
		int typeselect;
		int firstselect;
		while (true)
		{
			show_Menu();
			cin >> firstselect;
			if (firstselect == 5)
				CalculateForUser();
			else if (firstselect >= 0 && firstselect <= 7)
			{
				system("pause");
				system("cls");
				break;
			}
			else
				cout << "输入有误！请重新输入！" << endl;
			system("pause");
			system("cls");
		}
		while (true)
		{
			cout << "现创建链栈以完成操作：" << endl;
			cout << "需要什么类型的链栈：" << endl
				<< "1.整数\t2.字符\t3.小数" << endl;
			cin >> typeselect;
			if (typeselect >= 1 && typeselect <= 3)
			{
				break;
			}
			cout << "输入有误！请重新输入。" << endl;
		}
		if (typeselect == 1)
		{
			LinkStack<int> a;
			FaceUser(a);
		}
		else if (typeselect == 2)
		{
			LinkStack<char> b;
			FaceUser(b);
		}
		else if (typeselect == 3)
		{
			LinkStack<float> c;
			FaceUser(c);
		}
	}

	system("pause");
	return 0;
}