#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>
#include <math.h>
using namespace std;
int arr[201];
int n, m;
int find(int x)
{
	if (arr[x] == x)
		return x;
	return arr[x] = find(arr[x]);
}
void union_set(int a, int b)
{
	int root1 = find(a);
	int root2 = find(b);
	arr[root2] = root1;
}

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n; 
	cin >> m;
	int input;
	bool flag = true;
	for (int i = 1; i <= n; i++)
		arr[i] = i;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> input;
			if (input)
			{
				if (find(i) != find(j)) // 연결 안되어 있으면 연결
					union_set(i, j);
			}
		}
	}
	int start , end;
	for (int i = 1; i <= m; i++)
	{
		if (i == 1)
		{
			cin >> start;
			end = start;
			continue;
		}
		cin >> end;
		if (find(end) != find(start))
		{
			flag = false;
			break;
		}
		end = start;
	}
	if (flag)
		cout << "YES\n";
	else
		cout << "NO\n";
	return 0;
}