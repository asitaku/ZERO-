#include "twiceADT.h"

void dePoint()
{
	cout << "*********************************************************" << endl;
}

void show_Menu()
{
	cout << "**************************************************************" << endl;
	cout << "**************欢迎来到QG第一次大组作业双链表ADT!****************" << endl;
	cout << "**********************请输入需要进行的操作：********************" << endl;
	cout << "********************1.添加节点*********************************" << endl;
	cout << "********************2.查找节点*********************************" << endl;
	cout << "********************3.删除节点*********************************" << endl;
	cout << "********************4.反转链表*********************************" << endl;
	cout << "********************5.销毁链表*********************************" << endl;
	cout << "********************6.显示链表*********************************" << endl;
	cout << "********************0.退出程序*********************************" << endl;
	cout << "**************************************************************" << endl;
}

int main()
{
	cout << "以下为示例：" << endl;
	//通过构造函数初始化
	cout << "赋值初始化" << endl;
	ElemType num[] = { 1, 2, 3, 4, 5 };
	twiceList list1(num, 5);
	list1.print();
	cout << "拷贝初始化" << endl;
	twiceList list2(list1);
	list2.print();
	dePoint();

	//重载“+”
	cout << "重载+与=" << endl;
	twiceList list3 = list1 + list2;
	list3.print();
	dePoint();

	//查找(链表从零开始
	cout << "查找节点数据" << endl;
	cout << list3.search(3) << endl;
	dePoint();

	//删除
	cout << "删除节点" << endl;
	list3.detele_pos(3);//第四位
	list3.print();
	dePoint();

	//插入节点
	cout << "插入节点" << endl;
	list3.insert(4, 3);
	list3.print();
	dePoint();

	//反转链表
	cout << "反转链表" << endl;
	list3.reverse();
	list3.print();

	list1.clean();
	list2.clean();
	list3.clean();

	twiceList list4;
	while (1)
	{
		show_Menu();
		int select;
		cin >> select;
		switch (select)
		{
		case 1:
			list4.addPos();
			break;
		case 2:
			list4.serarchPos();
			break;
		case 3:
			list4.detelePos();
			break;
		case 4:
			list4.reverse();
			break;
		case 5:
			list4.clean();
			break;
		case 6:
			list4.print();
			break; 
		case 0:
			cout << "退出成功！" << endl;
			system("pause");
			exit(0);
		default:
			cout << "输入有误，请重新输入！" << endl;
		}
		system("pause");
		system("cls");
	}
	system("pause");
	return 0;
}