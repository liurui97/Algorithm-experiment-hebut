#include<stdio.h>
#define MAXLENGTH 10
//定义背包容量
int c;
//定义物品数量
int wupinn;
//物品重量
int weight[MAXLENGTH];
//物品价值
int value[MAXLENGTH];
//当前重量
int currentWeight = 0;
//当前价值
int currentValue = 0;
//最优解
int bestAnswer[MAXLENGTH];
//最优价值
int bestPrice = 0;
//代表最终的最大价值
int bp = 0;
//最终的最大价值
int bA[MAXLENGTH];
int times = 0;
//计算可行路径个数
int number = 0;
//输出函数的原型声明
void Print();
//回溯法原型声明
void Backtracking(int i);


//定义输出函数
void Print(){
	printf("路径%d:\t", ++number);
	int i;
	for (i = 1; i < wupinn; i++)
	{
		printf("%d,", bestAnswer[i]);
	}
	printf("%d\t价值为：%d\n", bestAnswer[i], bestPrice);
}

//定义回溯函数
void Backtracking(int i){
	//递归一次节点数量加1
	times++;
	if (i>wupinn)
	{
		//Print();
		if (bestPrice > bp){
			bp = bestPrice;
			for (int j = 1; j <= wupinn; j++)
			{
				bA[j] = bestAnswer[j];
			}
		}
		return;
	}
	//当装入第i个物品还没有达到背包的最大质量时
	if (currentWeight+weight[i]<=c)
	{
		//装入第i个物品
		currentWeight += weight[i];
		//currentValue += value[i];
		//分支分为0和1
		bestAnswer[i] = 1;
		bestPrice += value[i];
		//搜索左子树
		Backtracking(i + 1);
		//为其他情况恢复数据
		currentWeight -= weight[i];
		bestPrice -= value[i];
	}
	//当前节点重新开始，搜索右子树
	bestAnswer[i] = 0;
	Backtracking(i + 1);
}