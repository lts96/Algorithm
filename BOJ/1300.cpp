#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <vector>
using namespace std;
unsigned long long n, k;

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n; 
	cin >> k;
	unsigned long long left, right, mid ,cnt, ans = 0;
	left = 1;
	right = k; // k로 바꿔야할지 고민 
	//(어차피 k번째수는 k보다 작거나 같을게 명백하므로 이렇게 해도 될듯?)

	// **내가 놓친 부분 -> i * j <= mid 여야 하므로 이걸 만족하는 j의 개수는 mid / i 라는 것 
	while (left <= right)
	{
		cnt = 0;
		mid = (left + right) / 2;
		for (int i = 1; i <= n; i++)
			cnt += min(mid / i , n);  //min 을 거는 이유는 n = 1000이면 첫번째 mid가 50만이 되어서 mid/i 가 n보다 커짐 
		if (cnt < k)
			left = mid + 1;
		else // 최대한 근사하는 값을 찾는다고 생각  cnt == k로 일치하지 않는다 
		{
			ans = mid;
			right = mid - 1;
		}
		/*
		else if (cnt == k)   이렇게 하면 cnt = k에 안걸리는 경우가 생겨서 오답됨 
		*/
		
	}
	cout << ans << endl;
	return 0;
}