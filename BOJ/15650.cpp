#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>
#include <math.h>
#include <string>
#include <sstream>
using namespace std;
int n, m;
int* arr;
void p(int index , int pick)
{
	if (pick == m)
	{
		for (int i = 0; i < n; i++)
		{
			if (arr[i])
				cout << i + 1 << " ";
		}
		cout << "\n";
		return;
	}
	if (index == n)
		return;
	arr[index] = 1;
	p(index + 1, pick + 1);
	arr[index] = 0;
	p(index + 1, pick);
	return;
}

int main(void)
{
	ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m; 
	arr = new int[n];
	for (int i = 0; i < n; i++)
		arr[i] = 0;
	p(0,0);
	return 0;
}