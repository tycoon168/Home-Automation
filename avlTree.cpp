#include<iostream>
#include<math.h>
#include<string>
#include<conio.h>
using namespace std;
int main()
{
      int n;
      string arr="1578";
      cin>>n;
      long long int x=4*((pow(4,n)-1)/3);
      string s="";
      int len;
      //cout<<endl<<x;
      for(long long int i=0;i<x;i++)
      {
             s="";
             if(i==0)
                len=1;
            else
                len=((int)(log2(i)))/2+1;
            for(int j=1;j<=len;j++)
            {
                    if(len==1)
                         s=s+arr[i];
                    else
                    {
                            long long int store=i;
                            long long int div=pow(4,len-j);
                            int box=store/div;
                            if(j==1)
                                s=s+arr[box-1];
                            else
                                 s=s+arr[box-4*(box/4)];
                    }
           }
           cout<<s<<endl;
      }
}

