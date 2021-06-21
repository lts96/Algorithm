#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>
#define INF 2147483600
using namespace std;
int v, e , k;
class vertax {
public:
	int dist;
	int parent;
	int index;
	vertax(int i, int d ,int p)
	{
		this->dist = d;
		this->parent = p;
		this->index = i;
	}
};
vector<pair<int, int> > arr[20001];
priority_queue<vertax> q;
int dist[20001];
bool operator < (const vertax& a, const vertax& b) // sort 하려고 연산자 재정의
{
	return a.dist > b.dist;
}
int find(int s ,int d)
{
	while (!q.empty())
	{
		int d = q.top().dist;
		int index = q.top().index;
		q.pop();   // 바로 pop 안해주면 무한 루프 돈다.
		if (dist[index] < d) // 은근히 중요한 부분 , 방문 체크 -> 이미 계산한걸 다시 계산 안하고 넘어감
			continue;
		for (int i = 0; i < arr[index].size(); i++)
		{
			int next = arr[index][i].first;
			int weight = arr[index][i].second;
			
			if (dist[next] > dist[index] + weight)
			{
				dist[next] = dist[index] + weight;
				q.push(vertax(next, dist[next], index));
			}
		}
	}
	return dist[d];
}
// 다익스트라 문제 , 인접 행렬로 그래프 표현 불가 -> input 너무 큼 
// 그리고 시간 복잡도 n^2시 초과   우선순위 큐 써서 nlogn으로 줄여야됨
int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> v >> e;
	cin >> k;
	int a, b, c;
	for (int i = 1; i <= v; i++)
	{
		if (i != k)
		{
			dist[i] = INF;
		}
		else
		{
			dist[i] = 0;
			q.push(vertax(i, 0, -1));  // 여기 값 잘못 넣어서 틀렸었음 parent는 사실 불필요
		}
	}
	for (int i = 0; i < e; i++)
	{
		cin >> a >> b >> c;
		arr[a].push_back(make_pair(b, c));
	}
	for (int i = 1; i <= v; i++)
	{
		int ans = find(k,i);
		if (ans != INF)
			cout << ans << "\n";
		else
			cout << "INF\n";
	}
	return 0;
}