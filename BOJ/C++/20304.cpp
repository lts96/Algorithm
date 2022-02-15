#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <utility>
#include <stack>
#include <queue>
using namespace std;
#define MAX 1000000 + 10
int n, m, ans;
bool visit[MAX];
vector <int> arr[MAX];
queue <pair <int, int>> q;
// 백만은 20개의 비트로 표현 가능
// 0 ~ n까지 숫자를 각각 노드라고 생각하자
// 그리고 이 노드들을 서로 붙어있는 경우끼리 간선을 이어준다 
// xor 해서 비트가 1개 차이나는 경우 = 거리가 1인 경우
// 이런식으로 bfs해서 가장 깊은 depth를 찾는 문제
void bfs()
{
	// bfs를 돌면서 거리가 가까운 노드부터 방문을 하게 됨
	// 결국 제일 마지막에 남는 노드가 모든 방문점으로부터 거리가 
	// 가장 먼 노드가 되므로 그때 거리를 출력하면 끝
	int x, nx, d = 0;
	while (!q.empty())
	{
		x = q.front().first;
		d = q.front().second;
		q.pop();
		for (int i = 0; i < 20; i++)
		{
			nx = x ^ (1 << i);
			if (nx <= n && !visit[nx])
			{
				visit[nx] = true;
				q.push({ nx, d + 1 });
			}
		}
	}
	ans = d;
}

int main(void)
{
	ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	cin >> m;
	int temp;
	for (int i = 0; i < m; i++)
	{
		cin >> temp;
		visit[temp] = true;
		q.push({ temp, 0 });
	}
	bfs();
	cout << ans << "\n";
	return 0;
}
