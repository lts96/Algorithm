#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
using namespace std;
int n, m;
int* arr;
vector<int> v;
void p( int pick)
{
	if (pick == m)
	{
		for (int i = 0; i < v.size(); i++)
			cout << v[i] << " ";
		cout << "\n";
		
		return;
	}
	for (int i = 1; i <= n; i++)
	{
		v.push_back(i);
		p(pick+1);
		v.pop_back();
	}
	return;
}

int main(void)
{
	ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m; 
	arr = new int[n+1];
	for (int i = 0; i <= n; i++)
		arr[i] = 0;
	p(0);
	return 0;
}