/**
*	Print elements of a n-ary tree(a tree which may have more than two elements) breadth first reverse starting with the last level
* nodes and up. 
*/
#include <iostream>
#include <list>

using namespace std;

struct node
{
	int val;
	int count;
	node **children;
};

node *createNewNode(int val)
{
	node *np = new node;
	np->val = val;
	np->children = NULL;
	return np;
}

void printBsf(node *root)
{
	list<node*> q;
	q.push_back(root);

	cout<<"Normal BSF: ";
	while(q.size() != 0)
	{
		node *n = q.front();
		cout<<n->val<<" ";
		q.pop_front();

		for(int i=0; i<n->count; i++)
		{
			q.push_back(n->children[i]);
		}
		delete n;
	}
}

void printReverseBsf(node *root)
{
	list<node*> q;
	q.push_back(root);

	while(q.size() != 0)
	{
		node *n = q.front();

		for(int i=0; i<n->count; i++)
		{
			q.push_back(n->children[i]);
		}
	}

	cout<<"Reverse: ";
	for(int i =0; i<q.size(); i++)
	{
		node *n = q.back();
		cout<<n<<" ";
		q.pop_back();
	}
}

int main()
{
	node *root = createNewNode(34);

	root->children = new node*[3];
	root->children[0] = createNewNode(3);
	root->children[1] = createNewNode(56);
	root->children[2] = createNewNode(12);
	root->count = 3;

	root->children[0]->children = new node*[2];
	root->children[0]->count = 2;
	root->children[0]->children[0] = createNewNode(89);
	root->children[0]->children[1] = createNewNode(7);

	root->children[2]->children = new node*[1];
	root->children[2]->count = 1;
	root->children[2]->children[0] = createNewNode(22);

	root->children[2]->children[0]->children = new node*[1];
	root->children[2]->children[0]->count = 1;
	root->children[2]->children[0]->children[0] = createNewNode(78);

	printBsf(root);
	printReverseBsf(root);

	system("pause");
	return 0;
}