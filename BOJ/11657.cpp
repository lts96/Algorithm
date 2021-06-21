#include <iostream> 
#include <queue>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;
int v, e;
vector <pair <int , int>> arr[501];
long long dist[501];
#define INF 1e18
void bellman()
{
	int next,w;
	// 벨만은 다익스트라와 다르게 edge를 중심으로 본다 
	// 모든 edge를 탐색해서 최단 경로를 갱신 (단 아직 방문하지 않은 노드의 edge는 무시)
	for (int i = 1; i <= v; i++)
	{
		for (int j = 0; j < arr[i].size(); j++)
		{
			next = arr[i][j].first;
			w = arr[i][j].second;
			if (dist[i] != INF && dist[next] > dist[i] + w)
				dist[next] = dist[i] + w;
		}
	}
	return;
}
int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> v >> e;
	int a, b, c, temp;
	for (int i = 0; i < e; i++)
	{
		cin >> a >> b >> c;
		arr[a].push_back(make_pair(b, c));
	}
	for (int i = 2; i <= 500; i++)
		dist[i] = INF;
	for (int i = 2; i <= v; i++)
		bellman();

	int next, w;
	// 음수 사이클 있는지 확인
	// 이미 전부 갱신된 거리에서 한번 더 벨만 수행 
	// 바뀌는게 있으면 음수 사이클이 존재하는 것 (사이클 돌수록 거리 감소)
	for (int i = 1; i <= v; i++)
	{
		for (int j = 0; j < arr[i].size(); j++)
		{
			next = arr[i][j].first;
			w = arr[i][j].second;
    // 여기가 문제였음   INF인 경우는 무시해야됨(도달 불가능한 사이클)
			if (dist[i] != INF && dist[next] > dist[i] + w)
			{
				cout << "-1\n";
				return 0;
			}
		}
	}
	for (int i = 2; i <= v; i++)
	{
		if (dist[i] == INF)
			cout << "-1\n";
		else
			cout << dist[i] << "\n";
	}
	return 0;
}