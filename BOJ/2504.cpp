#include <iostream> 
#include <stack>
#include <stdlib.h>
#pragma warning (disable:4996)
using namespace std;
char buf[32];
int ans;
stack <char> s;
stack <int>  num;    // '(' = -2 , '[' = -3
int func()                                    //런타임 해결됬는데 95퍼에서 틀림?
{
	int temp = 0;
	int count = 0;
	for (int i = 0; i < 30; i++)
	{
		if (buf[i] == '(' || buf[i] == '[')
		{
			if (buf[i] == '(')
				num.push(-2);
			if (buf[i] == '[')
				num.push(-3);
		}
		else if (buf[i] == ')')
		{
			if (!num.empty() && num.top() == -2) // '('
			{
				num.pop();
				num.push(2);
			}
			else if (!num.empty() && num.top() > 0)
			{
				temp = num.top() * 2;
				num.pop();
				if(!num.empty())
				num.pop();
				num.push(temp);
			}
			else if (num.empty() || num.top() <0)
			{
				return 0;
			}
		}
		else if (buf[i] == ']')
		{
			if (!num.empty() && num.top() == -3)
			{
				num.pop();
				num.push(3);
			}
			else if (!num.empty() && num.top() > 0)
			{
				temp = num.top() * 3;
				num.pop();
				if (!num.empty())
				num.pop();
				num.push(temp);
			}
			else if (num.empty() || num.top()<0)
			{
				//cout << num.top()<<endl;
				return 0;
			}
		}

		if (!num.empty() && num.top() > 0) //헷갈리는 부분.나중에 다시보기
		{
			temp = num.top();
			num.pop();
			if (!num.empty() && num.top() > 0)
			{
				temp += num.top();
				num.pop();
				num.push(temp);
			}
			else
				num.push(temp);
		}
		if (buf[i] == '\0')
			break;

		temp = 0;
	}
	temp = num.top();
	while (!num.empty()) // 오류 제거 
	{
		if (num.top() < 0)
			temp = 0;
		num.pop();
	}

	if (temp > 0)
		return temp;
	else
		return 0;
}
int main(void)
{
	int count1 = 0;
	int count2 = 0;
	scanf("%s", buf);
	for (int i = 0; i < 30; i++) // 괄호의 개수가 홀수인 경우 제거 
	{
		if (buf[i] == '(' )
			count1++;
		if (buf[i] == ')' )
			count1--;
		if (buf[i] == '[')
			count2++;
		if (buf[i] == ']')
			count2--;
	}
	if (count1 != 0 || count2!=0)
		ans = 0;
	else 
		ans = func();
	cout << ans << endl;
	//system("pause");
	return 0;
}
