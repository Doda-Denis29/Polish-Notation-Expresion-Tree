#include <iostream>
#include <stack>
#include <string>
#include <string.h>
#include <algorithm>
#include <fstream>
using namespace std;
ifstream f("artpro.txt");
class node {
public:
	char val;
	node* l, * r;
	node(int val)
	{
		this->val = val;
		this->l = this->r = nullptr;
	}
	node(int val, node* l, node* r)
	{
		this->val = val;
		this->l = l;
		this->r = r;
	}
};
bool op(char a)
{
	if (a == '+' || a == '-' || a == '/' || a == '^' || a == '*')
		return true;
	return false;
}
node* con(string &p, int &i)
{
	if (i == p.size())
		return nullptr;
	if (op(p[i]))
	{
		node* nodeprime = new node(p[i]);
		i++;
		nodeprime->l = con(p, i);
		nodeprime->r = con(p, i);
		return nodeprime;
	}
	else
	{
		node* nodeprimeN = new node(p[i]);
		i++;
		return nodeprimeN;
	}
}
int calc(node* p)
{
	int nr = 0;
	if (op(p->val))
	{
		nr = calc(p->l);
		int nr2 = calc(p->r);
		if (p->val == '+')
			nr += nr2;
		else if (p->val == '-')
			nr -= nr2;
		else if (p->val == '*')
			nr *= nr2;
		else if (p->val == '/')
			nr /= nr2;
		else if (p->val == '^')
			nr = pow(nr, nr2);
	} else
	{
		nr = p->val - '0';
	}
	return nr;
}
int main()
{
	string s;
	int i = 0;
	f >> s;
	node* b = con(s,i);
	cout << "The result is " << calc(b);
}