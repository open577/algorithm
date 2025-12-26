#include<stdio.h>
//题目解析：输入一个数字，在数组中寻找和为该数字的两个元素。若没有，打印-1
int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	//方法一：暴力求解
	int input;
	printf("请输入:");
	scanf_s("%d", &input);
	for (int i = 0; i < sizeof(arr) / sizeof(arr[1]); i++)
	{
		
		for (int j = i + 1; j < sizeof(arr) / sizeof(arr[1]); j++)
		{
			if (arr[i] +arr[j] == input)
			{
				printf("和为%d两个数分别是%d %d\n",input, arr[i], arr[j]);
				break;
			}
		}
		
	}
	//方法二：双指针
	int a;
	printf("请输入：");
	scanf_s("%d", &a);
	int arr1[] = { 1,9,5,4,5,4,5,4,2,2,4,4 };
	//先排序(从小到大）
	for (int i = 0; i < sizeof(arr1) / sizeof(arr1[1]); i++)
	{
		for (int j = i + 1; j < sizeof(arr1) / sizeof(arr1[1]); j++)
		{
			if (arr1[j] < arr1[i])
			{
				int tmp = arr1[j];
				arr1[j] = arr1[i];
				arr1[i] = tmp;
			}
		}
	}
	/*for (int i = 0; i < sizeof(arr1) / sizeof(arr1[1]); i++)
		printf("%d ", arr1[i]);*/
	int left = 0, right = -1;
	//先找到right指向的数据（小于要判断的数字）
	for (int i = 0; i < sizeof(arr1) / sizeof(arr1[1]); i++)
	{
		if (arr1[i] <= a)
		{
			right++;
		}
	}
	while (left < right)
	{
		if (arr1[left] + arr1[right] > a)
		{
			right--;
		}
		else if (arr1[left] + arr1[right] < a)
		{
			left++;
		}
		else
		{
			printf("两个数分别是%d %d\n", arr1[left], arr1[right]);
			break;
		}
	}
	return 0;
}