#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <utility>
#include <math.h>
#include <limits.h>
using namespace std;
int n, s, ans;
int arr[21];
bool visit[21];
/*
반례 
5 0 
-5 -3 2 3 5
답 : 4
*/
void backtracking(int idx, int select)
{
	if (idx >= n)
	{
		int sum = 0;
		for (int i = 0; i < n; i++)
		{
			if (visit[i] == true)
				sum += arr[i];
			//cout << visit[i] << " ";
		}
		//cout << endl;
		if (sum == s && select > 0)
			ans++;
		return;
	}
	visit[idx] = true;
	backtracking(idx + 1, select + 1);
	visit[idx] = false;
	backtracking(idx + 1, select);
	return;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> s;
	int input;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	sort(arr, arr + n);
	backtracking(0, 0);
	cout << ans << endl;
	return 0;
}
