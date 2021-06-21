#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <algorithm>  //가방 문제 변형 
using namespace std; 
int day; 
int **arr;
int cache[16];
int ans; 
int consult(int limit)
{
	if (limit > day)
		return 0;
	else
	{
		int & ret = cache[limit];
		if (ret != 0)
			return ret; 
		ret = consult(limit+1);
		if (day + 1 >= limit + arr[limit][0])
		{
			ret = max(ret, consult(limit + arr[limit][0]) + arr[limit][1]);
		}
		return ret;
	}
}

int main(void)
{
	cin >> day; 
	arr = new int*[day+1];
	for (int i = 1; i <= day; i++)
	{
		arr[i] = new int[2];
		cin >> arr[i][0] >> arr[i][1];
	}
	
	consult(1);

	for (int i = 1; i <= 15; i++)
	{
		if (ans <= cache[i])
		{
			ans = cache[i];
		}
		//cout << cache[i] << endl;
	}

	cout << ans; 
	//system("pause");
	return 0;
}