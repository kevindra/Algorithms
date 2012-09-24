/**
*	Find if the given BST is correct.
*/

#include<iostream>

using namespace std;

struct node
{
	int val;
	node *left, *right;
};

node *createNewNode(int val)
{
	node *np = new node;
	np->val = val;
	np->left = np->right = NULL;
	return np;
}

void insert(node *&root, int val)
{
	if(root == NULL) { root = createNewNode(val); return; }

	if(val < root->val) insert(root->left, val);
	else insert(root->right, val);
}

bool isBST(node *root, int min, int max)
{
	if(root == NULL) return true;

	if(root->val < min || root ->val > max) return false;

	return isBST(root->left, min, root->val) && isBST(root->right, root->val, max);
}

void inorder(node *root)
{
	if(root == NULL) return;

	inorder(root->left);
	cout<<root->val<<", ";
	inorder(root->right);
}

int main()
{
	int a[] = {5,2,7,1,4,6,10,3,8,9};
	int n = 10;

	node *root = NULL;

	for(int i=0; i<n; i++) insert(root, a[i]);

	// tweak the tree
	root->left->val = 1;
	root->left->left->val = 2;

	cout<<"Inorder: "; inorder(root); cout<<endl;

	cout<< isBST(root, -INT_MAX, INT_MAX) << endl;

	system("pause");
}