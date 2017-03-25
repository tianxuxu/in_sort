#include "in_sort.h"
#include <stdlib.h>
#include <time.h>


int main()
{
	int arr[20];
	time_t  rawtime;//当前时间
	rawtime = time(NULL);//以时间作为随机数种子 
	srand(rawtime);
	for (int i = 0;i < 20;i++)
	{
		arr[i] = rand()%100+1;  //产生一定范围的随机数
	}
	//------------------------------------测试--------------------------------------------------
	
	//insert_sort(arr, sizeof(arr) / sizeof(arr[0]));//插入排序
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