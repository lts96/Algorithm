#include <iostream> 
#include <queue>
#include <utility>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
using namespace std;
#define MAX 1000000000
typedef long long ll;
stack <ll> s;
vector <pair <string, int >> program;

/*
틀렸던 이유
에러 메세지를 2군데 넣었었음 -> 에러메세지가 2번 출력 
*/


int num(ll x)
{
	s.push(x);
	return 1;
}
int pop()
{
	if (s.empty())
		return -1;
	s.pop();
	return 1;
}
int inv()
{
	if (s.empty())
		return -1;
	ll top = s.top();
	s.pop();
	s.push(top * -1);
	return 1;
}
int dup()
{
	if (s.empty())
		return -1;
	ll top = s.top();
	s.push(top);
	return 1;
}
int swp()
{
	ll a, b, ret;
	if (s.size() < 2)
		return -1;
	a = s.top();
	s.pop();
	b = s.top();
	s.pop();
	s.push(a);
	s.push(b);
	return 1;
}
int add()
{
	ll a, b, ret;
	if (s.size() < 2)
		return -1;
	a = s.top();
	s.pop();
	b = s.top();
	s.pop();
	ret = a + b;
	if (abs(ret) > MAX)
		return -1;
	s.push(ret);
	return 1;
}
int sub()
{
	ll a, b, ret;
	if (s.size() < 2)
		return -1;
	a = s.top();
	s.pop();
	b = s.top();
	s.pop();
	ret = b - a;
	if (abs(ret) > MAX)
		return -1;
	s.push(ret);
	return 1;
}
int mul()
{
	ll a, b, ret;
	if (s.size() < 2)
		return -1;
	a = s.top();
	s.pop();
	b = s.top();
	s.pop();
	ret = a * b;
	if (abs(ret) > MAX)
		return -1;
	s.push(ret);
	return 1;
}
int div()
{
	ll a, b, ret, cnt = 0;
	if (s.size() < 2)
		return -1;
	a = s.top();
	s.pop();
	b = s.top();
	s.pop();
	if (a == 0)
		return -1;
	ret = b / a;
	if (abs(ret) > MAX)
		return -1;
	s.push(ret);
	return 1;
}
int mod()
{
	ll a, b, ret;
	if (s.size() < 2)
		return -1;
	a = s.top();
	s.pop();
	b = s.top();
	s.pop();
	if (a == 0)
		return -1;
	ret = b % a;
	if (abs(ret) > MAX)
		return -1;
	s.push(ret);
	return 1;
}
int run()
{
	ll ret = 0, input;
	string cmd;
	for (int i = 0; i < program.size(); i++)
	{
		cmd = program[i].first;
		input = program[i].second;
		if (cmd == "NUM")
			ret = num(input);
		else if (cmd == "POP")
			ret = pop();
		else if (cmd == "INV")
			ret = inv();
		else if (cmd == "DUP")
			ret = dup();
		else if (cmd == "SWP")
			ret = swp();
		else if (cmd == "ADD")
			ret = add();
		else if (cmd == "SUB")
			ret = sub();
		else if (cmd == "MUL")
			ret = mul();
		else if (cmd == "DIV")
			ret = div();
		else if (cmd == "MOD")
			ret = mod();
		if (ret == -1)
			return ret;
	}
	return ret;
}

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	string cmd = "";
	ll input, a,b, ret, n;
	int flag = 1;
	while (1)
	{
		if (flag)
		{
			cin >> cmd;
			if (cmd == "QUIT")
				break;
			else if (cmd == "END")
			{
				flag = 0;
				continue;
			}
			else if (cmd == "NUM")
			{
				cin >> input;
				program.push_back({ cmd, input });
			}
			else
				program.push_back({ cmd, 0 });
		}
		else
		{
			cin >> n;
			for (int i = 0; i < n; i++)
			{
				cin >> input;
				s.push(input);
				ret = run();
				if (s.size() != 1 || ret == -1)
				{
					//cout << "stack size : " << s.size() << endl;
					cout << "ERROR\n";
				}
				else
					cout << s.top() << "\n";
				while (!s.empty())
					s.pop();
			}
			flag = 1;
			program.clear();
			cout << "\n";
		}
	}
	return 0;
}
