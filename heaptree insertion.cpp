#include<iostream>
using namespace std;
int arr[2][10000]={0};
long int last=0;
void heapifyinsert(int pos)
{
	 if(pos%2==0&&pos>=2&&arr[0][(pos-2)/2]<arr[0][pos])
	 {
	 	int temp=arr[0][pos];
	 	arr[0][pos]=arr[0][(pos-2)/2];
	 	arr[0][(pos-2)/2]=temp;
	 	heapifyinsert((pos-2)/2);
	 }
	 else if(pos%2!=0&&pos>=1&&arr[0][pos/2]<arr[0][pos])
	 {
	 	 int temp=arr[0][pos];
	 	 arr[0][pos]=arr[0][pos/2];
	 	 arr[0][pos/2]=temp;
	 	 heapifyinsert(pos/2);
	 }
}
int max(int a,int b)
{
	return arr[0][a]>arr[0][b]?a:b;
}
void insert(int key)
{
	 arr[0][last]=key;
	 arr[1][last]=1;
	 heapifyinsert(last);
	 last++;
}
void heapifydelete(int pos)
{
	   if(!(arr[1][2*pos+1]==0&&arr[1][2*pos+2]==0))
	     {
	     	  if(arr[1][2*pos+1]==1&&arr[1][2*pos+2]==1)
	     	   {
				  int m=max(2*pos+1,2*pos+2);
				  if(arr[0][m]>arr[0][pos])
				  {
				  	     int temp=arr[0][pos];
				  	     arr[0][pos]=arr[0][m];
				  	     arr[0][m]=temp;
				  	     heapifydelete(m);
				  }
	           }
	           else
	           {
	           	   if(arr[1][2*pos+1]==0&&arr[0][2*pos+1]>arr[0][2*pos+2])
	           	   {
	           	   	     int temp=arr[0][pos];
				  	     arr[0][pos]=arr[0][2*pos+1];
				  	     arr[0][2*pos+1]=temp;
				   }
			   }
		 }
}
void deletion(int key)
{
	
	int i;
  if(last==0)
    cout<<endl<<endl<<"HEAP TREE IS EMPTY";
  else
   {
	for(i=0;i<last;i++)
	  {
	  	  if(arr[0][i]==key)
	  	  break;
	  }
	  if(i==last)
	    cout<<endl<<endl<<"ELEMENT NOT FOUND";
	  else 
	    {
	          arr[0][i]=arr[0][last-1];
	          last--;
	          arr[0][last]=0;
	          arr[1][last]=0;
	          if(i!=last)
	          heapifydelete(i);
		}
}
}
int main()
{
	int n,key;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cout<<endl<<"INSERT NODE VALUE  :  ";
		cin>>key;
		insert(key);
		cout<<endl<<endl<<"LEVEL ORDER TRAVERSAL OBTAINED  :  ";
		for(int j=0;j<last;j++)
		    cout<<arr[0][j]<<"  ";
	}
		cin>>n;
		 for(int j=0;j<n;j++)
		 {
		 	cin>>key;
		 	deletion(key);
		 	cout<<endl<<endl<<"LEVEL ORDER TRAVERSAL OBTAINED  :  ";
	     	for(int j=0;j<last;j++)
		    cout<<arr[0][j]<<"  ";
		 }
}
