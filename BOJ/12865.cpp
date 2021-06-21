#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <math.h>
#include <algorithm>;
using namespace std;
int n, k; 
int *weight, *value , **arr;
int ans;
int knapsack(int index , int capacity) // index는 물건의 번호 , capacity는 가방의 남은 용량
{
	if (index == n)
	{
		return 0;
	}
	int ret = arr[index][capacity];
	if (ret != -1)    // 이미 값이 존재하는 경우 리턴
	{
		return ret;
	}
	if (weight[index] <= capacity) // 가방에 물건을 담을 수 있을때
	{
		ret = knapsack(index + 1, capacity - weight[index]) + value[index];
	}
	ret = max(ret, knapsack(index + 1, capacity));
	return arr[index][capacity] = ret;
}
int main(void)
{
	cin >> n >> k;
	weight = new int[n];
	value = new int[n];
	arr = new int*[n];
	for (int i = 0; i < n; i++)
	{
		cin >> weight[i] >> value[i];
		arr[i] = new int[k+1];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < k+1; j++)
			arr[i][j] = -1;
	}
	ans = knapsack(0, k);
	cout << ans << endl;
	//for (int i = 0; i < n; i++)
	//{
		//for (int j = 0; j < k+1; j++)
			//cout << arr[i][j] << " ";
		//cout << endl;
	//}
	//system("pause");
	return 0;
}