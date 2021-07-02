#include <iostream>
#include <string>
#include <queue>
using namespace std;
int n , k;
int ans; 
queue <int> q;
int main(int argc, char** argv)
{
	int a;
	int count = 0;
	cin >> n >> k;
	cout << "<";
	for (int i = 0; i < n; i++)
	{
		q.push(i + 1);
	}
	while(!q.empty())
	{
		a = q.front();
		q.pop();
		count++; 
		if (count == k)
		{
			count = 0; 
			cout << a;
			if (q.size() != 0)
			{
				cout << ", ";
			}
		}
		else
		{
			q.push(a);
		}
	}
	cout <<">";
	//system("pause");
	return 0;
}