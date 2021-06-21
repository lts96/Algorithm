#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <string>
#include <algorithm>

using namespace std;
int n;
int arr[200002];
int root = 1;
int p = root;
vector<int> ans;

void insert(int n)
{
	arr[p] = n;
	if (p == root)
	{
		p++;
		return;
	}
	int index = p;
	while (index != root) // 올라가면서 체크 
	{
		if (arr[index] > arr[index / 2])
		{
			int temp = arr[index / 2];
			arr[index / 2] = arr[index];
			arr[index] = temp;
			index = index / 2;
		}
		else
			break;
	}
	p++;
}
void del()
{
	if (p == root)
	{
		ans.push_back(0);
	}
	else
	{
		ans.push_back(arr[root]);
		arr[root] = arr[p-1];
		arr[p-1] = 0;
		bool flag = false;
		int index = root;
		for (int index = root; index * 2 <= p;)
		{
			int left = index * 2;
			int right = index * 2 + 1;
			if (arr[index] > arr[left] && arr[index] > arr[right])
				break;
			else
			{
				if (arr[right] < arr[left])
				{
					int temp = arr[left];
					arr[left] = arr[index];
					arr[index] = temp;
					index = index * 2;
				}
				else
				{
				
					int temp = arr[right];
					arr[right] = arr[index];
					arr[index] = temp;
					index = index * 2 + 1;
					
				}
			}
		}
		p--;
	}
}
int main()
{
	scanf("%d", &n);
	int cmd;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &cmd);
		if (cmd > 0)
			insert(cmd);
		else if (cmd == 0)
			del();
	}


	for (int i = 0; i < ans.size(); i++)
	{
		printf("%d\n", ans[i]);
	}
	return 0;
}