
#include "in_sort.h"
/***************************************************************************************************************
*                                     选择排序
*   基本思想：每一趟在n-i+1个记录中选取关键字最小的记录作为有序序列中的第i个记录  时间复杂度o(n^2)
*   优化： 思路：减少计较次数入手（ 锦标赛排序）
*               树形选择排序：首先对n个记录进行两两比较然后再n/2个中较小者之间两两比较 如此找到最小的关键字记录
*               树形排序缺点：辅助空间较大 最大值进行多余比较
*   为了进一步优化树形选择排序，提出了另一种堆排序的算法           
******************************************************************************************************************
*/

/*
伪代码
SelectSort(SqList &L)//简单选择排序
{
	for(int i=1;i<L.length-1;i++)
	{
		j=SelectMinKey(L,i);//在L.r[i,L.length]中选择key最小的记录
		if(i!=j)
		{
			L.r[i]<-->L.r[j];//与第i个节点交换
		}
	}
}

*/
//*1 简单选择排序
void select_sort(int *arr, int len)
{
	for (int i = 0;i < len;i++)
	{
		int index = i;//先挑个最小的确定好
		for (int j = i;j < len;j++)//从n-1次关键字间选择关键字最小的记录，并和第i个记录交换
		{
			if (arr[j] < arr[index])
			{
				index = j;
			}
		}
		if (index != i)//找到了一个小的
		{
			int tmp = arr[index];
			arr[index] = arr[i];
			arr[i] = tmp;
		}
	}

}
/**/





//思想：输出堆顶的最小值后 剩余再次成堆 得到次小值依次反复执行 得到一个有序序列
//小根堆 ki<=k2i   ki<=k2i+1   k2i>k2i+1  //叶子到根结点的调整过程称为筛选
//大根堆  ki>k2i ki>k2i+1 k2i>k2i+1 
//只需要一个记录大小的辅助空间
