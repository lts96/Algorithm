#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <string>
#include <algorithm>
int n;
struct node
{
	char name;
	struct node * left = NULL;
	struct node * right = NULL;
};
struct node* tree;
using namespace std;

void preorder(struct node* node)
{
	if (node != NULL)
	{
		cout << node->name;
		preorder(node->left);
		preorder(node->right);
		return;
	}
}
void inorder(struct node* node)
{
	if (node != NULL)
	{
		inorder(node->left);
		cout << node->name;
		inorder(node->right);
		return;
	}
}
void postorder(struct node* node)
{
	if (node != NULL)
	{
		postorder(node->left);
		postorder(node->right);
		cout << node->name;
		return;
	}
}
int main()
{
	cin >> n;
	tree = new node[n];
	char name ,left, right;
	for (int i = 0; i < n; i++)
	{
		cin >> name;
		tree[(int)(name - 65)].name = name;

		cin >> left;
		if (left != '.')
			tree[(int)(name - 65)].left = &tree[(int)(left- 65)];
		
		cin >> right;
		if (right != '.')
			tree[(int)(name - 65)].right = &tree[(int)(right - 65)];
		
		
	}
	
	
	preorder(&tree[0]);
	cout << "\n";
	inorder(&tree[0]);
	cout << "\n";
	postorder(&tree[0]);
	cout << "\n";
	return 0;
}