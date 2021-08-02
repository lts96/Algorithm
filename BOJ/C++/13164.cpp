#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <limits.h>
#include <stack>
using namespace std;
int n, k, ans;

/*
그리디 문제 
2개의 수를 k번 뽑아서 수의 차이를 모두 더한 값이 최소가 되게 해라?
차이값 n-1개 중에서 k-1개를 무시하면 답
즉 n-1-(k-1) = n-k 개 만큼 더해주자
*/
vector <int> arr, diff;
int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> k;
	int input;
	for (int i = 0; i < n; i++)
	{
		cin >> input;
		arr.push_back(input);
	}
	for (int i = 0; i < arr.size() - 1; i++)
		diff.push_back(arr[i + 1] - arr[i]);
	sort(diff.begin(), diff.end());
	for (int i = 0; i < diff.size() - (k - 1); i++)
		ans += diff[i];
	cout << ans << endl;
	return 0;
}
