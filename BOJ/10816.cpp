#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>
#include <math.h>
using namespace std;
int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, m;
	cin >> n;
	int* card = new int[n];
	for (int i = 0; i < n; i++)
		cin >> card[i];
	cin >> m;
	int* arr = new int[m];
	for (int i = 0; i < m; i++)
		cin >> arr[i];
	sort(card, card + n);
	for (int i = 0; i < m; i++)
	{
		int target = arr[i];
		int up = upper_bound(card, card + n, target) - arr;
		int low = lower_bound(card, card + n, target) - arr;
		cout << up - low << " ";
	}
	return 0;
}