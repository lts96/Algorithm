#include <iostream>
#include <algorithm>
#include <math.h>
#include <queue>
#include <string>
#include <stack>
using namespace std;
int n , ans = 2100000000;
int ans1, ans2;
int arr[100001];
// 투 포인터 문제 
// 배열 양쪽에 포인터를 두고 이동하면서 진행 
// 용액의 합이 0보다 작으면 왼쪽 포인터 한칸 이동, 0보다 크면 오른쪽 포인터 한칸 이동
int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	int left = 0, right = n - 1, temp;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	while (arr[left] < arr[right])
	{
		if (abs(arr[left] + arr[right]) <= ans)
		{
			ans = min(ans, abs(arr[left] + arr[right]));
			ans1 = arr[left];
			ans2 = arr[right];
		}
		if (arr[left] + arr[right] == 0)
		{
			cout << arr[left] << " " << arr[right] << endl;
			return 0;
		}
		else if (arr[left] + arr[right] < 0)
			left++;
		else
			right--;
	}
	cout << ans1 << " " << ans2 << endl;
	return 0;
}
