#include "in_sort.h"
/*****************************************************************************************************
*                                          堆排序
*  问题：如何由一个无序列建一个堆
*		取出堆顶后如何调整
*
*
*******************************************************************************************************
*/
void heap_adjust(int *arr, int s, int m)//一直H[s,m]除了H[S]之外其他均满足堆的定义
{
	int rc = arr[s];
	for (int j = 2 * s; j <=m;j *= 2)
	{
		if (j<m&&arr[j]>arr[j + 1])
		{
			j++;
		}
		if (rc == arr[j])
		{
			break;
		}
		arr[s] = arr[j];
		s = j;
	}
	arr[s] = rc;
}
void headpajust(int *arr, int s, int m)
{
	int top = arr[s];
	for (int i = 2 * s;i <= m;i *= 2)
	{
		if (i < m&&arr[i]<arr[i + 1])//i为比较大的元素
		{
			i++;
		}//arr[i]>arr[j+1]
		if (arr[i] < top)
		{
			break;
		}
		int tmp = arr[s];
		arr[s] = arr[i];
		arr[i] = tmp;
	}
	arr[s] = top;
}
void bucket_sort(int *arr, int len)
{
	for (int i = len/2+1;i >=0;--i)
	{
		heap_adjust(arr, i, len-1);
	}
	for (int i = len-1;i > 0;--i)
	{
		int tmp = arr[0];//把堆顶记录和当前未经排序的最后一个交换
		arr[0] = arr[i];
		arr[i] = tmp;
		heap_adjust(arr, 0, i - 1);
	}
}