#include <iostream> 
#include <queue>
#include <utility>
#include <vector>
#include <math.h>
#include <algorithm>
#include <string.h>
using namespace std;
int n;
// 트라이 문제 
/*
반례 
1
1 A         -> 아무것도 출력 안됨
*/
struct node {
	// 노드를 해당 노드가 가진 문자열 순으로 소팅하기 위해 pair 사용함
	vector<pair <string, node *>> child;
	string str;
	node(string s) {
		this->str = s;
	}
};
// 문자열을 키로 사용 
void insert(node* n, string s)
{
	if (s == "" || s == " ")
		return;
	int pos = s.find(" ");
	string key = s.substr(0, pos);
	string next = s.substr(pos + 1, s.size());
	for (int i = 0; i < n->child.size(); i++)
	{
		if (n->child[i].second->str == key)
		{
			insert(n->child[i].second, next);
			return;
		}
	}
	node* newNode = new node(key);
	n->child.push_back(make_pair(key,newNode));
	sort(n->child.begin(), n->child.end());
	return;
}
// 루트 먼저 출력하고 자식으로 넘어감 
void print(node* n, string s)
{
	cout << s << n->str << "\n";
	string next = s + "--";
	for (int i = 0; i < n->child.size(); i++)
		print(n->child[i].second, next);
	return;
}
int main(void)
{
	cin >> n;
	int m;
	string s, input;
	node* root = new node("");
	for (int i = 0; i < n; i++)
	{
		cin >> m;
		s = "";
		for (int j = 0; j < m; j++)
		{
			cin >> input;
			s += input;
			s += " ";
			insert(root, s);
		}
	}
	for(int i=0; i<root->child.size(); i++)
		print(root->child[i].second, "");
	return 0;
}
