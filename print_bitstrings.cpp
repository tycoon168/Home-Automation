#include<iostream>  //ques 2
using namespace std;
long long int fact(int n)
{
	if(n==0)
	  return 1;
	 long long int product=1;
	 while(n)
	    {  product*=n;
	       n--;
    	}
    return product;
}
long long int combination(int n,int r)
{
     long long int num=fact(n);
     long long int rem=fact(n-r)*fact(r);
     return num/rem;
}
int main()
{
	 int m,w;
	 cout<<endl<<"ENTER THE NO OF MATCHES TO BE PLAYED  :   ";
	 cin>>m;
	 cout<<endl<<endl<<"ENTER THE MINIMUM NO OF WINS REQUIRED TO GET QUALIFIED  :   ";
	 cin>>w;
	 cout<<endl<<endl<<"TOTAL POSSIBLE WAYS ARE  :   "<<2*combination(m,w);
}
