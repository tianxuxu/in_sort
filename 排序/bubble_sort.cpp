#include "in_sort.h"

/**********************************************************************************************************
*                                                     ð������
*
*
*
***********************************************************************************************************
*/

//˼��ͨ��������������ˮ�е�����һ����С����ð��������ĺ�ð������
//�ص� �ȶ� ��ռ�ý϶�ռ�
//��δ�Ľ��µ��ڲ�������


/*1 û�иĽ��� ��ú������O��n^2����ǰ����һֱ����  ������ʯͷ���һֱ��
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



/*2������1 �Ӻ���ǰһֱ����������С������ǰ��
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


//*3 �ݹ���ʽ          //2222222222222222222222222
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
	}//Ҫ��֤low��С
	
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