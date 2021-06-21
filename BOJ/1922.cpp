#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <utility>
using namespace std;
int n,m;
int arr[1001];
long long ans;
class Node{
public : 
	int s;
	int d;
	int value;
	Node(int  s, int d, int value) {
		this->s = s;
		this->d = d;
		this->value = value;
	}
};
vector<Node> v;

bool operator < (const Node & a, const Node & b) // sort 하려고 연산자 재정의
{
	return a.value < b.value;
}


int find(int a)
{
	if (arr[a] == a)
		return a;
	else
		return arr[a] = find(arr[a]);
}

bool union_set(int a, int b)
{
	int r1 = find(a);
	int r2 = find(b);
	if (r1 == r2) // 사이클 방지
		return false;
	arr[r2] = r1;
	return true;
}
int main()
{
	int a, b, c;
	scanf("%d", &n);
	for (int i = 0; i <= n; i++)
		arr[i] = i;
	scanf("%d", &m);
	for (int i = 0; i < m; i++)
	{
		scanf("%d %d %d", &a, &b, &c);
		v.push_back(Node(a,b,c));
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < m; i++)
	{
		//cout << v[i].s << " " << v[i].d << " " << v[i].value << endl;
		if(union_set(v[i].s, v[i].d))
			ans += v[i].value;
	}

	cout << ans << endl;
	return 0;
}