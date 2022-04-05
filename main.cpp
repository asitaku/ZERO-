#include "sort.h"

int choice;
int show;

int main()
{
	show = 1;
	while (true)
	{
		choice = 1;
		int select = 7;
		if (show > 3)
		{
			while (true)
			{
				show_Menu();
				cin >> select;
				if (select >= 1 && select <= 9)
					break;
				std::cout << "输入有误！请重新输入！" << endl;
			}
		}
		else if (show <= 3)
		{
			switch (show)
			{
			case 1:
				std::cout << "10000大数据用时：" << endl;
				break;
			case 2:
				std::cout << "50000大数据用时：" << endl;
				break;
			case 3:
				std::cout << "200000大数据用时：" << endl;
				break;
			}
		}
		do
		{
			if (select == 7)
			{
				Sort c;
				clock_t start = clock();
				c.ColorSort();
				std::cout << "颜色排序：" << clock() - start << endl;
				c.save(c.filename);
			}
			else if (select == 9)
			{
				std::cout << "退出成功！" << endl;
				std::system("pause");
				exit(0);
			}
			else
			{
				if (select == 0)
					break;
				choice = 2;
				Sort s;
				clock_t start = clock();
				switch (select)
				{
				case 1:
					s.insertSort();
					std::cout << "插入排序：" << clock() - start << endl;
					break;
				case 2:
					s.MergeSort(0, s.n, s.array);
					std::cout << "归并排序：" << clock() - start << endl;
					break;
				case 3:
					s.QuickSort_Recursion(0, s.n - 1);
					std::cout << "快速排序（递归版）：" << clock() - start << endl;
					break;
				case 4:
					s.QuickSort();
					std::cout << "快速排序（非递归版）：" << clock() - start << endl;
					break;
				case 5:
					s.CountSort(s.n, s.Max(), s.Min());
					std::cout << "计数排序：" << clock() - start << endl;
					break;
				case 6:
					s.RadixCountSort();
					std::cout << "基数计数排序：" << clock() - start << endl;
					break;
				case 8:
					s.FindNum();
					break;
				}
				s.save(s.filename);
			}
		} while (select-- && show <= 3);
		show++;
		std::cout << "排序成功！" << endl;
		std::system("pause");
		std::system("cls");
	}
	std::system("pause");
	return 0;
}