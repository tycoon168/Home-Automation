#include<iostream>
#include<stack>
using namespace std;
int main()
{
	stack<int> s;
	int n,flag=0;
	cout<<endl<<endl<<"ENTER THE LENGTH OF THE SEQUENCE  :   ";
	cin>>n;
	int arr[n];
	int storei[n],stored[n];
	int leni[n],lend[n];
	for(int i=0;i<n;i++)
	  {
	     storei[i]=i;
	     leni[i]=1;
	     lend[i]=1;
	     stored[i]=i;
	  }
	cout<<endl<<endl<<"ENTER THE NUMBERS IN THE SEQUENCE   :   ";
	for(int i=0;i<n;i++)
	  cin>>arr[i];
	int maxleni=1,indexi=0;
	for(int i=0;i<n;i++)
	{		
	    flag=0;
		 for(int j=i-1;j>=0;j--)
		 {
		     if(arr[j]<arr[i])	
			    {  
			      if(flag==0)
			        {
					  storei[i]=j;
			          leni[i]=leni[j]+1;
			        }
			      else if(flag==1&&leni[i]<leni[j]+1)
				     {
					    storei[i]=j;
			            leni[i]=leni[j]+1;
			         }
			      flag=1;
				}
		 }
	  if(maxleni<leni[i])
	   {
	     maxleni=leni[i];
	     indexi=i;
	   }	
	}
	int showi=indexi;
	 while(1)
	 {
	 	s.push(arr[showi]);
	 	if(showi==storei[showi])
	 	break;
	 	showi=storei[showi];
	 }
	 cout<<endl<<endl<<"LONGEST INCREASING SUBSEQUENCE   :   ";
	 while(!s.empty())
	 {
	 	cout<<s.top()<<"  ";
	 	s.pop();
	 }
	int maxlend=1,indexd=n-1; 
	 for(int i=n-1;i>=0;i--)
	{		
	    flag=0;
		 for(int j=i+1;j<n;j++)
		 {
		     if(arr[j]<arr[i])	
			    {  
			      if(flag==0)
			        {
					  stored[i]=j;
			          lend[i]=lend[j]+1;
			        }
			      else if(flag==1&&lend[i]<lend[j]+1)
				     {
					    stored[i]=j;
			            lend[i]=lend[j]+1;
			         }
			      flag=1;
				}
		 }
	  if(maxlend<lend[i])
	   {
	     maxlend=lend[i];
	     indexd=i;
	   }	
	}
	int showd=indexd;
	cout<<endl<<endl<<"LONGEST DECREASING SUBSEQUENCE   :   ";
	 while(1)
	 {
	 	cout<<arr[showd]<<" ";
	 	if(showd==stored[showd])
	 	break;
	 	showd=stored[showd];
	 }
}
