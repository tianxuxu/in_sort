
#include "in_sort.h"
/******************************************************************************************************
*                                                   ��������
*   ˼�룺��һ���¼�¼���뵽һ�����ź����������� �õ��µļ�¼����1�������
*	�ص㣺
*           �ȶ�������
*			��ռ�ö���ռ� 
*			������������������� o(n)
*			ʱ�临�Ӷ�O��n^2�� �ռ临�Ӷ�O��1��
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

		}//��Ѱ�Ҳ���λ��
		for (k=i-1;k>=j ; k--)
		{
			arr[k + 1] = arr[k];
		}//�Ѻ�벿�ֵ������ƶ�
		arr[j] = tmp;
		
	}
}
/**/


//�Ż��Ĳ�����������������¸��Ӷ�ΪO��n�� �ȽϺͽ���һ�����

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

//�ͷ���2һģһ��
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


/*4�ݹ���������
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


