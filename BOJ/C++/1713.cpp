#include <iostream> 
#include <queue>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;
#define INF 987654321
int n, m;
int arr[1001];
int cnt[101];
vector <int> ans;
void print()
{
	for (int i = 0; i < ans.size(); i++)
	{
		cout << ans[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < ans.size(); i++)
	{
		cout << cnt[ans[i]] << " ";
	}
	cout << endl;
	return;
}
// 틀린 이유 : 변수 초기화 제대로 안해서
void solve()
{
	int target, flag, temp = INF;
	for (int i = 0; i < n; i++)
	{
		temp = INF;
		target = arr[i];
		flag = 0;
		if (ans.size() == m)
		{
			for (int j = 0; j < ans.size(); j++) // 이미 있는지 찾고
			{
				if (ans[j] == target)
				{
					flag++;
					cnt[target]++;
					break;
				}
			}
			if (!flag) // 없으면 갱신
			{
				for (int j = 0; j < ans.size(); j++)
					temp = min(temp, cnt[ans[j]]);
				for (int j = 0; j < ans.size(); j++)
				{
					if (cnt[ans[j]] == temp)
					{
						cnt[ans[j]] = 0;
						ans.erase(ans.begin() + j);
						ans.push_back(target);
						cnt[target]++;
						break;
					}
				}
			}
		}
		else
		{
			for (int j = 0; j < ans.size(); j++)
			{
				if (ans[j] == target)
				{
					flag++;
					cnt[target]++;
					break;
				}
			}
			if (!flag) // 없으면 사진 등록
			{
				ans.push_back(target);
				cnt[target]++;
			}
		}
		//print();
	}
	return;
}
int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> m;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	solve();
	sort(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << " ";
	return 0;
}
