#include<stdio.h>
//问题介绍：给定一个数组，数组长度代表木桶长度，数组的每个元素代表每个木桶隔板的长度，选两个隔板作为木桶的边界。求木桶的盛水量
int main()
{
	//方法1;暴力枚举，算出所以情况，找出最大情况
	int arr[] = { 1,8,6,2,5,4,8,3,7 };
	int sum = 0; int max = 0;
	for (int i = 0; i < sizeof(arr) / sizeof(arr[1]); i++)
	{
		for (int j = i+1; j < sizeof(arr) / sizeof(arr[1]); j++)
		{
			if (arr[i] > arr[j])
			{
				sum = (j-i-1) * arr[j];
			}
			else
			{
				sum = (j - i-1) * arr[j];
			}
			if (sum > max)
			{
				max = sum;
			}
		}
	}
	printf("%d\n", max);
	//方法2；双指针，分别指向首末元素，往中间走，得到最终答案
	int left = 0;
	int right = sizeof(arr) / sizeof(arr[1]) - 1;
	int MAX = 0;
	while (left<right)
	{
		int v = (right-left) * (arr[left] <arr [right] ? arr[left] :arr [right]);
		if (arr[left] < arr[right])
		{
			left++;
		}
		else
			right--;
		if (v > MAX)
		{
			MAX = v;
		}
	}
	printf("%d\n", MAX);
	return 0;
}