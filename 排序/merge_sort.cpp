#include "in_sort.h"

/*******************************************************************************************
*                     �ϲ�����
*
*  ˼�룺���������������ϵ��������ϳ�һ���µ������
*  ���Ĳ�������һά����ǰ�����ڵ����������кϲ�Ϊһ��������
*  ��Ҫ�����ռ��ԭ�������д�С��ͬ�ĸ����ռ�   ʱ�临�Ӷ�log 2 n  �ȶ�������
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
	int i = left;                                                     //i ��¼��߽�
	int  j = n + 1;                                                 //j��¼N+1
	int k = left;                                                    //k��¼��߽�
	while ((i <= n) && (j <= right))               //i=left_n    j=n+1_right
	{
		if (arr[i] <= arr[j])                                                     //�������arr ��ǰһ���ֵ�һ��ֵ С�ں�һ����
		{
			brr[k++] = arr[i++];                                          //��brr��¼�����ֵ��I++,k++;
		}
		else
		{
			brr[k++] = arr[j++];
		}
	}
	if (i > n)    //���ǰһ����ȫ��С�ں�һ���� ��ǰһ����ǰ�����Ƹ�BRR
	{
		for (int q = j;q <= right;q++)
		{
			brr[k++] = arr[q];
		}
	}
	else
	{
		for (int q = i;q <= n;q++)                  //����ȫ���Ѻ�һ����ȫ�����Ƹ�BRR
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
	int brr[20] = {0};//�����ռ�
	mergesort(arr, brr, 0, len - 1);
}

