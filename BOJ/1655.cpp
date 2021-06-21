#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>
#include <math.h>
#include <string>
using namespace std;
priority_queue< int, vector<int>, less<int> > max_heap;
priority_queue< int, vector<int>, greater<int> > min_heap;
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n , input;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> input;
		if (max_heap.size() <= min_heap.size())
		{
			if (!min_heap.empty() && (min_heap.top() < input))
			{
				int temp = min_heap.top();
				min_heap.pop();
				min_heap.push(input);
				max_heap.push(temp);
			}
			else
				max_heap.push(input);
		}
		else if (max_heap.size() > min_heap.size())
		{
			if (max_heap.top() > input)
			{
				int temp = max_heap.top();
				max_heap.pop();
				max_heap.push(input);
				min_heap.push(temp);
			}
			else if (max_heap.top() <= input)
				min_heap.push(input);
		}
		cout << max_heap.top() << "\n";
	}
	//system("pause");
	return 0;
}