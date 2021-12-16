#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <limits.h>
using namespace std;
typedef long long ll;
#define MAX 20000
vector <pair <ll, ll>> arr[MAX + 2];
ll ans, n;
// 현재 노드를 중심으로 가중치 합 
ll sum[MAX + 2];
// 나를 포함하는 서브트리 노드 수 
ll num[MAX + 2];

/*
    첫번째 dfs를 돌면서 시작점을 중심으로 가중치 합을 1번 구한다
    앞에서 구한 가중치를 이용해서 다른 노드 중심 가중치 합을 한번 더 구함 (dfs2)
    구글링하면 설명 잘된 블로그 있으니 궁금하면 참고하자
*/
void clear()
{
    for (int i = 0; i <= MAX; i++)
    {
        while (!arr[i].empty())
            arr[i].pop_back();
        sum[i] = num[i] = 0;
    }
    return;
}
void dfs1(int idx, int prev)
{
    ll next, w;
    num[idx] = 1;
    for (int i = 0; i < arr[idx].size(); i++)
    {
        next = arr[idx][i].first;
        w = arr[idx][i].second;
        if (next != prev)
        {
            dfs1(next, idx);
            num[idx] += num[next];
            sum[idx] += (num[next] * w + sum[next]);
        }
    }
    return;
}
void dfs2(int idx, int prev, ll result)
{
    ll next, w, temp;
    if (ans >= result)
        ans = result;
    for (int i = 0; i < arr[idx].size(); i++)
    {
        next = arr[idx][i].first;
        w = arr[idx][i].second;
        if (next != prev)
        {
            temp = result - (w * num[next]) + (w * (n - num[next]));
            dfs2(next, idx, temp);
        }
    }
    return;
}
int main() {
    int test, a, b, c;
    while (1)
    {
        cin >> n;
        if (n == 0)
            break;
        ans = LLONG_MAX;
        for (int i = 0; i < n - 1; i++)
        {
            cin >> a >> b >> c;
            arr[a].push_back({ b,c });
            arr[b].push_back({ a,c });
        }
        dfs1(1, -1);
        dfs2(1, -1, sum[1]);
        cout << ans << "\n";
        clear();
    }
    return 0;
}
