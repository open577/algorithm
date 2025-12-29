#include<stdio.h>
//给定一个顺序数组，求所有和为0的三个数，不能是同一个位置的数字，若出现相同的三元组，只写一次
int main()
{
	int arr[] = { 0,0,0 };
	//暴力枚举不可取，因为无法消除相同的三元组
	//利用双指针算法解决问题
	int cur = 0;
	while ((cur < sizeof(arr) / sizeof(arr[1]) - 2)&&arr[cur]<=0)
	{
		int left = cur + 1;
		int right = sizeof(arr)/sizeof(arr[1])-1;
		while (left < right)
		{
			if (arr[left] + arr[right] > -arr[cur])
			{
				right--;
			}
			if (arr[left] + arr[right] < -arr[cur])
			{
				left++;
			}
			if ((arr[left] + arr[right] == -arr[cur])&&left!=right)
			{
				printf("三个数为：%d %d %d\n", arr[cur], arr[left], arr[right]);
				left++, right--;
			}
		
			while (left < right && arr[left]==arr[left - 1])
			{
				left++;
			}
			while (left < right && arr[right]== arr[right-1])
			{
				right-=2;
			}
		}
		cur++;
		while ((cur < sizeof(arr) / sizeof(arr[1]) - 2) && arr[cur] == arr[cur - 1])
		{
			cur++;
		}
	}
	return 0;
}