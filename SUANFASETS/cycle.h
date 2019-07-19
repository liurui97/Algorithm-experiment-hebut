#include<stdio.h>
#include<math.h>
#include<time.h>
#include<windows.h>

int a[20][20];

void GameTable(int k){
	int n = 2;
	int t,temp,i,j;

	//先定义初始几个元素
	a[1][1] = 1;
	a[1][2] = 2;
	a[2][1] = 2;
	a[2][2] = 1;

	//start=clock();
	for (t = 1; t < k; t++){
		//代表每一单位的边长
		temp = n;
		//代表每一行的最大长度
		n = n * 2;

		//填左下角
		for(i = temp + 1; i <= n; i++)
		for (j = 1; j <= temp; j++)
			a[i][j] = a[i - temp][j] + temp;

		//填右上角
		for (i = 1; i <= temp; i++)
		for (j = temp + 1; j <= n; j++)
			a[i][j] = a[i + temp][j - temp];

		//填右下角
		for (i = temp + 1; i <= n; i++)
		for (j = temp + 1; j <= n; j++)
			a[i][j] = a[i - temp][j - temp];
	}
	//Sleep(1000);
	//finish=clock();

}

void GameTable2(int k,int m){
	int i, j;
	if (m==2)
	{
		a[k][1] = k;
		a[k+1][1] = k + 1;
	}
	else
	{
		GameTable2(k, m / 2);
		GameTable2(k + m / 2, m / 2);
	}
	for (i = k; i < k + m / 2; i++)
	{
		for (j = m / 2 + 1; j <= m; j++)
		{
			a[i][j] = a[i + m / 2][j - m / 2];
		}
	}
	for (i = k+m / 2; i < k + m; i++){
		for (j = m / 2 + 1; j <= m; j++){
			a[i][j] = a[i - m / 2][j - m / 2];
		}
	}
}
/*void main(){
	int k,i,j;
	printf("请输入K的数值:");
	scanf("%d", &k);
	printf("这是非递归算法:\n");
	GameTable(k);
	for (int i = 1; i <= pow(2.0, k); i++)
	{
		printf("第");
		printf("%d", i);
		printf("天");
	}
	printf("\n");
	for (i = 1; i <= pow(2.0, k); i++){
		for (j = 1; j <=pow(2.0,k); j++)
		{
			printf("%5d", a[i][j]);
		}
		printf("\n");
	}
	printf("这是递归算法:\n");
	GameTable2(1, (int)pow(2.0, k));
	for (int i = 1; i <= pow(2.0, k); i++)
	{
		printf("第");
		printf("%d", i);
		printf("天");
	}
	printf("\n");
	for (i = 1; i <= pow(2.0, k); i++){
		for (j = 1; j <= pow(2.0, k); j++)
		{
			printf("%5d", a[i][j]);
		}
		printf("\n");
	}
	getchar();
	getchar();
	getchar();
}*/