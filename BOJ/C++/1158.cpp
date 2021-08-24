#include <iostream>
#include <algorithm>
#include <math.h>
#include <queue>
#include <string>
#include <stack>
using namespace std;
int n, k;
queue <int> q;
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> k;
	cout << "<";
	int i = 0, temp;
	for (int i = 0; i < n; i++)
		q.push(i + 1);
	while (!q.empty())
	{
		temp = q.front();
		q.pop();
		i++;
		if (i != k)
			q.push(temp);
		else
		{
			i = 0;
			cout << temp;
			if (!q.empty())
				cout << ", ";
			else
				cout << ">";
		}
	}
	return 0;
}
