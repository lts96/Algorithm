#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <utility>
#include <math.h>
#include <limits.h>
using namespace std;
int n, ans;

/*
반례
3 3 7 13 / 2 3 9 6
0이 아닌 차이값 2개를 찾아서 이 2개의 최대 공약수를 구하면 된다
2개만 구하면 안된다, 반례 1 5 2 4 6 9 12
간단한 식으로 증명 가능 -> 직접해서 푸는게 빠르다
2개의 최대공약수만으론 약할거 같아서 전체 차이들의 최대공약수를 구함
*/
int gcd(int a, int b)
{
	if (a % b == 0)
		return b;
	return gcd(b, a % b);
}
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int test;
	cin >> test;
	for (int t = 0; t < test; t++)
	{
		ans = 0;
		cin >> n;
		int input;
		vector <int> arr;
		for (int i = 0; i < n; i++)
		{
			cin >> input;
			arr.push_back(input);
		}
		sort(arr.begin(), arr.end());
		vector <int> v, v2;
		for (int i = 0; i < arr.size() - 1; i++)
			v.push_back(arr[i + 1] - arr[i]);
		sort(v.begin(), v.end());
		for (int i = 0; i < v.size(); i++)
		{
			if (v[i])
				v2.push_back(v[i]);
		}
		if (v2.size() == 1)
		{
			ans = v2[0];
			if (ans)
				cout << ans << "\n";
			else
				cout << "INFINITY\n";
		}
		else if (v2.size() == 0)
			cout << "INFINITY\n";
		else
		{
			ans = v2[0];
			for(int i=1; i<v2.size(); i++)
				ans = gcd(ans, v2[i]);
			cout << ans << "\n";
		}
		v.clear();
		v2.clear();
		arr.clear();
	}
	return 0;
}
