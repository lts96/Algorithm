#include <iostream>
#include <stdlib.h>
#include <queue>
#include <vector>
#include <utility>
#pragma warning (disable:4996)
using namespace std;
int n, m, v;
int arr[1001][1001];
bool *visit;
queue < int > q;


// bfs에서 계속 queue가 터지는게 문제였음 
// 옛날 코드대로 하면 간선의 개수만큼 큐에 집어넣으므로 큐가 터짐 
// 그래서 큐에 push 하자마자 visit를 true로 바꿔서 해결 

void dfs(int pos)
{
	cout << pos << " ";
	visit[pos] = true;
	for (int i = 0; i <= n; i++)
	{
		if (arr[pos][i] != 0 && visit[i]==false)
		{
			dfs(i); 
		}
	}
}
void bfs()
{
	int x;
	while (!q.empty())
	{
		x = q.front();
		cout << x << " ";
		for (int i = 0; i <= n; i++)
		{
			if (arr[x][i] != 0 && visit[i] == false)
			{
				q.push(i);
				visit[i] = true;
			}
		}
		q.pop();
	}
}


int main(void)
{
	int x, y;
	cin >> n >> m >> v;
	visit = new bool[n + 1];
	for (int i = 0; i <= n; i++)
	{
		visit[i] = false;
	}

	for (int i = 0; i < m; i++)
	{
		cin >> x >> y;
		arr[x][y] = 1;
		arr[y][x] = 1;
	}
	dfs(v);
	cout << endl;
	for (int i = 0; i <= n; i++)
		visit[i] = false;
	q.push(v);
	visit[v] = true;
	bfs();
	
	//system("pause");
	return 0;
}