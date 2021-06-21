#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <utility>
#include <queue>
using namespace std;
int n, ans , q;
int root;
int dp[100001];
vector <vector <int>> tree;
int postOrder(int index , int parent)// 부모를 다시 호출하지 못하도록 부모가 누군지 알려줌
{
	if ((index != root) && (tree[index].size() == 1)) // 리프 노드일때
	{
		dp[index] = 1;
		return dp[index];
	}
	if (dp[index] != 0)
		return dp[index];
	// 중간에 부모를 호출해버려서 오류
	for (int i = 0; i < tree[index].size(); i++)
	{
		if(tree[index][i] != parent)
			dp[index] += postOrder(tree[index][i], index);
	}
	dp[index]++;
	//cout << "index : " << index << " " << dp[index] << endl;
	return dp[index];
}
int main(void) 
{
	ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
	cin >> n >> root >> q;
	int a, b , temp;
	for (int i = 0; i < 100001; i++)
		tree.push_back(vector<int>());
	for (int i = 0; i < n - 1; i++)
	{
		cin >> a >> b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	postOrder(root , 0);
	for (int i = 0; i < q; i++)
	{
		cin >> temp;
		cout << dp[temp] << "\n";
	}
	return 0;
}