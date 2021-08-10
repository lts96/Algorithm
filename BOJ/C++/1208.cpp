#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <utility>
#include <math.h>
#include <limits.h>
using namespace std;
long long n, s, ans;
int arr[41];
bool visit[41];
/*
반례 
5 0 
-5 -3 2 3 5
답 : 4

6 3
1 1 1 -1 -1 -1
답 : 1

3 0
0 0 0 
답 : 7

연속하지 않는 경우도 있기 때문에 투포인터로는 해결 불가능
백트래킹을 쓰기엔 숫자가 너무 크니 반씩 쪼개서 백트래킹을 하고 나온 결과를 이분탐색으로 서로 합한다
틀린 이유 : 백트래킹 범위 값이 틀렸음
하나도 안뽑는 경우와 백트래킹 결과에서 중복되는 숫자가 있는 경우를 예외처리해야함
57퍼에서 시간초과남 -> lower bound랑 upper로 바꾸니까 시간초과는 해결
하지만 57퍼 넘어서 틀림 -> 정답이 천억까지 감 -> 오버플로우 고치니까 70퍼 정도에서 틀림
질문 게시판에서 반례 찾음 , 양쪽 모두에서 안골랐을때 예외처리가 이상해서 틀렸던 것

*/
vector <pair<int, int >> result[2];
bool comp(const pair<int, int>& a, const pair<int, int>& b) {
	return a.first < b.first;
}
void backtracking(int idx, int start, int end, int select, int d)
{
	if (idx >= end)
	{
		long long sum = 0;
		for (int i = start; i < end; i++)
		{
			if (visit[i] == true)
				sum += arr[i];
		}
		result[d].push_back(make_pair(sum, select));
		return;
	}
	visit[idx] = true;
	backtracking(idx + 1, start, end, select + 1,d);
	visit[idx] = false;
	backtracking(idx + 1, start, end, select,d);
	return;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> s;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	sort(arr, arr + n);
	backtracking(0, 0, n/2, 0 , 0);
	backtracking(n/2, n/2, n, 0 ,1);
	sort(result[0].begin(), result[0].end());
	sort(result[1].begin(), result[1].end());
	
	
	int l, r, mid, target, temp,select, idx;
	for (int i = 0; i < result[0].size(); i++)
	{
		target = s - result[0][i].first;
		select = result[0][i].second;
		l = lower_bound(result[1].begin(), result[1].end(), make_pair(target, select), comp) - result[1].begin();
		r = upper_bound(result[1].begin(), result[1].end(), make_pair(target, select), comp) - result[1].begin();
		//cout << l << " " << r <<" " << result[1].size() << endl;
		if (result[1][l].first == target && select + result[1][l].second > 0)
			ans += (r - l);
		// 반으로 쪼갤때 양쪽 모두에서 1개도 고르지 않은 경우는 제외해야한다 
		else if (result[1][l].first == target && select + result[1][l].second == 0)
			ans += (r - l) - 1;
	}
	cout << ans << endl;
	return 0;
}
