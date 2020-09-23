#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
long int n;
bool mark[1000][1000]={false};
int getvalue[1000][1000]={0};
int ans(int fuel,int city,int a[])
{
    if(city==n-1)
        return 0;
    int value=0,flag=0;
    if(fuel==0)
    {
        fuel=a[city];
        flag=1;
        value++;
    }
     if(fuel>=n-1-city){
        return value;
    }
    int var=0,store=0;
    if (flag==0)
    {
         for(int i=1;i<=fuel;i++)
    {
          if(mark[fuel-i][city+i]==true)
            var=getvalue[fuel-i][city+i];
        else
          {
              var=ans(fuel-i,city+i,a);
              mark[fuel-i][city+i]=true;
              getvalue[fuel-i][city+i]=var;
          }
          if(i==1)
              store=var;
          else if(var<store)
              store=var;
    }
    }
    else if(flag==1)
    {
          for(int i=1;i<=fuel;i++)
    {
          if(mark[0][city+i]==true)
            var=getvalue[0][city+i];
        else
          {
              var=ans(0,city+i,a);
              mark[0][city+i]=true;
              getvalue[0][city+i]=var;
          }
          if(i==1)
              store=var;
          else if(var<store)
              store=var;
    }
    }

    return store+value;
}
int main() {
    cin>>n;
    int a[n-1];
    for(int i=0;i<n-1;i++)
        cin>>a[i];
    if(n==1)
        cout<<0;
    else
    cout<<ans(0,0,a);
    return 0;
}
