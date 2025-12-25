#include<stdio.h>
//问题介绍：给定一个数组，数组元素作为三角形边长。选出所有能组成的三角形的元素，打印出能够组成的个数
int main()
{
	int arr[] = { 2,2,3,4,4,5,5,7,8,8,8,9,10 };
	int leng = sizeof(arr) / sizeof(arr[1]);
	int sum = 0;
	//方法一：暴力求解
	for (int level1 = 0; level1 < leng - 2; level1++)
	{
		for (int level2 = level1 + 1; level2 < leng - 1; level2++)
		{
			for (int level3 = level2 + 1; level3 < leng; level3++)
			{
				if (arr[level1] + arr[level2] > arr[level3] && arr[level1] + arr[level3] > arr[level2] && arr[level2] + arr[level3] > arr[level1])
				{
					sum++;
				}
			}
		}
	}
	printf("%d\n", sum);
	//方法二：双指针算法。先将数组元素进行优化，使其有序，先固定最大的元素，载访问第二大的元素和最小的元素。判断是否符合构成三角形条件
	//有序化数组(从小到大）
	int time = 0;
	for (int i = 0; i < sizeof(arr) / sizeof(arr[1]); i++)
	{
		for (int j = i + 1; j < sizeof(arr) / sizeof(arr[1]); j++)
		{
			if (arr[j] < arr[i])
			{
				int tmp = arr[j];
				arr[j] = arr[i];
				arr[i] = tmp;
			}
		}
	}
	//定义指针
	for (int cur = sizeof(arr) / sizeof(arr[1])-1 ; cur >= 2; cur--)
	{
		int left = 0, right = cur - 1;
		while (left < right)
		{
			if (arr[left] + arr[right] <= arr[cur])
			{
				left++;
			}
			else
			{
				time += right - left;
				right--;
			}
		}
	}
	printf("%d\n", time);
	return 0;
}