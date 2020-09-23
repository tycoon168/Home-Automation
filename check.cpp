#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
	int arr[5];
	for(int i=0;i<5;i++)
		cin>>arr[i];
	cout<<endl<<endl;
	int *p=arr;
	p--;
}
