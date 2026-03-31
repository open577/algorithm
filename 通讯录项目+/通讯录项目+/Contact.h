#define NAME_MAX 20
#define NUM_MAX 20
#define GENDER_MAX 20
#define ADDR_MAX 20

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef struct ContactNode
{
	char name[NAME_MAX];//姓名
	int age;//年龄
	char gender[GENDER_MAX];//性别
	char num[NUM_MAX];//电话号码
	char addr[ADDR_MAX];//地址
}ConNode;
typedef int ContactDataType;
//动态顺序表
typedef struct SeqList1
{
	ConNode* arr;
	int size;
	int capacity;
}SL;
//动态顺序表初始化
void BEG1(struct SeqList1* pf);
////查看联系人
//void PRINT(struct SeqList1* pf);
////添加联系人
//void SLInsert(struct SeqList1* pf);
////联系人元素
//void ERASE(struct SeqList1* pf, int a);
////联系人查找实现
//int FIND(struct SeqList1* ps, int b);