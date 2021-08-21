#include <iostream>
#include <algorithm>
#include <math.h>
#include <queue>
#include <string>
#include <stack>
using namespace std;
int n,ans, temp;
priority_queue<int, vector <int>, greater<int>> q;
// 우선순위 큐 써서 n개만 큐에 담아가며 진행하면 됨
// 만약 모든 수를 담으려고 했다간 문제 메모리 제한에 걸릴테니 불가능 

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> temp;
			if (q.empty() || q.size() < n)
				q.push(temp);
			else
			{
				if (q.top() < temp)
				{
					q.pop();
					q.push(temp);
				}
			}
		}
	}
	cout << q.top() << "\n";
	return 0;
}
