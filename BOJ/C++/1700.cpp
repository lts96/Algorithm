#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <limits.h>
#include <stack>
using namespace std;
int n, k, ans;
int arr[101];
int cnt[101];
int plug[101];
/*
반례 
3 14
1 4 3 2 5 4 3 2 5 3 4 2 3 4
답 : 4


18퍼에서 틀림
남은 사용횟수가 제일 적은걸 뽑아야한다고 생각했는데 아니었다
남은 사용횟수가 없거나 지금 나한테서 제일 먼 코드를 뽑아야한다
구현 실수해서 틀림, 고치니까 맞음

*/
priority_queue <pair <int, int>> pq;
vector <int> target;
int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> k;
	for (int i = 0; i < k; i++)
	{
		cin >> arr[i];
		cnt[arr[i]]++;
	}
	bool flag;
	int use,m, idx = 0;
	for (int i = 0; i < k; i++)
	{
		flag = false;
		// 이미 쓰고 있는지 확인 
		for (int j = 0; j < n; j++)
		{
			if (plug[j] == arr[i])
			{
				cnt[arr[i]]--;
				flag = true;
				break;
			}
		}
		if (flag)
			continue;
		flag = false;
		// 빈자리가 있는지 확인 
		for (int j = 0; j < n; j++)
		{
			if (plug[j] == 0)
			{
				plug[j] = arr[i];
				cnt[arr[i]]--;
				flag = true;
				break;
			}
		}
		if (flag)
			continue;
		flag = false;
		// 나랑 제일 먼놈 찾아서 저장 
		for (int j = 0; j < n; j++)
		{
			flag = false;
			for (int h = i+1; h < k; h++)
			{
				if (arr[h] == plug[j])
				{
					pq.push(make_pair(h, plug[j]));
					flag = true;
					break;
				}
			}
			if(!flag)
				pq.push(make_pair(210000000, plug[j]));
		}
		idx = pq.top().second;
		while (!pq.empty())
			pq.pop();
		// 제일 먼 놈 제거 
		for (int j = 0; j < n; j++)
		{
			if (plug[j] == idx)
			{
				//cout << "case : " << plug[j] << endl;
				plug[j] = arr[i];
				cnt[idx]--;
				ans++;
				break;
			}
		}
	}
	cout << ans << endl;
	return 0;
}
