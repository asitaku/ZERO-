#include "LQueue.h"

int main()
{
	LQueue q;
	while (true)
	{
		show_LQueue_Menu();
		int select;
		while (true)
		{
			cin >> select;
			if (select >= 0 && select <= 7)
				break;
			cout << "输入有误！请重新输入。" << endl;
		}
		switch (select)
		{
		case 1:
			q.AddNode();
			break;
		case 2:
			q.DeLQueue();
			break;
		case 3:
			q.ClearLQueue();
			break;
		case 4:
			q.TraverseLQueue();
			break;
		case 5:
			q.LPrint();
			break;
		case 6:
			q.LengthLQueue();
			break;
		case 7:
			if (q.IsEmptyLQueue())
			{
				cout << "该队列为空！" << endl;
				break;
			}
			q.NPrint(q.GetHeadLQueue());
			break;
		case 0:
			cout << "程序已退出！" << endl;
			system("pause");
			return 0;
		}
		system("pause");
		system("cls");
	}
}