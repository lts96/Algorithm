#include <iostream>
#include <vector>
#include <stack>

using namespace std;
stack<int> s;
vector<char> v;
int index = 1;
int main(void)
{
	bool flag = true;
	cin.tie(NULL); cout.tie(NULL);
	int n;
	cin >> n;
	int * arr = new int[n+1];
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	int i = 1;
	while(index < n+1)
	{
		if (!s.empty() && arr[index] == s.top())
		{
			v.push_back('-');
			s.pop();
			index++;
			continue;
		}
		else if (s.empty()||(arr[index] > s.top() && index <= n))
		{
			s.push(i);
			v.push_back('+');
			i++;
			continue;
		}
		else if (arr[index] < s.top())
		{
			flag = false;
			break;
		}
	}
	if (flag)
	{
		for (int i = 0; i < v.size(); i++)
		{
			cout << v[i] << "\n";
		}
	}
	else
		cout << "NO\n";
	//system("pause");
	return 0;
}