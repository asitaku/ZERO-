#include "sort.h"

extern int choice;
extern int show;

Sort::Sort()
{
	filename = FILENAME;
	array = NULL;
	this->n = 0;
	int dtype = 2;
	int creatselect = 1;
	string filename_exist;
	string filename_tocreat;
	if (show > 3)
	{
		while (true)
		{
			cout << "请问用原文件还是创建新的文件或是搜索用户创建的文件：" << endl
				<< "1.用原文件\t2.创建新的文件\t3.用户创建的文件" << endl
				<< "creatselect = ";
			cin >> creatselect;
			if (creatselect >= 1 && creatselect <= 3)
				break;
			cout << "输入有误！请重新输入！" << endl;
		}
		if (creatselect == 1 || creatselect == 3)
		{
			if (creatselect == 3)
			{
				cout << "请输入想要操作的文件名：" << endl
					<< "文件名（例：xxxx.txt）：";
				cin >> filename_exist;
				filename = filename_exist;
			}
			int clearselect = 0;
			ifstream ifs;
			char ch;
			ifs >> ch;
			if (creatselect == 1)
			{
				ifs.open(FILENAME, ios::in);
			}
			else if (creatselect == 3)
			{
				ifs.open(filename_exist, ios::in);
			}
			/*while (true)
			{*/
			if (ifs.eof())
			{
				cout << "文件为空，可直接输入。" << endl;
			}
			/*cout << "是否清除原文件中的数据：" << endl
				<< "1.清除\t2.保留" << endl
				<< "clearselect =";
			cin >> clearselect;
			if (clearselect == 1 || clearselect == 2)
				break;
			cout << "输入有误！请重新输入！" << endl;
		}*/
		/*if (clearselect == 1)
		{*/
			if (creatselect == 1)
			{
				ofstream ofs(FILENAME, ios::trunc);
				ofs.close();
			}
			else if (creatselect == 3)
			{
				ofstream ofs(filename_exist, ios::trunc);
				ofs.close();
			}
			//}
			/*else if (clearselect == 2)
			{
				int num, i = 0;
				while (ifs >> num)
				{
					array = new int(num);
					this->n++;
				}
			}
			ifs.close();*/
		}

		if (creatselect == 2)
		{
			while (true)
			{
				cout << "请输入想要创建的文件名：" << endl
					<< "文件名（例：xxxx.txt）：";
				cin >> filename_tocreat;
				this->filename = filename_tocreat;
				string str = " ";
				/*str = str.substr(str.length() - 4, str.length());
				if (str != ".txt")
				{
					cout << "文件末尾不以.txt结尾，请重新输入！" << endl;
					continue;
				}输入检测但报错*/
				ifstream ifs;
				ifs.open(filename_tocreat, ios::in);
				if (!ifs.is_open())
					break;
				cout << "该文件已存在！" << endl;
			}
		}
		while (true)
		{
			cout << "请问需要产生随机数测试还是用户输入进行排序：" << endl
				<< "1.用户输入\t2.产生随机数" << endl
				<< "dtype = ";
			cin >> dtype;
			if (dtype == 1 || dtype == 2)
				break;
			cout << "输入有误！请重新输入！" << endl;
		}
	}
	if (dtype == 2)
	{
		if (creatselect == 1)
		{
			creatRandomSort(FILENAME);
		}
		else if (creatselect == 2)
		{
			creatRandomSort(filename_tocreat);
		}
		else if (creatselect == 3)
		{
			creatRandomSort(filename_exist);
		}
	}
	else if (dtype == 1)
	{
		int count;
		cout << "请问需要输入多少整数：" << endl;
		cin >> count;
		cout << "请输入数据：" << endl;
		int num;
		array = new int[count];
		for (int i = n; i < n + count; i++)
		{
			cin >> num;
			array[i] = num;
			n++;
		}
	}
}

void Sort::creatRandomSort(string filename)
{
	if (show > 3)
	{
		cout << "请问要产生多少随机数：" << endl
			<< "count = ";
	}
	int count;
	if (show <= 3)
	{
		switch (show)
		{
		case 1:
			count = 10000;
			break;
		case 2:
			count = 50000;
			break;
		case 3:
			count = 200000;
			break;
		}
	}
	if (show > 3)
	{
		cin >> count;
	}
	srand((unsigned)time(NULL));
	array = new int[count];
	int s = n;
	this->n = n + count;
	if (choice == 1)
	{
		for (int i = s; i < count + s; i++)
		{
			int p = rand()%3;
			array[i] = p;
		}
	}
	else
	{
		for (int i = s; i < count + s; i++)
		{
			int p = rand();
			array[i] = p;
		}
	}
}

