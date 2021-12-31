#include <string>
#include <vector>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <limits.h>
using namespace std;
typedef long long ll;
ll arr[20][20];
ll n, ans = LLONG_MAX, start, p;
// 현재 비트 상태에서 가장 최소 비용을 저장
ll cache[65600];
//  bit는 현재 가동중인 발전소들 상태  cnt는 정상 발전소 개수
/*
외판원 응용한거
그래프로 생각하자, 비용은 연결된 간선의 가중치다
dfs를 순회하는 과정에서 오류가 있었다 -> 왜 2중 for문이 필요했을까? 잘 생각해보기
내가 이전에 짠 코드는 dfs 탐색에서 계속 내려가기만 할뿐 예제 1번을 통과할 수 없었다.
하지만 수정된 코드는 우선 현재 상태를 기준으로 고칠 수 있는 노드로 이동하기 때문에 예제 1번도 통과 가능하다.
반드시 2중 for로 구현해야 예제 1번 같은 케이스를 커버할 수 있다 (내려가지 않고 현재 노드에서 모두 고치는 경우)
*/
ll dp(ll bit, ll cnt)
{
    ll w, ret = LLONG_MAX, temp = 0;
    // 전부다 가동되었거나 p개 이상 가동시 중지 
    if (bit == (2 << n - 1) || cnt >= p)
        return 0;
    if (cache[bit] != -1)
        return cache[bit];
    // 이 부분이 달랐었음 
    for (int i = 0; i < n; i++)
    {
        if ((bit & (1 << i)))
        {
            for (int j = 0; j < n; j++)
            {
                w = arr[i][j];
                if (!(bit & (1 << j)))
                    ret = min(ret, w + dp(bit | (1 << j), cnt + 1));
            }
        }
    }
    return cache[bit] = ret;
}
int main(void)
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    string s;
    cin >> n;
    ll cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];
    }
    cin >> s;
    cin >> p;
    for (int j = 0; j < 65600; j++)
        cache[j] = -1;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == 'Y')
        {
            cnt++;
            start |= (1 << i);
        }
    }
    ans = dp(start, cnt);
    if (ans == LLONG_MAX)
        ans = -1;
    cout << ans << endl;
    return 0;
}
