#include<stdio.h>
//定义最大作业数量
#define MAXLENGTH 10
//定义机器的空闲时间
int d[MAXLENGTH];
//定义每台机器的处理时间
int S[MAXLENGTH][MAXLENGTH];
//定义一个结构体，记录作业处理时间
struct work{
	//作业时间
	int hour;
	//原顺序
	int number;
};
work t[MAXLENGTH];
//数组的排序算法
void bubble_sort(work a[], int n){
	int i, j;
	work temp;
	for (j = 0; j < n - 1; j++){
		for ( i = 0; i < n-1-j; i++)
		{
			if (a[i].hour<a[i+1].hour)
			{
				temp = a[i];
				a[i] = a[i + 1];
				a[i + 1] = temp;
			}
		}
	}
}
//多机调度算法
void MultiMachine(work t[], int n, int d[], int m){
	//队尾下标
	int rear[MAXLENGTH];
	int i, j, k;
	//安排前m个作业
	for ( i = 0; i < m; i++)
	{
		S[i][0] = t[i].number;
		rear[i] = 0;
		d[i] = t[i].hour;
	}
	//一次安排余下几个作业
	for ( i = m; i < n; i++)
	{
		//查找最先空闲的机器
		for (j = 0, k = 1; k < m; k++){
			if (d[k]<d[j])
			{
				j = k;
			}
		}
		rear[j]++;
		S[j][rear[j]] = t[i].number;
		d[j] += t[i].hour;
	}
}