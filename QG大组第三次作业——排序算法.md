# QG大组第三次作业——排序算法

## 构造函数初始化

进行选择生成随机数还是用户输入数据，操作输入文件。

```c++
while (true)
	{
		cout << "请问用原文件还是创建新的文件或是搜索用户创建的文件：" << endl
			<< "1.用原文件\t2.创建新的文件\t3.用户创建的文件" << endl
			<< "creatselect = ";
		cin >> creatselect;
		if (creatselect == 1 || creatselect == 2)
			break;
		cout << "输入有误！请重新输入！" << endl;
	}
```

对文件内数据进行清空

```c++
ofstream ofs(FILENAME, ios::trunc);
			ofs.close();
```

## 插入排序

从头开始遍历，索引不断前进开阔有序序列

```c++
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
```

## 归并排序（合并数组）

通过递归将数组不断拆分到每个数组有一或两个元素，再合并数组，在过程中进行排序

```c++
void Sort::MergeSort(int begin, int end, int* temp)//归并排序
{
	if (begin + 1 < end) {     		  //保证只有一个值的时候退出，防止多余计算,
		int middle = (end + begin) / 2;   //这里可以想想int关于奇数和偶数的除法运算，但是仔细想想都不影响结果
		MergeSort(begin, middle, temp);
		MergeSort(middle, end, temp);
		MergeArray(begin, middle, end, temp);  //如何排序交给Merge函数即可
	}
}
```

## 快速排序

### 递归

将逐次数组分成两部分，然后不断进行排序

```c++
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
```

### 非递归

输入最大值与最小值，记录数组中每个元素的个数，然后创建一个数组，统计数组做变形，后面的元素等于前面元素的和，再将对应排到对的位置

```c++
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
```

## 基数计数排序

需要最大值的位数，每次遍历数组，记录每个数的一位数进行排序

```c++
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
```

## 小结

总是会报地址访问冲突，或者一些底层的我看不懂的错误，放弃了许多操作，往后继续进行学习