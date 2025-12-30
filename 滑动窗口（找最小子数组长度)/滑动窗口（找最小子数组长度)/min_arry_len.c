#include<stdio.h>
//问题介绍：给定一个正整形数组和一个目标值，求出数组中和大于等于目标值的最小子数组长度，若没有则返回0.
int main()
{
	int arr[] = {2,3,1,2,3,4,};
	int input;
	printf("请输入：");
	scanf_s("%d", &input);
	//利用同向双指针创造一个窗口，判断窗口中数组和是否大于等于目标值，若小于，左指针不变，右指针向前移。若大于等于，左指针向前移，右指针不变
	int left = 0; int right = 0; int sum = 0; int ret = _CRT_INT_MAX;
	while (right< sizeof(arr))
	{
		if (input <= 0)
		{
			printf("%d\n", 1);
			return;
		}
		sum += arr[right];
		while(sum>=input)
		{
			ret = ret >= (right - left + 1) ? (right - left + 1) : ret;
			sum -= arr[left++];
			
		}
		right++;
	}
	printf("%d\n", ret == _CRT_INT_MAX ? 0 : ret);
	return 0;
}