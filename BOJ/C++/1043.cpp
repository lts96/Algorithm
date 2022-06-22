#include <iostream> 
#include <queue>
#include <utility>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <math.h>
using namespace std;
int n, m, t, ans;


// 유니온 파인드 문제 
int truth[51];
int arr[51];
vector <int> party[51];
int find(int a)
{
	if (a == arr[a])
		return a;
	return arr[a] = find(arr[a]);
}
void union_set(int a, int b)
{
	int root1 = find(a);
	int root2 = find(b);
	if (root1 == root2)
		return;
	if (truth[root1])
	{
		arr[root2] = root1;
		return;
	}
	else if (truth[root2])
	{
		arr[root1] = root2;
		return;
	}
	arr[root2] = root1;
	return;
}

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	cin >> t;
	int temp, num;
	for (int i = 0; i <= 50; i++)
		arr[i] = i;
	for (int i = 0; i < t; i++)
	{
		cin >> temp;
		truth[temp] = 1;
	}
	vector <int> v;
	int root, flag;

	// 일단 모든 노드에 대해 union을 실행하고 나중에 판정해야함
	for (int i = 0; i < m; i++)
	{
		cin >> temp;
		v.clear();
		flag = 0;
		for (int j = 0; j < temp; j++)
		{
			cin >> num;
			v.push_back(num);
			party[i].push_back(num);
		}
		// 파티 인원수가 1 초과일 경우 
		if (v.size() > 1)
		{
			for (int j = 1; j < v.size(); j++)
				union_set(v[j - 1], v[j]);
		}
	}
	// 판정하기 전에 root 한번 정리 
	for (int i = 1; i <= n; i++)
	{
		find(i);
		//cout << arr[i] << " ";
	}
	//cout << endl;
	
	for (int i = 0; i < m; i++)
	{
		flag = 0;
		for (int j = 0; j < party[i].size(); j++)
		{
			root = arr[party[i][j]];
			if (truth[root])
			{
				flag++;
				break;
			}
		}
		if (!flag)
			ans++;
	}
	cout << ans << "\n";
	return 0;
}
