#include<stdio.h>
//问题描述：将数组中22的0元素移动到前面，其它元素顺序不变，放置数组后面
int main()
{
	int arr[] = { 0,1,6,9,0,0,5,6,0,4,6,0,5,6,9,5,74,5,4,5,5,5,4,0,0,0,5,9,6,0,560,0,0,0,0,7,5,7 };
	int dst = 0;//定义一个伪指针，指向数组0位置
	int cur = 0;//定义一个伪指针，指向0位置
	while (cur < (sizeof(arr) / sizeof(arr[1])))
	{
		if (arr[cur] == 0)
		{
			cur++;
		}
		//进行数据交换
		if (arr[cur] != 0)
		{
			int mid = arr[cur];
			arr[cur] = arr[dst];
			arr[dst] = mid;
			cur++;
			dst++;
		}

	}
	for (int i = 0; i < (sizeof(arr) / sizeof(arr[0])); i++)
		printf("%d ", arr[i]);
	return 0;
}
