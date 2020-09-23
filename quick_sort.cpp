#include<iostream>
using namespace std;
void swap(int &a,int &b)
{
	int temp=a;
	a=b;
	b=temp;
}
void quicksort(int arr[],int start,int end)
{
	if(start<end)
	{
	 int loc=start;
	 int right=end;
	 int flag=0;
	 while(loc!=right)
	 {
	    if(flag==0)
	    {
	         if(arr[loc]<=arr[right])
	           right--;
	         else 
	         {
	    		swap(arr[loc],arr[right]);
	    		flag=1;
	    		swap(loc,right);
			 }
		}
	   else
	   {
	 	 	if(arr[right]<arr[loc])
	 	    	right++;
	 	 	else
	 	 	{
	 			swap(arr[loc],arr[right]);
	 			flag=0;
	 			swap(loc,right);
		 	}
	 	}	 
	}
	quicksort(arr,start,loc-1);
	quicksort(arr,loc+1,end);
   }
}
int main()
{
	int n;
	cout<<"ENTER THE SIZE OF THE ARRAY  :   ";
	cin>>n;
	int arr[n];
	cout<<endl<<endl<<"ENTER THE ELEMENTS IN IT  :   ";
	for(int i=0;i<n;i++)
	 cin>>arr[i];
	cout<<endl<<endl<<"ARRAY BEFORE SORTING   :   ";
	for(int i=0;i<n;i++)
	  cout<<arr[i]<<"  ";
	quicksort(arr,0,n-1);
	cout<<endl<<endl<<"ARRAY AFTER SORTING   :   ";
	for(int i=0;i<n;i++)
	  cout<<arr[i]<<"  ";
}


