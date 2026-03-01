#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define N 10000
void swap(int* a1, int* a2)
{
	int tmp = *a1; *a1 = *a2; *a2 = tmp;
}
void QuickSort(int* a, int left,int right)
{
	if (left >= right)
		return;
	int begin = left; int end = right; int keyi = left;
	//左边找大，右边找小
	while (begin < end)
	{
		while (begin < end && a[begin] <= a[keyi])
		{
			begin++;
		}
		while (begin<end && a[end]>=a[keyi])
		{
			end--;
		}
		
		swap(&a[begin], &a[end]);
	}
	swap(&a[begin], &a[keyi]);
	keyi = begin;
	QuickSort(a, left, keyi-1);
	QuickSort(a, keyi+1, right);
}
void InsertSort(int num[], int count)
{
	int a = 0;
	for (int i = 0; i < count; i++)
	{
		int end = i;
		while (end >= 1)
		{
			if (num[end - 1] > num[end])
			{
				int tmp = num[end - 1];
				num[end - 1] = num[end];
				num[end] = tmp;
			}
			end--;
		}
	}
	/*for (int i = 0; i <count ; i++)
	{
		printf("%d ", num[i]);
	}*/
	
}
void SelectSort(int* a, int count)
{
	//找到最大值和最小值
	for (int i = 0; i < count; i++)
	{
		int max =i; int min =i;
		int begin = i; //int end = count;
		while (begin < count)
		{
			if (a[begin] > max)
			{
				max =i;
			}
			if (a[begin] < min)
				min =i;
			begin++;
		}
		swap(&a[max], &a[min]);
		count--;
	}
	/*for (int i = 0; i < count; i++)
	{
		printf("%d ", a[i]);
	}*/
}
void Creatnums()
{
	srand((unsigned int)time(NULL));
	FILE* pf = fopen("num", "w");
	if (pf == NULL)
	{
		perror("无法打开文件！");
		return ;
	}
	for (int i = 0; i < N; i++)
	{
		fprintf(pf, "%d\n", (unsigned int)rand()+i);
	}
	fclose(pf);
}
int main()
{
	Creatnums();
	int numbers[N];
	int count = 0;//数据个数
	FILE* file = fopen("num", "r");
	if (file == NULL)
	{
		perror("无法打开文件！");
	}
	while (fscanf(file, "%d", &numbers[count]) == 1)
	{
		count++;
		if (count > N)
		{
			printf("超过已有数据数量！");
			return 1;
		}
	}
	
	//插入排序
	int begin1 = clock();
	InsertSort(numbers, N);
	int end1 = clock();
	printf("InsertSort:%d\n", end1 - begin1);
	//选择排序
	int begin2 = clock();
	SelectSort(numbers,N);
	int end2 = clock();
	printf("SelectSort:%d\n", end2 - begin2);
	//快速排序
	int begin3 = clock();
	QuickSort(numbers,0,N-1);
	int end3 = clock();
	printf("QuickSort:%d\n", end3 - begin3);
	return 0;
}