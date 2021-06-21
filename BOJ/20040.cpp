#include <iostream> 
#include <queue>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;
int n, m, ans;
int arr[500001];
int find(int a)
{
	if (arr[a] == a)
		return a;
	return arr[a] = find(arr[a]);
}
void unionSet(int a, int b)
{
	int root1 = find(a);
	int root2 = find(b);
	arr[root2] = root1;
	return;
}
int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	int a, b;
	for (int i = 0; i < n; i++)
		arr[i] = i;
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;
		if (find(a) == find(b))
		{
			cout << i + 1 << "\n";
			return 0;
		}
		else
			unionSet(a, b);
	}
	cout << 0 << "\n";
	return 0;
}