void Sort::insertSort()//插入排序算法
{
	int unsortfront = 0;
	while (unsortfront < n)
	{
		for (int i = unsortfront; i >= 1; i--)
		{
			if (array[i] < array[i - 1])
			{
				int temp = array[i];
				array[i] = array[i - 1];
				array[i - 1] = temp;
			}
			else
				break;
		}
		unsortfront++;
	}
	this->save(FILENAME);
}

void Sort::MergeArray(int begin, int mid, int end, int* temp)//归并排序（合并数组）
{
	int n1 = mid - begin;
	int n2 = end - mid;

	//动态申请内存空间大小
	int* left = new int[n1];
	int* right = new int[n2];
	//left，right 在不断迭代过程中已经排好序了，在后面只需要比较
	//数组两边的数赋值到动态数组内           
	for (int i = 0; i < n1; i++)
		left[i] = temp[begin + i];    //从begin开始赋值
	for (int i = 0; i < n2; i++)
		right[i] = temp[mid + i];  //从mid开始赋值 

	//最初的数组赋值进行归并排序
	int i = 0, j = 0, key;
	for (key = begin; key < end; key++) 
	{
		if (i < n1 && left[i] <= right[j])
			temp[key] = left[i++];

		else if (j < n2 && left[i] >= right[j])
			temp[key] = right[j++];

		else if (i == n1 && j < n2)       //考虑一边赋完值另一边还有
			temp[key] = right[j++];

		else if (j == n2 && i < n1)	 
			temp[key] = left[i++];
	}
}

void Sort::MergeSort(int begin, int end, int* temp)//归并排序
{
	if (begin + 1 < end) {     		  //保证只有一个值的时候退出，防止多余计算,
		int middle = (end + begin) / 2;   //这里可以想想int关于奇数和偶数的除法运算，但是仔细想想都不影响结果
		MergeSort(begin, middle, temp);
		MergeSort(middle, end, temp);
		MergeArray(begin, middle, end, temp);  //如何排序交给Merge函数即可
	}
}

void Sort::QuickSort_Recursion(int begin, int end)//快速排序（递归版）
{
	if (begin < end)
	{
		// 获得枢轴
		int p = Partition(begin, end);
		//排列枢轴之前
		QuickSort_Recursion(begin, p - 1);
		//排列枢轴之后
		QuickSort_Recursion(p + 1, end);
	}
}

void Sort::QuickSort()//快速排序（非递归版）
{
	stack<int> st; // 用栈保存每一个待排序子串的首尾元素下标
	int mid = Partition(0, n-1);
	if (mid > 1) {
		st.push(0);
		st.push(mid - 1);
	}
	if (mid < n - 2) {
		st.push(mid + 1);
		st.push(n - 1);
	}

	while (!st.empty()) {
		int right = st.top();
		st.pop();
		int left = st.top();
		st.pop();
		mid = Partition(left, right);
		if (left < mid - 1) {
			st.push(left);
			st.push(mid - 1);
		}
		if (right > mid + 1) {
			st.push(mid + 1);
			st.push(right);
		}
	}
}

int Sort::Partition(int begin, int end)//快速排序（枢轴存放）
{
	//釆用要分区的子范围中的第一个元素作为基准元素
	int pivotValue = array[begin];
	int pivotPosition = begin;
	//重新排列分区子范围中除基准元素之外的从begin到end的元素
	for (int pos = begin + 1; pos <= end; pos++)
	{
		if (array[pos] < pivotValue)
		{
			//调整之后还是用一样的值去比较直到比他大的值出现
			swap(array[pivotPosition + 1], array[pos]);
			swap(array[pivotPosition], array[pivotPosition + 1]);
			pivotPosition++;
		}
	}
	return pivotPosition;
}

void Sort::CountSort(int size, int max, int min)//计数排序
{
	int len = max - min;//计算出数列最大最小值得差值
	int* countarr = new int[len + 1]();
	for (int i = 0; i < n; i++)
	{
		countarr[array[i] - min]++;//统计元素个数
	}

	int sum = 0;
	for (int i = 0; i < len + 1; i++)//统计数组做变形，后面的元素等于前面元素的和
	{
		sum += countarr[i];
		countarr[i] = sum;
	}
	int* sortarr = new int[n];
	for (int i = n - 1; i >= 0; i--)//倒序遍历原始数组，从统计数组中找到正确位置
	{
		sortarr[countarr[array[i] - min] - 1] = array[i];
		countarr[array[i] - min]--;
	}
	delete[] countarr;
	for (int i = 0; i < n; i++)
	{
		array[i] = sortarr[i];
	}
}

