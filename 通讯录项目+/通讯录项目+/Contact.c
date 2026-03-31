#include"Contact.h"
//动态顺序表初始化
void BEG1(struct SeqList1* pf)
{
	pf->arr = NULL;
	pf->size = 0;
	pf->capacity = 0;
}
////展示联系人
//void PRINT(struct SeqList1* pf)
//{
//	for (int j = 0; j < pf->size; j++)
//	{
//		printf("%d ", pf->arr[j]);
//	}
//	printf("\n");
//	//printf("%d\n", pf->capacity);
//}
//添加联系人
void SLInsert(SL* pf)
{
	assert(pf);
	//判断空间是否足够并且申请空间
	if (pf->size == pf->capacity)
	{
		int newcapacity = pf->capacity == 0 ? 4 : 2 * pf->capacity;
		int* tmp = (int*)realloc(pf->arr, newcapacity * sizeof(ConNode));
		//判断内存是否申请成功
		if (tmp == NULL)
		{
			perror("realloc fail!");
			exit(1);
		}
		pf->arr = tmp;
		pf->capacity = newcapacity;
	}
	//添加联系人
	printf("请输入联系人姓名：");
	scanf("%s", pf->arr[pf->size].name);
	printf("请输入联系人年龄：");
	scanf("%d", &pf->arr[pf->size].age);
	printf("请输入联系人性别：");
	scanf("%s", pf->arr[pf->size].gender);
	printf("请输入联系人电话号码：");
	scanf("%s", pf->arr[pf->size].num);
	printf("请输入联系人住址：");
	scanf("%s", pf->arr[pf->size].addr);
	pf->size++;
}
////删除联系人
//void ERASE(struct SeqList1* pf, int a)
//{
//	//下标为a及其后面的元素向前移动一个位置
//	for (int i = 0; i < pf->size - a - 1; i++)
//	{
//
//		pf->arr[a + i] = pf->arr[a + i + 1];
//	}
//	pf->size--;
//}
////联系人查找实现
//int FIND(struct SeqList1* ps, int b)
//{
//	for (int i = 0; i < ps->size; i++)
//	{
//		if (ps->arr[i] == b)
//			return i;//找到时返回下标
//
//	}
//	return -1;//没有找到，返回负数
//}