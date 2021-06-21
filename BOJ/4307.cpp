#include <iostream>
#include <stdlib.h>
using namespace std; 
int test; 
int num;
int length; 
int *ant;
int *longest, *shortest;
int main(void)
{
	float half;
	float temp;
	int mid;
	cin >> test; 
	longest = (int*)malloc(sizeof(int)*test);
	shortest = (int*)malloc(sizeof(int)*test);
	for (int i = 0; i < test; i++)
	{
		int low = 10000000;
		cin >> length;
		cin >> num;
		ant = (int*)malloc(sizeof(int)*num);
		for (int j = 0; j < num; j++)
		{
			cin >> ant[j]; 
		}
		half = length / 2;
		temp = half;
		for (int k = 0; k < num; k++)
		{
			if (abs(half - ant[k]) < temp)
			{
				temp = abs(half - ant[k]); 
				mid = k;
			}
			if (ant[k] >= half)
			{
				if (low > length - ant[k])
				{
					low = length - ant[k];
				}
			}
			if (ant[k] < half)
			{
				if (low > ant[k])
				{
					low = ant[k];
				}
			}
		}
		if (ant[mid] >= half)
		{
			shortest[i] = length - ant[mid]; 
		}
		else
		{
			shortest[i] = ant[mid];
		}
		longest[i] = length - low;
		
		
	}
	for (int i = 0; i < test; i++)
	{
		cout << shortest[i] << " " << longest[i] << endl;
	}
	//system("pause"); 
	return 0; 
}