#include <iostream>
using namespace std;
const int con = 1; //При увеличении максимального количества узлов + 1
class Node
{	
public:
Node *l, *r, *u;
int z;
void add(int x, Node *&Treee)
{
	if (NULL == Treee)// Создание узла
	{
		Treee = new Node;
		Treee->z = x;
		Treee->l = Treee->r = Treee->u = NULL;
	}

	if (x<Treee->z)// В левую сторону
	{
		if (Treee->l != NULL) add(x, Treee->l);
		else
		{
			Treee->l = new Node;
			Treee->l->l = Treee->l->r = Treee->l->u = NULL;
			Treee->l->z = x;
		}
	}

	if (x>Treee->z)// В правую сторону
	{
		if (Treee->r != NULL) add(x, Treee->r);
		else
		{
			Treee->r = new Node;
			Treee->r->l = Treee->r->r = Treee->r->u = NULL;
			Treee->r->z = x;
		}
	}

	if (x == Treee->z)// Вниз
	{
		if (Treee->u != NULL) add(x, Treee->u);
		else
		{
			Treee->u = new Node;
			Treee->u->l = Treee->u->r = Treee->u->u = NULL;
			Treee->u->z = x;
		}
	}
}
void Show(Node *tree, int &size)
{
	if (tree != NULL)
	{
		Show(tree->l, size);
		Show(tree->r, size);
		Show(tree->u, size);
		size += tree->z;
	}
}
};
int main()
{
	int size = 0;
	int x;
	Node *Treee = NULL;
	int w = 0;
	cout << "Kol-vo elementov v dereve = ";
	cin >> w;
	int z = 0;
	int y = 0;
	while (z<w)
	{
		cout << "x = ";
		cin >> x;
		if (z == 0)
		{
			y = x*con;//Для того чтобы корень не считался дважды
		}
		Treee->add(x, Treee);
		z++;
	}
	Treee->Show(Treee, size);
	size -= y;
	cout <<"Summa elementov "<< size << endl;
	delete Treee->r;
	delete Treee->l;
	delete Treee->u;
	delete Treee;
}