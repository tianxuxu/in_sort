#include "in_sort.h"

/*************************************************************************************************************************
*                                                     ��������
* ˼�룺ͨ��һ�����򽫴������¼���ֳɶ����������� ����һ���־�С����һ����  �ֱ���������ּ����������� �Դﵽ������������
* ����������ȡһ���� ��ͨ����һ������֧��    ����С������һ��  ���ڵ�һ��
* ȱ�㣺������������ʽ����  
*		��Ҫһ��ջ�Ŀռ�ʵ�ֵݹ� 
* �Ż���ѡȡ֧��ʱ ����ȡ��  ���� ѡȡ�����е�����±�
*       ÿ�ηָ�� �ȶ�ջ�ĳ���С�Ľ��жԿ��������ܹ�����ջ��������
***************************************************************************************************************************
*/

void swap(int *a, int *b) 
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

//���� ��������ָ�� low high  �ؼ���priotkey 
//���ȴ�high����ǰ  �ҵ���һ��С��key�Ľ���  low�����  ���ڵĽ��� �ظ�������ֱ��low==high 
static int partition(int *arr, int low, int high)
{
	//������¼ʹ֧�㵽λ �����±�  ��߶�С��  �ұ߶�����
	int priotkey = arr[low];
	while (low < high)
	{
		while (low < high&&arr[high] > priotkey)
		{
			high--;
		}
		swap(&arr[high], &priotkey);//ȱ��û����һ�ζ�Ҫ3�θ�ֵ����
		while (low < high&&arr[low] < priotkey)
		{
			low++;
		}
		swap(&arr[low], &priotkey);
	}
	return low;//����֧������λ��
}

//�Ż���Ĳ���һֱ�ظ���ֵ ��arr[0]����֧��ֵ  ֻ��������һ�θ�ֵ
static int Partition(int *arr, int low, int high)//�Ƚ�֧���λ���ݴ���arr[0];
{
	//������¼ʹ֧�㵽λ �����±�  ��߶�С��  �ұ߶�����
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
	return low;//����֧������λ��
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