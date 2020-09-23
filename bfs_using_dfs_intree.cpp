#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    int prev,curr,mx=INT_MIN;
    curr=arr[0];
    prev=0;
    for(int i=1;i<n;i++)
    {
        mx=max(arr[i]+prev,mx);

    }
}
