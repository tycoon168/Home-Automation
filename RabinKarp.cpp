#include<bits/stdc++.h>
using namespace std;
int mod=100000;
int main()
{
        string t,p;
        cin>>t>>p;
        int n,m;
        n=t.length();
        m=p.length();
        long long int d=1;
        long long int hashval=0,save=0,cnt=0;
        for(int i=m-1;i>=0;i--)
        {
                hashval=(hashval+(t[i]-'a'+1)*d)%mod;
                save=(save+(p[i]-'a'+1)*d)%mod;

                if(i)
                    d=(d*26)%mod;
        }
        for(int i=0;i<=n-m;i++)
        {
                if(i!=0)
                {
                        hashval=(((hashval-((t[i-1]-'a'+1)*d)%mod+mod)%mod)*26)%mod+t[i+m-1]-'a'+1;
                        hashval=(hashval+mod)%mod;
                }
                if(hashval==save)
                {
                        bool flag=1;
                        for(int j=0;j<m;j++)
                            if(p[j]!=t[j+i])
                                flag=0;
                        if(flag)
                            cnt++;
                }
        }
        cout<<cnt;
}
