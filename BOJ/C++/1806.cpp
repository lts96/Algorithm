#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <string>
using namespace std;
int n, s, ans = 100000000;
int arr[100001];
int main()
{
	int start = 0, end = 0;
	bool flag = false;
	cin >> n >> s;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	int sum = arr[0];
	while (start < n)
	{
		if (sum >= s)  // if else 조건 꼬여서 틀림 -> 주의할 것 
		{
			int len = end - start + 1;
			if (len < ans)
			{
				ans = len;
				flag = true; // 부분합이 s 넘는게 가능한지 아닌지 체크용 
			}
			sum -= arr[start];
			start++;
		}
		else if (end == n - 1)
		{
			sum -= arr[start];
			start++;
		}
		else
		{
			end++;
			sum += arr[end];
		}
	}
	if (flag == false)
		ans = 0;
	cout << ans << endl;
	//system("pause");
	return 0;
}