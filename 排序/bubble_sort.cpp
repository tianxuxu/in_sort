#include "in_sort.h"

/**********************************************************************************************************
*                                                     冒泡排序
*
*
*
***********************************************************************************************************
*/

//思想通过两两交换，像水中的泡泡一样，小的先冒出来，大的后冒出来。
//特点 稳定 不占用较多空间
//在未改进下低于插入排序


/*1 没有改进的 最好和最坏都是O（n^2）从前往后一直遍历  将最大的石头向后方一直放
bool bubble_sort(int *arr,int len)
{
	int i;
	int j;
	int tmp;
	for (i = 0; i < len; i++)
	{
		for (j = 0; j < len - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				tmp = arr[j + 1];
				arr[j + 1] = arr[j];
				arr[j] = tmp;
			}
		}
	}
	return true;
}
/**/



/*2类似于1 从后往前一直遍历，吧最小的泡向前放
bool bubble_sort(int *arr, int len)
{
	int i;
	int j;
	int tmp;
	for (i = 0; i < len; i++)
	{
		for (j = len-1; j > i; j--)
		{
			if (arr[j] < arr[j - 1])
			{
				tmp = arr[j - 1];
				arr[j - 1] = arr[j];
				arr[j] = tmp;
			}
		}
	}
	return true;
}
/**/


//*3 递归形式          //2222222222222222222222222
static  void  findmin(int *arr, int low, int high)
{
	int i = low+1;
	
	while (i<high-low-1)
	{
		if(arr[i]>arr[i+1])
		{
			int tmp = arr[i];
			arr[i] = arr[i + 1];
			arr[i + 1] = tmp;
		}
		
		i++;
	}//要保证low最小
	
}
static void recursive_bubble_sort(int *arr, int low, int high)
{
	if (low < high)
	{
		findmin(arr, low, high);
		recursive_bubble_sort(arr, low + 1, high);
		
	}
}
void bubble_sort(int *arr, int len)
{
	recursive_bubble_sort(arr, 0, len - 1);
}
/**/