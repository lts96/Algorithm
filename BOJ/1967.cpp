#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <utility>
#include <queue>
using namespace std;
int ans;
bool visit[10002];
queue <pair <short , short>> q;
vector<vector <pair<short , short>>> v;  // 인접 리스트 형태로 트리 구현
int n;
void bfs(int start)
{
	q.push(make_pair(start , 0));
	short index , next;
	int sum;
	while (!q.empty())
	{
		index = q.front().first;
		visit[index] = true;  
		sum = q.front().second;
		ans = max(ans, sum);
		//cout <<"start : " <<start <<" visit : " << index << " sum : "<< sum<< endl;
		for (int i = 0; i < v[index].size(); i++)
		{
			next = v[index][i].first;
			if (visit[next] == false) // 무한 루프 방지 
				q.push(make_pair(next, sum + v[index][i].second));
		}
		q.pop();
	}
	for (int i = 1; i <= n; i++)
		visit[i] = false;
    return;
}
int main(void)
{
	ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	short a, b, c;
	for (int i = 0; i <= n; i++)
		v.push_back(vector <pair <short, short>>());
	for (int i = 0; i < n-1; i++)
	{
		cin >> a >> b >> c;
		v[a].push_back(make_pair(b, c)); // 부모 -> 자식 루트 저장
		v[b].push_back(make_pair(a, c)); // 자식 -> 부모 루트 저장 
	}
	for (int i = 1; i <= n; i++)
		bfs(i);
	cout << ans << endl;
	return 0;
}