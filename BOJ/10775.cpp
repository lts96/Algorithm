#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <utility>
#include <queue>
using namespace std;
int arr[100001];
int find(int i)
{
	if (arr[i] == i)
		return arr[i];
	return arr[i] = find(arr[i]);
}
void union_set(int a, int b)
{
	int root1 = find(a);
	int root2 = find(b);
	arr[root2] = root1;
	return;
}

int main(void) 
{
	ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
	int g, p , input;
	cin >> g >> p;
	for (int i = 0; i < 100001; i++)
		arr[i] = i;
	int ans = 0;
	bool flag = true;
	for (int i = 0; i < p; i++)
	{
		cin >> input;
		if (find(input) == 0)
			flag = false;
		int target = find(input) - 1;
		union_set(target, input);
		find(input);
		if (flag)
			ans++;
	}
	cout  << ans << endl;
	return 0;
}