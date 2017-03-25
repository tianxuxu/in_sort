#include "in_sort.h"

/*******************************************************************************************
*                     合并排序
*
*  思想：将两个或两个以上的有序表组合成一个新的有序表
*  核心操作：将一维数组前后相邻的两个有序列合并为一个有序列
*  需要辅助空间和原无序序列大小相同的辅助空间   时间复杂度log 2 n  稳定的排序
*
********************************************************************************************
*/
 



static void copy(int *arr, int *brr, int left, int right)
{
	for (int i = left;i <= right;i++)
	{
		arr[i] = brr[i];
	}
}
static void merge(int *arr, int *brr, int left, int n, int right)
{
	int i = left;                                                     //i 记录左边界
	int  j = n + 1;                                                 //j记录N+1
	int k = left;                                                    //k记录左边界
	while ((i <= n) && (j <= right))               //i=left_n    j=n+1_right
	{
		if (arr[i] <= arr[j])                                                     //如果数组arr 的前一部分的一个值 小于后一部分
		{
			brr[k++] = arr[i++];                                          //用brr记录这个数值，I++,k++;
		}
		else
		{
			brr[k++] = arr[j++];
		}
	}
	if (i > n)    //如果前一部分全部小于后一部分 把前一部分前部复制给BRR
	{
		for (int q = j;q <= right;q++)
		{
			brr[k++] = arr[q];
		}
	}
	else
	{
		for (int q = i;q <= n;q++)                  //否则全部把后一部分全部复制给BRR
		{
			brr[k++] = arr[q];
		}
	}

}

static void mergesort(int *arr, int *brr, int left, int right)
{
	if (left < right)
	{
		int i = (left + right) / 2;

		mergesort(arr, brr, left, i);
		mergesort(arr, brr, i + 1, right);

		merge(arr, brr, left, i, right);
		copy(arr, brr, left, right);
	}
}


void merge_sort(int *arr, int len)
{
	int brr[20] = {0};//辅助空间
	mergesort(arr, brr, 0, len - 1);
}

