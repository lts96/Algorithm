#include <iostream>
#include <math.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int n;
vector<int> v[100001];
int arr[100001];
void refactoring(int k)
{
	for (int i = 0; i < v[k].size(); i++)
	{
		int index = v[k][i];
		if (arr[index] == 0)
		{
			arr[index] = k;
			refactoring(index);
		}
	}
	return;
}
int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	int a, b;
	for (int i = 0; i < n-1; i++)
	{
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	arr[1] = 1;
	refactoring(1);
	for (int i = 2; i <= n; i++)
		cout << arr[i] << "\n";
}