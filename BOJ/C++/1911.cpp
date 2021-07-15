#include <iostream> 
#include <queue>
#include <utility>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;
typedef long long ll;
ll n, m, ans;
vector <pair <ll, ll>> arr;
int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	int a, b;
	for (int i = 0; i < n; i++)
	{
		cin >> a >> b;
		arr.push_back(make_pair(a,b));
	}
	
	sort(arr.begin(), arr.end());
	int x, y, idx = 0;

	// 너무 복잡하게 생각했고 L = 3 이었던 테케만 생각함 
	// 다양한 경우를 고려해서 일반화할것 

	for (int i = 0; i < n; i++)
	{
		x = arr[i].first;
		y = arr[i].second;
		if (x > idx)
			idx = x;
		// 만약 idx가 x보다 크면 이어서 진행하므로 널판지 절약 
		// idx > x라는 거부터가 널판지를 이을 수 있었다는 의미 
		while (idx < y)
		{
			idx += m;
			ans++;
		}
	}
	cout << ans << endl;
	return 0;
}
