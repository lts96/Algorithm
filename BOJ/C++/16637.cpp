#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;
int ans = -2147483648, n, cnt;
char arr[100];

// 백준 괄호 추가하기 문제 
// 브루트포스로 괄호를 넣을 수 있는 모든 경우를 탐색
// 그리고 나온 계산식을 큐나 스택쓰면서 계산해주면 끝 
// 주의할 점은 정답이 음수가 나올 수 있기 때문에 ans의 최저값을 가장 작은 int값으로 해야한다 

void print()
{
	for (int i = 0; i < 2 * n + 1; i++)
		cout << arr[i];
	cout << endl;
	return;
}

// 괄호 내부 계산용 
int cal(int s, int d)
{
	queue <int> a;
	queue <char> b;
	for (int i = s; i < d; i++)
	{
		if (arr[i] >= '0' && arr[i] <= '9')
			a.push(arr[i] - '0');
		else if (arr[i] == '+' || arr[i] == '-' || arr[i] == '*')
			b.push(arr[i]);
	}
	char op;
	int temp, result = a.front();
	a.pop();
	while (!b.empty() && !a.empty())
	{
		op = b.front();
		b.pop();
		temp = a.front();
		if (op == '+')
			result += temp;
		else if (op == '-')
			result -= temp;
		else if (op == '*')
			result *= temp;
		a.pop();
	}
	while (!a.empty())
		a.pop();
	return result;
}
// 완전탐색하면서 괄호 씌우는 함수 
void searchAll(int idx)
{
	int d;
	if (idx >= 2 * n + 1)
	{
		//print();
		queue <int> a;
		queue <char> b;
		for (int i = 0; i < 2 * n + 1; i++)
		{
			if (arr[i] == '+' || arr[i] == '-' || arr[i] == '*')
			{
				b.push(arr[i]);
				continue;
			}
			if (arr[i + 1] != ' ' && arr[i] != '(')
			{
				if (arr[i + 1] >= '0' && arr[i + 1] <= '9')
					a.push(arr[i + 1] - '0');
			}
			else if (arr[i] == '(')
			{
				for (int j = i + 2; j < 2 * n + 1; j+=2)
				{
					if (arr[j] == ')')
					{
						d = j;
						break;
					}
				}
				a.push(cal(i,d));
				//cout << i << " " << d <<" " << a.back() << endl;
				i = d;
			}
		}
		char op;
		int temp, result = a.front();
		//cout << "a size : " << a.size() << " b size :" << b.size() << endl;
		a.pop();
		while (!b.empty() && !a.empty())
		{
			op = b.front();
			b.pop();
			temp = a.front();
			if (op == '+')
				result += temp;
			else if (op == '-')
				result -= temp;
			else if (op == '*')
				result *= temp;
			a.pop();
		}
		//cout << result << endl;
		while (!a.empty())
			a.pop();
		ans = max(ans, result);
		return;
	}
	arr[idx] = '(';
	if (arr[idx + 6] == ' ' && idx + 6 < 2 *n + 1)
	{
		arr[idx + 6] = ')';
		searchAll(idx + 8);
		arr[idx + 6] = ' ';
	}
	arr[idx] = ' ';
	searchAll(idx + 4);
	return;
}

int main(void)
{
	cin >> n;
	for (int i = 0; i < 100; i++)
		arr[i] = ' ';
	for (int i = 0; i < n; i++)
		cin >> arr[2 * i + 1];
	searchAll(0);
	cout << ans << endl;
	return 0;
}
