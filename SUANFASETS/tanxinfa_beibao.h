#include<iostream>
#include<algorithm>
using namespace std;

struct tanxinbeibao
{
	int id;
	int weight;
	int value;
	double ratio;
};

bool Bagcmp(tanxinbeibao item1, tanxinbeibao item2){
	return item1.ratio > item2.ratio;
}
int tanxinn;
int tanxinc;

double KnapSack(tanxinbeibao y[], int n, int C,CString &strData){
	double x[10] = { 0 };
	int maxValue = 0;
	int i;
	for (i = 0; y[i].weight<C; i++)
	{
		x[i] = 1;
		maxValue += y[i].value;
		C = C - y[i].weight;
	}
	x[i] = 1.0*C / y[i].weight;;
	maxValue += x[i] * y[i].value;
	char string[20];
	for (i = 0; x[i] != 0; i++)
	{
		strData+="物品";
		sprintf(string, " %d:" , y[i].id+1);
		strData+=string;
		strData+="比重:";
		sprintf(string, " %2.1f\r\n" , x[i]);
		strData+=string;
	}
	return maxValue;
}
