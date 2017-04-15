#include <iostream>
using namespace std;
const int con = 1; //При увеличении максимального количества узлов + 1
struct Node
{
	Node *l, *r, *u;
	int z;
};
void add(int x, Node *&MyTree)
{
	if (NULL == MyTree)// Создание узла
	{
		MyTree = new Node;
		MyTree->z = x;
		MyTree->l = MyTree->r = MyTree->u = NULL;
	}

	if (x<MyTree->z)// В левую сторону
	{
		if (MyTree->l != NULL) add(x, MyTree->l);
		else
		{
			MyTree->l = new Node;
			MyTree->l->l = MyTree->l->r = MyTree->l->u = NULL;
			MyTree->l->z = x;
		}
	}

	if (x>MyTree->z)// В правую сторону
	{
		if (MyTree->r != NULL) add(x, MyTree->r);
		else
		{
			MyTree->r = new Node;
			MyTree->r->l = MyTree->r->r = MyTree->r->u = NULL;
			MyTree->r->z = x;
		}
	}

	if (x == MyTree->z)// Вниз
	{
		if (MyTree->u != NULL) add(x, MyTree->u);
		else
		{
			MyTree->u = new Node;
			MyTree->u->l = MyTree->u->r = MyTree->u->u = NULL;
			MyTree->u->z = x;
		}
	}
}
void Show(Node *tree, int &size)
{
	if (tree!= NULL)
	{	

		Show(tree->l, size);
		Show(tree->r, size);
		Show(tree->u, size);
		size += tree->z;

	}
}
int main()
{
	int size = 0;
	int x;
	Node *MyTree = NULL;
	int w = 0;
	cin >> w;
	int z = 0;
	int y = 0;
	while (z<w)
	{
		cout << "X = "; 
		cin >> x;
		if (z == 0)
		{
			y = x*con;//Для того чтобы корень не считался дважды
		}
		add(x, MyTree);
		z++;
	}
	Show(MyTree,size);
	size -= y;
	cout << size<<endl;
}