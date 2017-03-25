#include "in_sort.h"

/*************************************************************************************************************************
*                                                     快速排序
* 思想：通过一趟排序将待排序记录划分成独立的两部分 其中一部分均小于另一部分  分别对这两部分继续进行排序 以达到整个序列有序
* 操作：首先取一个点 （通常第一个）做支点    按照小于他的一边  大于的一边
* 缺点：对于有序序列式最慢  
*		需要一个栈的空间实现递归 
* 优化：选取支点时 三者取中  或者 选取序列中的随机下标
*       每次分割后 先对栈的长度小的进行对快速排序能够降低栈的最大深度
***************************************************************************************************************************
*/

void swap(int *a, int *b) 
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

//做法 附设两个指针 low high  关键字priotkey 
//首先从high找向前  找到第一个小于key的交换  low向后走  大于的交换 重复这两步直到low==high 
static int partition(int *arr, int low, int high)
{
	//交换记录使支点到位 返回下标  左边都小于  右边都大于
	int priotkey = arr[low];
	while (low < high)
	{
		while (low < high&&arr[high] > priotkey)
		{
			high--;
		}
		swap(&arr[high], &priotkey);//缺点没交换一次都要3次赋值操作
		while (low < high&&arr[low] < priotkey)
		{
			low++;
		}
		swap(&arr[low], &priotkey);
	}
	return low;//返回支点所在位置
}

//优化后的不用一直重复赋值 借arr[0]保存支点值  只进行最后的一次赋值
static int Partition(int *arr, int low, int high)//先将支点的位置暂存在arr[0];
{
	//交换记录使支点到位 返回下标  左边都小于  右边都大于
	arr[0] = arr[low];
	int priotkey = arr[low];

	while (low < high)
	{
		while (low < high&&arr[high] > priotkey)
		{
			high--;
		}
		arr[low] = arr[high];
		while (low < high&&arr[low] < priotkey)
		{
			low++;
		}
		arr[high] = arr[low];
	}
	arr[low] = arr[0];
	return low;//返回支点所在位置
}

void q_sort(int *arr, int low, int high)
{
	if (low < high)
	{
		int priotloc = partition(arr, low, high);
		q_sort(arr, low, priotloc - 1);
		q_sort(arr, priotloc + 1, high);
	}
}

void quick_sort(int *arr, int len)
{
	q_sort(arr, 0, len - 1);
}