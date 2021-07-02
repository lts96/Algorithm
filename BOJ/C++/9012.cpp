#include <iostream>
#include <stdlib.h>
#include <stack>
#pragma warning(disable : 4996)
using namespace std; 
int n; 
bool *ans;
char buf[52];

bool vps()
{
	stack <char> s;  // 초기화가 이상? 3 ()()  () () -> 반례
	/*
	for (int i = 0; i < 50; i++) // 혹시 몰라서 이상한 문자들 제외
	{
		if ((buf[i] != '(' && buf[i] != ')') && buf[i] != '\0')
		{
			//cout << "error!\n";
			return false;
		}
	}
	*/
	for (int i = 0; i < 50; i++)
	{
		if (buf[i] == '(')
			s.push(buf[i]);
		else if (buf[i] == ')')
		{
			if (!s.empty() && s.top() == '(')
			{
				s.pop();
			}
			else
			{
				while (!s.empty()) s.pop();
				return false;
			}
		}
		else if (buf[i] == '\0')
			break;
	
	}
	return s.empty();
}
int main(void)
{

	cin >> n;
	ans = new bool[n];
	for (int i = 0; i < n; i++)
	{
		scanf("%s",buf);
		//cout << "input :" << buf<<endl;
		ans[i]= vps();
	}
	for (int i = 0; i < n; i++)
	{
		if (ans[i] == true)
			cout << "YES" <<endl;
		else
			cout << "NO" <<endl;
	}
	//system("pause");
	return 0; 
}