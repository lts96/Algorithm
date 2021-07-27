#include <iostream> 
#include <queue>
#include <utility>
#include <vector>
#include <math.h>
#include <algorithm>
#include <string.h>
using namespace std;
int ans;
vector <int> arr;
// 문제는 간단하고 푸는 방식도 간단한데 왜 그렇게 되는지 
// 수학적으로 증명하고 확신을 가지는게 어려운 문제 
// 그리디. i까지 누적합이 arr[i+1]과 2차이 이상 나면 
// 누적합 Si + 1은 어떤 추로도 만들 수 없는 무게가 된다 
int main(void)
{
	int n, input;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> input;
		arr.push_back(input);
	}
	sort(arr.begin(), arr.end());
	int sum = 0;   // sum 까진 무게를 측정할 수 있다고 가정 
	for (int i = 0; i < n; i++)
	{
		if (sum + 2 <= arr[i])
			break;
		sum += arr[i];
	}
	// 조건에 안걸리고 다 더하고 나오게 되는 경우를 생각 안함 
	cout << sum + 1 << endl;
	return 0;
}
