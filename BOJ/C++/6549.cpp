#include<iostream>
#include<stdlib.h>
#include<math.h>
#include<algorithm>
using namespace std;
unsigned long long ans;
int n;
unsigned long long  *arr;

unsigned long long divide(int left , int right)
{
	if (left == right)
	{
		return arr[left]; 
	}
	int mid = (left + right) / 2;
	// 왼쪽 오른쪽 중에서 더 큰 값 가져오기 
	unsigned long long ret = max(divide(left, mid), divide(mid + 1, right));
	// 중간에 걸친 경우 
	int a = mid, b = mid + 1;
	unsigned long long height = min(arr[a], arr[b]);
	// 앞에서 구한 값과 중간에 걸친 것중 큰거 선택
	if (ret < height * 2)
		ret = height * 2;
	while (left < a || b < right)
	{
		// 높이가 높아지는 방향으로 확장 
		if (b < right && (a == left || arr[a - 1] < arr[b + 1]))
		{
			b++; 
			height = min(height, arr[b]);
		}
		else
		{
			a--;
			height = min(height, arr[a]);
		}
		if (ret < height * (b - a + 1))
			ret = height * (b - a + 1);
	}
	return ret;
}


int main(void)
{
	int n = 1; 
	while (n != 0)
	{
		cin >> n;
		if (n == 0)
			break;
		arr = new unsigned long long [n];
		for (int i = 0; i < n; i++)
		{
			cin >> arr[i];
		}
		ans = divide(0, n-1);
		cout << ans << endl;
	}
	
	//system("pause");
	return 0;
}