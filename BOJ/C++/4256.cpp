#include <iostream> 
#include <queue>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;
int n;
int preorder[1001];
int inorder[1001];
void findRoot(int idx, int s, int d)
{
	int index = 0;
	int target = preorder[idx];
	if (idx > n)
		return;
	if (!(s < d))
		return;
	for (int i = s; i < d; i++)
	{
		if (target == inorder[i])
			index = i;
	}
	findRoot(idx+1,s, index);
	findRoot(idx + index - s + 1, index+1,d);
	cout << target << " ";
	return;
}
int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int test;
	cin >> test;
	for (int t = 0; t < test; t++)
	{
		cin >> n; 
		for (int i = 0; i <= 1000; i++)
			preorder[i] = inorder[i] = 0;
		for (int i = 0; i < n; i++)
			cin >> preorder[i];
		for (int i = 0; i < n; i++)
			cin >> inorder[i];
		findRoot(0, 0, n);
		cout << "\n";
	}
	return 0;
}