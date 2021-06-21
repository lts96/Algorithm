#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;
int n;
int ans;
vector <pair <long long, long long> > v;
int main(void)
{
	cin >> n;
	long long a, b;
	long long start=0,end;
	
	for (int i = 0; i < n; i++)
	{
		cin >> b;
		cin >> a;
		v.push_back(pair<long long, long long >(a, b)); 
	}
	sort(v.begin(), v.end());
	vector <pair <long long, long long> > ::iterator iter;
	/*
	for (iter = v.begin();iter!=v.end();iter++)
	{
		cout << iter->first << "," << iter->second << endl;
	}
	*/
	//end = v.back->first; 
	for (iter = v.begin(); iter != v.end(); iter++)
	{
		if (start <= iter->second)
		{
			ans++;
			start = iter->first;
		}
	}
	
	cout << ans; 
	//system("pause"); 
	return 0;
}