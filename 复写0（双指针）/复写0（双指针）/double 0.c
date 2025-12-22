#include<stdio.h>
//问题描述
//给定一个数组，如果数组中有0，复写0，其他元素照抄在0后面，数组大小不变
// 方法1:额外开辟数组
int main()
{
	int arr[] = { 0,2,5,47,5,5,5,58,5,5,0,0,0,5,8,45,85,8 };
	int arr1[sizeof(arr) / sizeof(arr[1])] = {0};
	int i = 0;
	int slow = 0;
	while (i <sizeof(arr) / sizeof(arr[1]))
	{
		if (arr[slow] == 0)
		{
			arr1[i] = arr[slow];
				arr1[++i] = arr[slow];
			slow++;
			i++;
		}
		else
		{
			arr1[i] = arr[slow];
			i++;
			slow++;
		}
	}
	for (int i = 0; i < sizeof(arr) / sizeof(arr[1]); i++)
	{
		printf("%d ", arr1[i]);
	}printf("\n");
	//方法2：本地操作
	int arr2[] = { 0,2,5,47,5,5,5,58,5,5,0,0,0,5,8,45,85,8 };
	 slow = 0;
	int fast = 0;
	//从后往前操作
	//先找到最后一个要写的元素下标
	while (fast < sizeof(arr2) / sizeof(arr2[1]) - 1)
	{
		if (arr2[fast] == 0)
		{
			fast++;
		}
		else
		{
			fast++;

			slow++;
		}
	}
	while (slow >= 0)
	{
		if (arr2[slow] == 0)
		{
			arr2[fast] = 0;
			arr2[fast - 1] = 0;
			fast -= 2;
			slow--;
		}
		else
		{
			arr2[fast] = arr2[slow];
			fast--;
			slow--;
		}
	}
	for (int i = 0; i < sizeof(arr2) / sizeof(arr2[3]); i++)
	{
		printf("%d ", arr2[i]);
	}printf("\n");
	return 0;
}
//
//int main()
//{
//	//方法2：本地操作
//	int arr2[] = { 0,2,5,47,5,5,5,58,5,5,0,0,0,5,8,45,85,8 };
//	int slow = 0;
//	int fast = 0;
//	//从后往前操作
//	//先找到最后一个要写的元素下标
//	while (fast < sizeof(arr2) / sizeof(arr2[1])-1)
//	{
//		if (arr2[fast] == 0)
//		{
//			fast++;
//		}
//		else
//		{
//			fast++;
//	
//			slow++;
//		}
//	}
//	while (slow>=0)
//	{
//		if (arr2[slow] == 0)
//		{
//			arr2[fast] = 0;
//			arr2[fast - 1] = 0;
//			fast -= 2;
//			slow--;
//		}
//		else
//		{
//			arr2[fast] = arr2[slow];
//			fast--;
//			slow--;
//		}   
//	}
//	for (int i = 0; i < sizeof(arr2) / sizeof(arr2[3]); i++)
//	{
//		printf("%d ", arr2[i]);
//	}printf("\n");
//	return 0;
//}