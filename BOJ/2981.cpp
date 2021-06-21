#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <utility>
#include <stack>
using namespace std;
int n;
vector<int> v , ans;
int gcd(int a, int b)  //유클리드 호제법 참고 
{
	if (b == 0)
		return a;
	return gcd(b, a % b);
}
int main(void)
{
	ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	int temp ,g;
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		v.push_back(temp);
	}
	sort(v.begin(), v.end()); // 반드시 정렬이 필요 
	g = v[1] - v[0];
	if (n > 2)
	{
		// 모든 수 n에 대해서 gcd를 구해야함 
		// 앞의 수로만 gcd를 구해서 틀림 
		for (int i = 0; i < n - 1; i++)
			g = gcd(g, v[i + 1] - v[i]);
	}
	// 최대공약수 g의 약수를 찾기 
	// 굳이 소수로 나눠주면서 찾을 필요 없음 -> 이러면 합성수로 된 약수가 안나옴

	for (int i = 1; i <= sqrt(g); i++) // 시간 초과를 피하기 위해 제곱근까지
	{
		if (g % i == 0)
		{
			ans.push_back(i);
			if(g / i != i)
				ans.push_back(g / i);
		}
	}
	sort(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i++)
	{
		if(ans[i]!=1)
			cout << ans[i] << " ";
	}
	return 0;
}