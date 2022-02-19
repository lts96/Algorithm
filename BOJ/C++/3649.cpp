#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <utility>
#include <stack>
#include <queue>
using namespace std;
vector <int> arr;
// 계속 틀렸던 이유 : 입출력 실수 + (n < 2)일때 에러메세지를 2번 출력해버림 
// 로직 자체는 간단 => 투 포인터 사용하면 막대기가 중복되는 상황 없이 절댓값이 제일 큰 경우 출력가능 

int main(void)
{
	ios_base::sync_with_stdio(false);  cin.tie(NULL); cout.tie(NULL);
	int x;
	while (1)
	{
		if (cin >> x)
		{
			x *= 10000000;
			int n, input;
			cin >> n;
			arr.clear();
			for (int i = 0; i < n; i++)
			{
				cin >> input;
				arr.push_back(input);
			}
			sort(arr.begin(), arr.end());
			int left = 0;
			int right = arr.size() - 1;
			bool flag = false;
			int temp;
			while (left < right)
			{
				temp = arr[left] + arr[right];
				if (temp == x)
				{
					flag = true;
					cout << "yes " << arr[left] << " " << arr[right] << "\n";
					break;
				}
				else if (temp < x)
					left++;
				else
					right--;
			}
			if (!flag)
				cout << "danger\n";
		}
		else
			break;
	} 
	return 0;
}
