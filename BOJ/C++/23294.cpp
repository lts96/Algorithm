#include <iostream> 
#include <queue>
#include <utility>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
using namespace std;
#define MAX 2001
deque <pair <int, int>> b;
deque <pair <int, int>> f;
int cap[MAX];
int n,q,c, cache, curr = -1;
void back()
{
	if (b.empty())
		return;
	f.push_back({ curr, cap[curr] });
	curr = b.front().first;
	b.pop_front();
}
void front()
{
	if (f.empty())
		return;
	b.push_front({ curr, cap[curr] });
	curr = f.back().first;
	f.pop_back();
}
void compression() // 연속할 경우만 지워야함
{
	int s = b.size();
	int temp = -1;
	int top;
	for (int i = 0; i < s; i++)
	{
		top = b[i].first;
		if (top == temp)
			cache -= cap[temp];
		temp = top;
	}
	b.erase(unique(b.begin(), b.end()), b.end());
}
void access(int num)
{
	while (!f.empty())
	{
		cache -= f.front().second;
		f.pop_front();
	}
	if (curr != -1)
		b.push_front({ curr, cap[curr] });
	curr = num;
	cache += cap[curr];
	while (cache > c)
	{
		cache -= b.back().second;
		b.pop_back();
	}
}
int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> q >> c;
	for (int i = 0; i < n; i++)
		cin >> cap[i + 1];
	char cmd;
	int num;
	for (int i = 0; i < q; i++)
	{
		cin >> cmd;
		if (cmd == 'B')
			back();
		else if (cmd == 'F')
			front();
		else if (cmd == 'C')
			compression();
		else
		{
			cin >> num;
			access(num);
		}
		//cout <<i + 1 << " " << b.size() <<" " << curr << " " << cache << endl;
	}
	cout << curr << "\n";
	if (b.empty())
		cout << "-1\n";
	else
	{
		while (!b.empty())
		{
			cout << b.front().first << " ";
			b.pop_front();
		}
		cout << "\n";
	}
	if (f.empty())
		cout << "-1\n";
	else
	{
		while (!f.empty())
		{
			cout << f.back().first << " ";
			f.pop_back();
		}
		cout << "\n";
	}
	return 0;
}
