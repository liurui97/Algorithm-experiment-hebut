#include<iostream>
using namespace std;
/*回溯法求解TSP问题，采用排列树、深度优选搜索的方法
由于课本中没有给出算法，故在此给出算法设计
变量：
1.城市个数n
2.城市之间的距离value[][]
3.城市走过的路程cl
4.最短路径bestx[]
5.城市编号数组x[]
步骤：
*/
#define MAXLENGTH 10
//城市个数
int n;
//城市之间的距离
int value[MAXLENGTH][MAXLENGTH];
//城市编号
int citys[MAXLENGTH];
//最优路径
int bestx[MAXLENGTH];
int maybex[MAXLENGTH];
//经过的路径
int cl = 0;
//最优路径长度
int bestl = 999;
int maybel = 999;

//修正函数原型声明
void Modify();
//Tsp函数原型声明
void Tsp(int n);

//修正函数，将对角线数据置为0
void Modify(){
	for (int i = 1; i <= n; i++)
	{
		value[i][i] = -1;
	}
}

//交换函数
void swap(int &a, int &b){
	int temp;
	temp = a;
	a = b;
	b = temp;
}
//定义回溯法求TSP问题
void Tsp(int t){
	//用于计数
	int j;
	//到达叶子节点
	if (t>n)
	{
		if (value[citys[n]][1] != -1 && (cl + value[citys[n]][1])<bestl){
			//记录所经过的路径
			for (j = 1; j <= n; j++)
			{
				bestx[j] = citys[j];
			}
			bestl = cl + value[citys[n]][1];
		}
	}
	else{//还没有到达叶子节点
		//搜索扩展节点的左右分支，即所有与当前城市所在的邻近城市
		for ( j = t; j <= n ; j++)
		{
			//若果第t-1个城市与第t个城市之间有路径且可以得到更短的路线
			if (value[citys[t - 1]][citys[j]] != -1 && (cl + value[citys[t - 1]][citys[j]]) < bestl){
				//交换位置
				swap(citys[t], citys[j]);
				//为长度赋值
				cl += value[citys[t - 1]][citys[t]];
				//进行深度遍历
				Tsp(t + 1);
				//恢复原状
				cl -= value[citys[t - 1]][citys[t]];
				swap(citys[t], citys[j]);
			}
		}
	}
}