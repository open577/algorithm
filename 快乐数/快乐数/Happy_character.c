#include<stdbool.h>
#include<stdio.h>
//问题介绍：给定一个数据，它的每一位数字平方和作为一个新的数据，再次进行平方和，如果最后的数据为1，就称这个数据为快乐数
int SUM(int in)
{
	 int sum1 = 0;
	while(in)
	{
		int a = in % 10;
		sum1 = a * a;
		in /= 10;
	}
	return sum1;
}
bool IsHappy(int n)
{
	int fast = n; int slow = SUM(n);
	while (fast != slow)
	{
		int slow = SUM(n);
		int fast = SUM(SUM(n));
	}
	return slow == fast;
}
int main()
{
	//方法1；暴力算法：每算一次进行判断，如果=1，结束进程
	int input;
	printf("请输入你要检查的数据：");
 	scanf_s("%d", &input);
	int times = 0;
	int sum = 0;
	
	while (input)
	{
		while (input)
		{
			int a = input % 10;
			sum += a * a;
			input /= 10;
		}
		if (sum == 1)
		{
			printf("是快乐数\n");
			break;
		}
		else
		{
			times++;
			if (times > 811)
			{
				printf("不是快乐数字\n");
				break;
			}
		}
		input = sum;
		sum = 0;
	}
	//方法2：双指针算法：
	//快指针走两步，慢指针走一步，如果指针指向的数据都是1，就结束进程
	int in=70;
	printf("请输入你要判断的数据：");
	scanf_s("%d", &in);

	bool result =IsHappy(in);
	if (result)
		printf("是快乐数\n");
	else
		printf("不是快乐数\n");
	return 0;
}