#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>
#include <math.h>
#include <string>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int test, n;
	cin >> test;
	for (int k = 0; k < test; k++)
	{
		cin >> n;
		string cloth, body;
		vector<int> v(n + 1, 1);
		vector<string> code;
		for (int i = 0; i < n; i++)
		{
			cin >> cloth >> body;
			bool find = false;
			for (int j = 0; j < code.size(); j++)
			{
				if (body.compare(code[j]) == 0)
				{
					v[j]++;
					find = true;
					break;
				}
			}
			if (!find)
			{
				code.push_back(body);
				v[code.size()-1]++;
			}
		}
		int ans = 1;
		for (int i = 0; i < n; i++)
		{
			ans = ans * v[i];
			//cout << v[i] << " ";
		}
		ans--;
		cout << ans << "\n";
	}
	//system("pause");
	return 0;
}