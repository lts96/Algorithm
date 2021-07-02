#include <iostream>
#include <stdlib.h>
#include <string>
#include <stack>
#pragma warning (disable:4996)
using namespace std;
stack <int> s;
int main(void)
{
	int k;
	int temp;
	unsigned long long sum = 0;
	cin >> k;
	for (int i = 0; i < k; i++)
	{
		cin >> temp;
		if (temp != 0)
			s.push(temp);
		else
			s.pop();
	}
	while (!s.empty())
	{
		sum += s.top();
		s.pop();
	}
	cout << sum << endl;
	//system("pause");
	return 0;
}