#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <utility>
#include <math.h>
#define INF 2100000000
using namespace std;
/*
25퍼에서 시간초과 -> 33퍼에서 시간초과
지우는 함수에서 시간초과 난다
시간 초과 났던 이유 -> 문제를 자세히 보면 u에서 v로 가는 간선도 있고 v에서 u로 가는 간선도 있을 수 있다고 함
그래서 재귀돌때 무한 루프에 빠진 것
출력 잘못해서 몇번 틀림
괜히 벡터 쓰지말고 이차원 배열써서 바로바로 인덱스 접근해서 갱신하는게 더 빠르고 정확하다
푸는 방법은 처음 다익스트라 돌면서 최단거리 만들고 기존 간선을 전부 뒤집은 edge 배열을 역으로 탐색하면서
최단거리와 연결된 간선을 전부 찾아서 없앤다음 다시한번 다익스트라를 돌려서 찾으면 된다.
질문글 참고해서 겨우겨우 풀었던 문제
*/
int arr[501][501];
int edge[501][501];
// 나를 도착지로 하는 edge 저장
priority_queue<pair <int, int>> q;
int dist[501];
bool visit[501];
int ans;
int n, m, s, d, min_way;
void print()
{
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << arr[i][j] << " ";
		cout << endl;
	}
	return;
}
// edge의 w값을 변화시키는 방법은 결국 모든 edge값을 바꿔버리므로 불가능
// 최단 경로에 속하는 edge만 선별해야됨
int find(int s, int d)
{
	for (int i = 0; i < n; i++)
	{
		if (i != s)
			dist[i] = INF;
		else
		{
			dist[i] = 0;
			q.push(make_pair(0, s));
		}
	}
	while (!q.empty())
	{
		int d = q.top().first * -1;
		int index = q.top().second;
		q.pop();
		if (dist[index] < d)
			continue;
		for (int i = 0; i < n; i++)
		{
			if (arr[index][i] == 0)
				continue;
			int next = i;
			int weight = arr[index][i];
			if (dist[next] > dist[index] + weight)
			{
				dist[next] = dist[index] + weight;
				q.push(make_pair(dist[next] * -1, next));
			}
		}
	}
	return dist[d];
}
void erase(int idx)
{
	if (idx == s)
		return;
	if (visit[idx])
		return;
	visit[idx] = true;
	for (int j = 0; j < n; j++)
	{
		if (edge[idx][j] == 0)
			continue;
		int prev = j;
		int w = edge[idx][j];
		if (dist[idx] - dist[prev] == w)
		{
			// 원래 edge가 저장된 arr 값을 변경 
			arr[prev][idx] = 0;
			erase(prev);
		}
	}
	return;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	while (1)
	{
		cin >> n >> m;
		if (n == 0 && m == 0)
			break;
		cin >> s >> d;
		int u, v, p;
		for (int i = 0; i < m; i++)
		{
			cin >> u >> v >> p;
			arr[u][v] = p;
			edge[v][u] = p;
		}
		min_way = find(s, d);
		if (min_way == INF)   // 맨처음부터 최단 경로가 없다면 거의최단경로도 없음
		{
			cout << -1 << "\n";
			for (int i = 0; i <= 500; i++)
			{
				for (int j = 0; j <= 500; j++)
				{
					visit[i] = false;
					arr[i][j] = edge[i][j] = 0;
				}
			}
			continue;
		}
		erase(d);
		//print();
		ans = find(s, d);
		if (ans != INF)
			cout << ans << "\n";
		else
			cout << -1 << "\n";

		for (int i = 0; i <= 500; i++)
		{
			for (int j = 0; j <= 500; j++)
			{
				arr[i][j] = edge[i][j] = 0;
				visit[i] = false;
			}
		}
	}
    return 0;
}
