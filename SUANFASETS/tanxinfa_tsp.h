#include<iostream>
#define MAXLENGTH 10
//回路长度
int TSPLength;
//无向带权图的代价矩阵
int value[5][5];

//定义一个结构体
struct bian
{
	int x;
	int y;
};
//定义城市集合
int V[MAXLENGTH];
//定义变得集合
bian P[MAXLENGTH];
//城市实际个数
int citys;
//定义修正函数
void Modify(int a[5][5]){
	int i;
	for (i = 0; i < citys; i++)
	{
		value[i][i] = 999;
	}
}
//顺序查找函数
int FindBySeq(int *ListSeq, int ListLength, int KeyData)
{
	int tmp = 0;
	int length = ListLength;
	for (int i = 0; i < ListLength; i++)
	{
		if (ListSeq[i] == KeyData)
			return i;
	}
	return -1;
}
