#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>
#include <math.h>
using namespace std;

struct num {
	int value;
	bool flag;
};
struct cmp {         // pq를 커스터마이징 , 부등호 방향 주의 
	bool operator()(num a, num b)
	{
		if (abs(a.value) != abs(b.value))
			return abs(a.value) > abs(b.value);
		else
		{
			return a.value > b.value;
		}
	}
};
vector <int> ans;
priority_queue< num , vector<num> , cmp> pq;
int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n , cmd;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> cmd; 
		if (cmd != 0)
		{
			num input;
			input.value = cmd;
			if (cmd > 0)
				input.flag = true;
			else
			{
				input.flag = false;
			}
			pq.push(input);
		}
		else
		{
			if (pq.empty())
				ans.push_back(0);
			else
			{
				num temp = pq.top();
				
				pq.pop();
				ans.push_back(temp.value);
			}
		}
	}
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << "\n";
	return 0;
}