int Sort::Max()
{
	int max = array[0];
	for (int i = 0; i < n; i++)
	{
		if (array[i] > max)
		{
			max = array[i];
		}
	}
	return max;
}

int Sort::Min()
{
	int min = array[0];
	for (int i = 0; i < n; i++)
	{
		if (array[i] < min)
		{
			min = array[i];
		}
	}
	return min;
}

void Sort::RadixCountSort()//基数计数排序
{
	int p = GetMaxp();
	int* tmp = new int[n];
	int* count = new int[10]; //计数器
	int i, j, k;
	int radix = 1;
	for (i = 1; i <= p; i++) //进行p次排序
	{
		for (j = 0; j < 10; j++)
			count[j] = 0; //每次分配前清空计数器
		for (j = 0; j < n; j++)
		{
			k = (array[j] / radix) % 10; //统计每个桶中的记录数
			count[k]++;
		}
		for (j = 1; j < 10; j++)
			count[j] = count[j - 1] + count[j]; //将tmp中的位置依次分配给每个桶
		for (j = n - 1; j >= 0; j--) //将所有桶中记录依次收集到tmp中
		{
			k = (array[j] / radix) % 10;
			tmp[count[k] - 1] = array[j];
			count[k]--;
		}
		for (j = 0; j < n; j++) //将临时数组的内容复制到array中
			array[j] = tmp[j];
		radix = radix * 10;
	}
	delete[] tmp;
	delete[] count;
}

int Sort::GetMaxp()
{
	int max = Max(), p = 0;
	while (max)
	{
		max /= 10;
		p++;
	}
	return p;
}

void Sort::ColorSort()//颜色排序
{
	/*int* p0 = &array[0];
	int* p2 = &array[n - 1];
	int* p1 = &array[0];
	for (int i = 0; i < n; i++)
	{
		if (*p1 == 2 && (* p2 == 0))
			swap(*p1, *p2);
		while (!(*p1 == 0 | 2) && (p1 != p2))
			p1 = p1 + 1;
		while (!(*p2 == 0 | 2) && (p1 != p2))
			p2 = p2 - 1;
		if (*p1 == 0 && *p0 == 1)
			swap(*p0, *p1);
		p0 += 1;
	}*/
	int red = 0, blue = n - 1;
	for (int i = 0; i <= blue; ++i) 
	{
		if (array[i] == 0) {
			swap(array[i], array[red++]);
		}
		else if (array[i] == 2) {
			swap(array[i--], array[blue--]);
		}
	}
}

void Sort::save(string filename)
{
	ofstream ofs;
	ofs.open(filename, ios::out);
	for (int i = 0; i < (n); i++)
	{
		ofs << array[i] << endl;
	}
	ofs.close();
}

void Sort::FindNum()
{
	int BigOrSmall;
	while (true)
	{
		cout << "请问要从小到大找还是从小到大：" << endl
			<< "1.从小到大\t2.从大到小" << endl
			<< "BigOrSmall = ";
		cin >> BigOrSmall;
		if ((BigOrSmall == 1) || (BigOrSmall == 2))
			break;
		cout << "输入有误！请重新输入！" << endl;
	}
	int findselect;
	while (true)
	{
		cout << "请问要找到第几个数：" << endl
			<< "findselect = ";
		cin >> findselect;
		if (findselect > 0)
			break;
		cout << "输入有误！请重新输入！" << endl;
	}
	MergeSort(0, n, array);
	cout << array[findselect - 1] << endl;
}

void show_Menu()
{
	std::cout << "**************************************************************" << endl;
	std::cout << "**************欢迎来到QG第三次大组作业排序算法!****************" << endl;
	std::cout << "**********************请输入需要进行的操作：********************" << endl;
	std::cout << "********************1.插入排序*********************************" << endl;
	std::cout << "********************2.归并排序*********************************" << endl;
	std::cout << "********************3.快速排序（递归版）************************" << endl;
	std::cout << "********************4.快速排序（非递归版）***********************" << endl;
	std::cout << "********************5.计数排序*********************************" << endl;
	std::cout << "********************6.基数计数排序******************************" << endl;
	std::cout << "********************7.颜色排序*********************************" << endl;
	std::cout << "********************8.找到第K大/小的数*************************" << endl;
	std::cout << "********************9.退出程序*********************************" << endl;
	std::cout << "**************************************************************" << endl;
}