#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <string>
#include <algorithm>

// 나중에 다른 방법으로 다시 풀어보기 -> 배열로 푸는 방법 있음 
struct node
{
	int value;
	struct node * left = NULL;
	struct node * right = NULL;
	void setLeft(node * newLeft) 
	{ 
		left = newLeft;
	}
	void setRight(node * newRight)
	{
		right = newRight;
	}
};
struct node* tree;
using namespace std;

void postOrder(struct node* node)
{
	if (node != NULL)
	{
		postOrder(node->left);
		postOrder(node->right);
		cout << node->value << "\n";
	}
	return;
}
node * insert(struct node * root , struct node * node)
{
	if (root == NULL)
		return node;
	if (root->value > node->value)
	{
		root->setLeft(insert(root->left, node));
	}
	else 
	{
		root->setRight(insert(root->right, node));
	}
	return root;
}
int main()
{
	int n;
	
	while (scanf("%d", &n) != EOF)
	{
		node *newNode = new node;
		newNode->value = n;
		newNode->left = newNode->right = NULL;
		tree = insert(tree, newNode);
	}
	
	
	postOrder(tree);
	return 0;
}
