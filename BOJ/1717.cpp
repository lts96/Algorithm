#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;
int n,m;
int arr[1000001];

int find(int a)  // 거슬러 올라가면서 부모를 찾는다. 부모는 자기 자신을 값으로 가지고 있음
{
	if (arr[a] == a) 
		return a;
	else
		return arr[a] = find(arr[a]); // 이 부분을 처리 안해서 시간초과
	// -> path compression 이란 기법 (매우 중요)
	// 만약 5만번 합치고 마지막 노드를 5만번 동안 찾으면 50000 * 50000 (처리 안했을때)
}
void union_set(int a, int b)
{
	int root1 = find(a); 
	int root2 = find(b);

	arr[root2] = root1;
}
int main()
{
	scanf("%d %d", &n, &m);
	int cmd, a, b, result;
	for (int i = 1; i <= n; i++)  //초기화
		arr[i] = i;

	for (int i = 0; i < m; i++)
	{
		scanf("%d %d %d", &cmd,&a, &b);
		if (cmd)
		{
			if (find(a) == find(b))
				printf("YES\n");
			else
				printf("NO\n");
		}
		else
			union_set(a, b);
	}
	return 0;
}