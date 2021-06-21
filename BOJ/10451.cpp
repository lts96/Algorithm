#include <iostream>
#include <stdlib.h>

using namespace std;  // n은 2부터 1000까지 
int n; 
int test;
int *ans , *arr;
int ans_index;
bool *visit;
double dfs(int compare, int value) // 무한루프 ?
{
	if (compare == arr[value-1])
	{
		ans[ans_index]++;
		visit[value - 1] = true;
		return 0.1;
	}
	visit[value-1]= true;
	dfs(compare, arr[value - 1]);
}
void find_cycle()
{
	for (int i = 0; i < n; i++)
	{
		if (i + 1 == arr[i])
		{
			ans[ans_index]++;
			visit[i] = true;
		}
		else
		{
			if (visit[i] == false)
				dfs(i + 1, arr[i]);
		}
	}
}
int main(void)
{
	cin >> test;
	ans = (int *)malloc(sizeof(int)*test); 
	for (int i = 0; i < test; i++)
	{
		cin >> n; 
		ans[i] = 0;
		arr = (int *)malloc(sizeof(int)*n);
		visit = (bool *)malloc(sizeof(bool)*n);
		for (int j = 0; j < n; j++)
		{
			cin >> arr[j]; 
			visit[j] = false;
		}
		find_cycle();
		ans_index++;
	}

	for (int i = 0; i < test; i++)
		cout << ans[i] << "\n"; 
	/*
	for (int i = 0; i < n; i++)
		cout << visit[i];
	system("pause");
	*/
	return 0; 
}