#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <utility>
#include <queue>
#include <string>
#include <map>
using namespace std;
int arr[200005];
int cnt[200005];
int n;
map<string, int> m;
int find(int i)
{
	if (arr[i] == i)  // 내가 루트면 바로 반환
		return i;
	else
		return arr[i] = find(arr[i]); 
}
int union_set(int a, int b)  // b를 a에 합친다
{
	int root1 = find(a);
	int root2 = find(b);
	if (root1 == root2)
		return cnt[root1];  // 이미 같은 집합이면 크기 바로 반환

	arr[root2] = root1;
	cnt[root1] += cnt[root2]; // 서로의 집합 크기를 더한다
	cnt[root2] = 1;  // 더하고나서 한쪽은 1로 초기화?
	return cnt[root1];  // 루트쪽 크기를 반환 
}


int main(void) 
{
	ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
	int test;
	cin >> test;
	for (int i = 0; i < test; i++)
	{
		for (int j = 0; j < 200005; j++)
		{
			cnt[j] = 1;
			arr[j] = j;
		}
		cin >> n;
		string s1, s2;
		int k1, k2;
		int cnt = 0;
		for (int j = 0; j < n; j++)
		{
			cin >> s1 >> s2;
			if (!m.count(s1))  // map에 없는 경우 
			{
				m.insert(make_pair(s1, ++cnt));
				k1 = cnt;
			}
			else
				k1 = m.find(s1)->second;  // iter 반환이라 ->로 접근
			if (!m.count(s2))
			{
				m.insert(make_pair(s2, ++cnt));
				k2 = cnt;
			}
			else
				k2 = m.find(s2)->second;
			cout << union_set(k1, k2) << "\n";
		}
	}
	return 0;
}