#include <iostream>
#include <string>
#include <queue>
using namespace std;
int n;
int ans; 
queue <int> q;
int main(int argc, char** argv)
{
	cin >> n;
	int a, b;
	for (int i = 0; i < n; i++)
	{
		q.push(i + 1);
	}
	while (q.size()!= 1)
	{
		q.pop();
		if (q.size() != 1)
		{
			a = q.front();
			q.pop();
			q.push(a);
		}
		else 
		{
			ans = q.front();
			break;
		}
	}
	ans = q.front();
	cout << ans << endl;
	//system("pause");
	return 0;
}