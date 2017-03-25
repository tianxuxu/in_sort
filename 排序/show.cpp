#include<iostream>
#include "in_sort.h"

using namespace std;

//打印给定数组中的元素
void show(int *arr, int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}