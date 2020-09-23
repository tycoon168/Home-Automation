#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b)
{
    if(b==0)
        return a;
    return gcd(b,a%b);
}
int main()
{
    int t,n,m,cnt;
    cin>>t;
    int pr[1000001];
    for(int i=0;i<1000001;i++)
        pr[i]=i;
    for(int i=2;i*i<1000001;i++)
    {
        if(pr[i]==i)
            for(int j=i*i;j<1000001;j+=i)
                if(pr[j]==j)
                    pr[j]=i;
    }
    while(t--)
    {
        cin>>n;
        int ans;
        vector<int> arr(n);
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
            if(i==0)
                ans=arr[0];
            else ans=gcd(ans,arr[i]);
        }
        map<int,int> mp[n],store;
        for(int i=0;i<n;i++)
        {
            int temp=arr[i]/ans;
            while(temp!=1)
            {
                mp[i][pr[temp]]++;
                temp/=pr[temp];
            }
            for(map<int,int>::iterator it=mp[i].begin();it!=mp[i].end();it++)
                store[it->first]++;
        }
        for(map<int,int>::iterator it=store.begin();it!=store.end();it++)
        {
            for(int i=0;i<n;i++)
            {
                if(mp[i].find(it->first)!=mp[i].end())
                {
                    while(mp[i][it->first]>=3)
                    {
                        mp[i][it->first]-=2;
                        store[it->first]++;
                        if(store[it->first]==n)
                        {
                            ans*=it->first;
                            for(int i=0;i<n;i++)
                            {
                                mp[i][it->first]--;
                                if(mp[i][it->first]!=0)
                                    store[it->first]++;
                            }
                        }
                    }
                }
            }
        }
        cout<<ans<<endl;
    }
}
