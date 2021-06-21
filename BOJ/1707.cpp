#include <iostream> 
#include <queue>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;
int v, e;
bool visit[20001];
int color[20001];
vector <int> arr[20001];
vector <int> red, black;
void bfs(int n)
{
	queue<pair <int, int>> q;
	int x, c ,next;
	q.push(make_pair(n, 1)); // red부터 시작 
	while (!q.empty())    // bfs로 돌면서 그래프 이분 (레드 블랙 트리처럼)
	{
		x = q.front().first;
		c = q.front().second;
		visit[x] = true;
		color[x] = c;
		q.pop();
 		if (c == 1)
			red.push_back(x);
		else
			black.push_back(x);
		for (int i = 0; i < arr[x].size(); i++)
		{
			next = arr[x][i];
			if (!visit[next])
				q.push(make_pair(next, 3 - c));
		}
	}
	return;
}
int check()
{
	int idx, target;
	/*
	cout << endl << "red : ";
	for (int i = 0; i < red.size(); i++)
		cout << red[i] << " ";
	cout << endl << "black : ";
	for (int i = 0; i < black.size(); i++)
		cout << black[i] << " ";
	cout << endl;
	*/
	for (int i = 0; i < red.size(); i++)
	{
		idx = red[i];
		for (int j = 0; j < arr[idx].size(); j++)
		{
			if (color[arr[idx][j]] == color[idx])
				return 1;
		}
	}
	for (int i = 0; i < black.size(); i++)
	{
		idx = black[i];
		for (int j = 0; j < arr[idx].size(); j++)
		{
			if (color[arr[idx][j]] == color[idx])
				return 1;
		}
	}
	return 0;
}
int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t, a, b, result = 0;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		for (int k = 0; k <= 20000; k++)
		{
			visit[k] = false;
			color[k] = 0;
		}
		cin >> v >> e;
		for (int j = 0; j < e; j++)
		{
			cin >> a >> b;
			arr[a].push_back(b);
			arr[b].push_back(a);
		}
		for (int j = 1; j <= v; j++)
		{
			if(visit[j] == false)
				bfs(j);
		}
		if (check() == 0)
			cout << "YES\n";
		else
			cout << "NO\n";
		for (int j = 0; j <= v; j++)
			arr[j].clear();
		for (int j = 0; j < red.size(); j++)
			red.pop_back();
		for (int j = 0; j < black.size(); j++)
			black.pop_back();
	}
	return 0;
}
