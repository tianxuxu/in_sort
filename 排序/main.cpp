#include "in_sort.h"
#include <stdlib.h>
#include <time.h>


int main()
{
	int arr[20];
	time_t  rawtime;//��ǰʱ��
	rawtime = time(NULL);//��ʱ����Ϊ��������� 
	srand(rawtime);
	for (int i = 0;i < 20;i++)
	{
		arr[i] = rand()%100+1;  //����һ����Χ�������
	}
	//------------------------------------����--------------------------------------------------
	
	//insert_sort(arr, sizeof(arr) / sizeof(arr[0]));//��������
	//bubble_sort(arr, sizeof(arr) / sizeof(arr[0]));
	//select_sort(arr, sizeof(arr) / sizeof(arr[0]));
	//shell_sort(arr, sizeof(arr) / sizeof(arr[0]));
	bucket_sort(arr, sizeof(arr) / sizeof(arr[0]));
	//merge_sort(arr, sizeof(arr) / sizeof(arr[0]));
	//quick_sort(arr, sizeof(arr) / sizeof(arr[0]));



	//------------------------------------------------------------------------------------------
	show(arr,sizeof(arr)/sizeof(arr[0]));
	return 0;
}