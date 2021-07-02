#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <vector>
#pragma warning(disable:4996)
using namespace std;
bool primeNum[246912+2];
int main(void)
{
	
	for (int i = 0; i < 246912 + 2; i++)
	{
		primeNum[i] = true;
	}
	primeNum[1] = false;
	for (int i = 2; i * i <= 246912; i++)
	{
		if (primeNum[i])
		{
			for (int j = i * 2; j <= 246912; j += i)
			{
				primeNum[j] = false;
			}
		}
	}
	while (1)
	{
        int n;
		cin >> n;
        if(n==0)
            break;
		int count = 0;

		for (int i = n+1; i <= 2 * n; i++)
		{
			if (primeNum[i])
				count++;
		}
		cout << count << endl;
	}
	return 0;
}