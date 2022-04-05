#pragma once
#include <iostream>
using namespace std;
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <stack>
#include <Windows.h>
#define FILENAME "empFlie.txt"


class Sort
{
public:
	Sort();
	void creatRandomSort(string filename);
	/**
	 *  @name        : void insertSort(int *a,int n);
	 *  @description : 插入排序算法
	 *  @param       : 数组指针 a, 数组长度 n
	 */
	void insertSort();


	/**
	 *  @name        : void MergeArray(int *a,int begin,int mid,int end,int *temp);
	 *  @description : 归并排序（合并数组）
	 *  @param       : 数组指针a，数组起点begin，数组中点mid，数组终点end，承载数组指针temp
	 */
	void MergeArray(int begin, int mid, int end, int* temp);

	/**
	 *  @name        : void MergeSort(int *a,int begin,int end,int *temp);
	 *  @description : 归并排序
	 *  @param       : 数组指针a，数组起点begin，数组终点end，承载数组指针temp
	 */
	void MergeSort(int begin, int end, int* temp);


	/**
	 *  @name        : void QuickSort(int *a, int begin, int end);
	 *  @description : 快速排序（递归版）
	 *  @param       : 数组指针a，数组起点begin，数组终点end
	 */
	void QuickSort_Recursion(int begin, int end);


	/**
	 *  @name        : void QuickSort(int *a,int size)
	 *  @description : 快速排序（非递归版）
	 *  @param       : 数组指针a，数组长度size
	 */
	void QuickSort();


	/**
	 *  @name        : void QuickSort(int *a, int begin, int end)
	 *  @description : 快速排序（枢轴存放）
	 *  @param       : 数组指针a，数组起点begin，数组终点end
	 */
	int Partition(int begin, int end);


	/**
	 *  @name        : void CountSort(int *a, int size , int max)
	 *  @description : 计数排序
	 *  @param       : 数组指针a，数组长度size，数组最大值max
	 */
	void CountSort(int size, int max, int min);
	int Max();//获得数组中的最大值
	int Min();//获得数组中的最小值


	/**
	 *  @name        : void RadixCountSort(int *a,int size)
	 *  @description : 基数计数排序
	 *  @param       : 数组指针a，数组长度size
	 */
	void RadixCountSort();
	int GetMaxp();//获得数组的最大位数


	/**
	 *  @name        : void ColorSort(int *a,int size)
	 *  @description : 颜色排序
	 *  @param       : 数组指针a（只含0，1，2元素），数组长度size
	 */
	void ColorSort();

	void save(string filename);


	/**
	 *  @name        : 自拟
	 *  @description : 在一个无序序列中找到第K大/小的数
	 *  @param       : 数组指针a，数组长度size
	 */
	void FindNum();

	int* array;//数组
	int n;//数组长度
	string filename;//文件名
};

void show_Menu();