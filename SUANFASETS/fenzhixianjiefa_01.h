#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
//物品个数
int fenzhi01n;
//背包容量
int fenzhi01c;
int *fenzhi01x = new int[fenzhi01n];
//定义物品结构体
struct Item
{
	//物品编号
	int ItemID;
	//物品价值
	int value;
	//物品重量
	int weight;
	//质量/重量
	int ratio;
};

//定义搜索节点
struct Node
{
	Node(){
		value = 0;
		weight = 0;
		level = 0;
		parent = 0;
		bound = 0;
	}
	//搜索到该节点的价值
	int value;
	//搜索到该节点的总重量
	int weight;
	//搜索以该节点韦根的子树能达到的价值上界
	int bound;
	//层次
	int level;
	//父节点
	struct Node *parent;
};

//按照大顶堆的形式存放
struct cmp
{
	bool operator()(Node *a, Node *b){
		return a->bound < b->bound;
	}
};

//比较函数
bool Itemcmp(Item item1, Item item2);
//分支限界法
int branchAndBound(Item items[], int c);
int searchCount = 0;
int maxSize = 0;
//限界函数
float maxBound(Node *node, Item items[], int c);

/*int main(){
	int maxValue;
	cout << "请输入物品的个数:";
	cin >> n;
	cout << "请输入背包容量:";
	cin >> c;
	int *w = new int[n];
	int *v = new int[n];
	cout << "请输入" << n << "个物品的质量:" << endl;
	for (int i = 0; i < n; i++)
	{
		cin >> w[i];
	}
	cout << "请输入" << n << "个物品的价值:" << endl;
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}

	//定义物品结构体
	Item *items = new Item[n];
	//初始化结构体数组
	for (int i = 0; i < n; i++)
	{
		items[i].ItemID = i;
		items[i].value = v[i];
		items[i].weight = w[i];
		items[i].ratio = 1.0*v[i] / w[i];
	}
	//按价值率排序
	sort(items, items + n, Itemcmp);
	cout << "商品的价值依次为:";
	for (int i = 0; i < n; i++)
	{
		cout << v[i] << "  ";
	}
	cout << endl;
	cout << "商品的质量分别为:";
	for (int i = 0; i < n; i++)
	{
		cout << w[i] << " ";
	}
	cout << endl;
	cout << "选取方案为:" << endl;
	maxValue = branchAndBound(items, c);
	cout << "最大价值为:" << maxValue;
	getchar();
	getchar();
	getchar();
	delete []w;
	delete []v;
}*/

//比较函数
bool Itemcmp(Item item1, Item item2){
	return item1.ratio > item2.ratio;
}

//分支限界函数
int branchAndBound(Item items[], int c){
	int i;
	for (i = 0; i < fenzhi01n; i++)
	{
		fenzhi01x[i] = 0;
	}
	//保存最大价值
	int maxValue;
	//保存当前最大价值节点
	Node *maxNode = new Node();
	//最大价值优先队列
	priority_queue<Node *, vector<Node *>, cmp> maxQueue;
	Node *firstNode, *curNode;
	
	searchCount = 1;
	firstNode = new Node();
	firstNode->bound = maxBound(firstNode, items, c);
	firstNode->parent = NULL;
	maxQueue.push(firstNode);
	maxValue = 0;
	maxNode = firstNode;
	while (!maxQueue.empty()){
		curNode = maxQueue.top();
		maxQueue.pop();
		//扩展左孩子
		if (curNode->weight + items[curNode->level].weight <= c){
			Node *leftNode = new Node();
			leftNode->value = curNode->value + items[curNode->level].value;
			leftNode->weight = curNode->weight + items[curNode->level].weight;
			leftNode->level = curNode->level + 1;
			leftNode->parent = curNode;
			leftNode->bound = curNode->bound;
			if (leftNode->level<fenzhi01n)
			{
				maxQueue.push(leftNode);
				searchCount++;
			}
			if (maxValue<leftNode->value)
			{
				maxValue = leftNode->value;
				maxNode = leftNode;
			}
		}

		//扩展右孩子节点
		if (maxBound(curNode, items, c)>maxValue){
			Node *rightNode = new Node();
			rightNode->value = curNode->value;
			rightNode->weight = curNode->weight;
			rightNode->level = curNode->level + 1;
			rightNode->parent = curNode;
			rightNode->bound = maxBound(rightNode, items, c);
			if (rightNode->level<fenzhi01n)
			{
				maxQueue.push(rightNode);
				searchCount++;
			}
		}
		if (maxQueue.size()>maxSize)
		{
			maxSize = maxQueue.size();
		}
	}
	curNode = maxNode;
	while (curNode)
	{
		int tempValue = curNode->value;
		curNode = curNode->parent;
		if (curNode&&curNode->value != tempValue){
			fenzhi01x[items[curNode->level].ItemID] = 1;
		}
	}
	/*for (i = 0; i < fenzhi01n; i++)
	{
		cout << x[i] << "  ";
	}
	cout << endl;*/
	return maxValue;
}

//限界函数
float maxBound(Node *node, Item items[], int c){
	float maxValue;
	//背包剩余容量
	int restCapacity;
	int i;

	maxValue = node->value;
	restCapacity = c - node->weight;
	i = node->level;

	while (i<fenzhi01n&&restCapacity>items[i].weight)
	{
		maxValue += items[i].value;
		restCapacity -= items[i].weight;
		i++;
	}
	if (restCapacity!=0)
	{
		maxValue += restCapacity*items[i].ratio;
	}
	return maxValue;
}