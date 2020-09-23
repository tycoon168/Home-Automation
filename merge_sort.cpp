#include<iostream>
using namespace std;
void merge(int arr[],int start,int mid,int end)
{
	int temparr[100000];
	int i=start,j=mid,k;
	for(k=start;k<end;k++)
	{
		    if(j==end||i==mid)
		       break;
		    else
	         {
	       	      if(arr[i]<arr[j])
	       	            {
					     temparr[k]=arr[i];
					     i++;
				    	}
			      else
				    {
					     temparr[k]=arr[j];
					     j++;
				    }
		   }
	}
	if(i!=mid||j!=end)
	{
		 if(i==mid)
		  for(int var=k;(var<end)/*&&j<end*/;var++)
		     {
			    temparr[var]=arr[j];
			     j++;
	         }
	     else if(j==end)
	       for(int var=k;(var<end)/*&&i<mid*/;var++)
	         {
	         	temparr[var]=arr[i];
	         	i++;
			 }
	}
	for(int p=start;p<end;p++)
	  arr[p]=temparr[p];
}
void mergesort(int arr[],int start,int end)
{
	int mid=(end+start)/2+(end-start)%2;
	if((end-start)>=2)
	{
	      mergesort(arr,start,mid);
	      mergesort(arr,mid,end);
    }
	merge(arr,start,mid,end);
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
	mergesort(arr,0,n);
	cout<<endl<<endl<<"ARRAY AFTER SORTING   :   ";
	for(int i=0;i<n;i++)
	  cout<<arr[i]<<"  ";
}


