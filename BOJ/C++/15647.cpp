#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <queue>
using namespace std;
#define MAX 300007

typedef long long ll;
ll n;
// 자신을 루트로 하는 서브트리 노드 수 
ll num[MAX];
// 자신을 루트로 하는 서브트리에서 가중치 총합
ll sum[MAX];
// 모든 노드에 대해서 정답을 구해야함 
ll ans[MAX];
vector < pair < ll, ll >> arr[MAX];

void dfs1(int idx, int prev)
{
    ll next, w;
    num[idx] = 1;
    for (int i = 0; i < arr[idx].size(); i++)
    {
        next = arr[idx][i].first;
        w = arr[idx][i].second;
        // 방문체크 
        if (next != prev)
        {
            dfs1(next, idx);
            // 테크닉 
            // 굳이 dfs 두번 돌 필요없이 리턴값 말고 이렇게 갱신하면 한번에 가능
            num[idx] += num[next];
            // 현재 내 sum 값은 내 자식의 노드수 * 자식과 나의 가중치 간선 곱
            // + 내 자식의 가중치 총합 
            sum[idx] += (num[next] * w + sum[next]);
        }
    }
    return;
}
// 다시 모든 노드를 돌면서 정답을 갱신해준다 
// 지금 1번 노드를 제외하곤 자신의 한쪽 자식만 체크된 상태 
// 1번쪽도 체크해야함 
void dfs2(int idx, int prev, ll result)
{
    ll next, w, temp;
    ans[idx] = result;
    for (int i = 0; i < arr[idx].size(); i++)
    {
        next = arr[idx][i].first;
        w = arr[idx][i].second;
        if (next != prev)
        {
            // 다음 자식의 값은 
            // 1이 가진 전체값 - 내 서브트리 자식수 * w 
            // + 내 서브트리엔 없고 1쪽 서브트리에 있는 노드 수 * w
            // 그림으로 그린 다음 반 잘라서 비교하면 이해가 쉽다 
            temp = result - (w * num[next]) + (w * (n - num[next]));
            dfs2(next, idx, temp);
        }
    }
    return;
}
// dp는 아래서부터 올라오고 
// 정답은 위에서부터 갱신 
int main(void)
{
	ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	int a, b, c;
	for (int i = 0; i < n - 1; i++)
	{
		cin >> a >> b >> c;
		arr[a].push_back({ b, c });
		arr[b].push_back({ a, c });
	}
    dfs1(1, -1);
    // 1에서 모든 노드로부터 가중치 합은 구했으므로 그대로 넣어줌 
    dfs2(1, -1, sum[1]);
	for (int i = 1; i <= n; i++)
		cout << ans[i] << "\n";
	return 0;
}
