#include <iostream>
#include <stdio.h>
using namespace std;
int n,ans=0;
void push_button(bool* note, bool* button , int i) 
{
	if(note[i]!=button[i])
	{
		if(i>=0&&i<= n-1)
		{
			button[i] = !button[i];
			if(i+1<=n-1)
			button[i+1] =!button[i+1];
			if(i+2<=n-1)
			button[i+2] =!button[i+2];
			ans++;
		}
		push_button(note,button,i+1);
		return;	
	}
	if(note[i]==button[i]&&i<n-1)
	push_button(note,button,i+1);
	return;
}
int main(int argc, char** argv) 
{
	cin>>n;
	bool button[n];
	bool note[n];
	int start_index=0;
	for(int i=0;i<n;i++)
	{
		cin>>note[i];
		button[i]= false;	
	}
	for(int i=0;i<n;i++)
	{
		if(note[i]!=button[i])
		{
			start_index=i;	
			break;
		}	
	}
	push_button(note,button,start_index);
	cout << ans <<endl ;
	return 0;
}