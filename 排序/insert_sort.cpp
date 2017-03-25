
#include "in_sort.h"
/******************************************************************************************************
*                                                   插入排序
*   思想：将一个新纪录插入到一个已排好序的有序表中 得到新的纪录数增1的有序表
*	特点：
*           稳定的排序
*			不占用额外空间 
*			在有序的情况下排序最快 o(n)
*			时间复杂度O（n^2） 空间复杂度O（1）
******************************************************************************************************
*/

/*1
void insert_sort(int *arr, int len)
{
	int tmp;
	int i;
	int j;
	int k;
	for (i = 1; i < len;i++)
	{
		tmp = arr[i];
		for (j = 0; j < i; j++)
		{
			if (arr[j] > tmp)
			{
				break;
			}

		}//先寻找插入位置
		for (k=i-1;k>=j ; k--)
		{
			arr[k + 1] = arr[k];
		}//把后半部分的数据移动
		arr[j] = tmp;
		
	}
}
/**/


//优化的插入排序在有序情况下复杂度为O（n） 比较和交换一步完成

/*2
void insert_sort(int *arr, int len)
{
	int tmp;
	int i;
	int j;
	int k;
	for (i = 1; i < len; i++)
	{
		tmp = arr[i];
		for (j = i-1; j >=0; j--)
		{
			if (arr[j] > tmp)
			{
				arr[j+1] = arr[j];
			}
			else
			{
				break;
			}
		}
		arr[j+1] = tmp;
	}
}/**/

//和方法2一模一样
//*3
void insert_sort(int *arr, int len)
{
	int i;
	int j;
	int tmp;
	for (i = 1; i < len; i++)
	{
		j = i - 1;
	    tmp = arr[i];
		while (j >= 0&&arr[j]>tmp)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = tmp;
	}
}
/**/


/*4递归版插入排序
static void insert_sort(int *arr, int low, int high)
{
	int tmp =arr[ high + 1];
	int j = high;
	while (j >= 0 && arr[j] > tmp)
	{
		arr[j + 1] = arr[j];
		j--;
	}
	arr[j + 1] = tmp;
}
static void recursive_insert_sort(int *arr, int low, int high)
{
	if (low < high)
	{
		recursive_insert_sort(arr, low, high-1);
		insert_sort(arr, low, high-1);
	}
}
void insert_sort(int *arr, int len)
{
	return recursive_insert_sort(arr, 0, len - 1);

}

/**/


