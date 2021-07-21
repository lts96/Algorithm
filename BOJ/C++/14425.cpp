#include <iostream> 
#include <queue>
#include <utility>
#include <vector>
#include <math.h>
#include <algorithm>
#include <string.h>
using namespace std;
int n,m, ans;
int charToint(char c)
{
	return c - 'a';
}
struct node {
	node* child[26];
	bool finish;
	node() {
		for (int i = 0; i < 26; i++)
			child[i] = NULL;
		this->finish = false;
	}
};
// 문자열을 키로 사용 
/*
트라이로 구현했는데 계속 틀렸던 이유 
그냥 string으로 인자를 넘겨주면 string이 계속 통째로 복사가 되므로 
string 길이만큼 시간이 낭비됨 
따라서 주소를 넘겨줘서 사용하면 된다.
*/
void insert(node* n, const string &s, int idx)
{
	if (idx == s.size())
	{
		n->finish = true;
		return;
	}
	char c = s[idx];
	int target = charToint(c);
	if (n->child[target] == NULL)
	{
		node* newNode = new node();
		n->child[target] = newNode;
	}
	insert(n->child[target], s, idx + 1);
	return;
}
void find(node* n, const string& s, int idx)
{
	int size = s.size();
	if (n->finish && !(idx < size))
	{
		ans++;
		return;
	}
	if (idx >= size)
		return;
	char c = s[idx];
	int target = charToint(c);
	if(n->child[target] != NULL)
		find(n->child[target], s, idx + 1);
	return;
}
int main(void)
{
	cin >> n >> m;
	string s;
	node* root = new node();
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		insert(root, s, 0);
	}
	for (int i = 0; i < m; i++)
	{
		cin >> s;
		find(root, s, 0);
	}
	cout << ans << "\n";
	return 0;
}
