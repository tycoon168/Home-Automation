#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
vector<int> v[100001];
bool mark[100001]={0};
int co=0,croad,clib;
void dfs(int n,long long prev)
{
    mark[n]=1;
    if(prev>clib)
    { 
        co+=clib;
        prev=0;
    }
    else co+=croad;
    for(int i=0;i<v[n].size();i++)
    {
        if(!mark[v[n][i]])
            dfs(v[n][i],prev+croad);
    }
}
int main() {
    int q;
    cin>>q;
    while(q--)
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        int n,e,a,b;
        cin>>n>>e>>clib>>croad;
        for(int i=0;i<e;i++)
        {
            cin>>a>>b;
            v[a].push_back(b);
            v[b].push_back(a);
        }
        if(clib<=croad)
            cout<<clib*n;
        else 
        {
            for(int i=1;i<=n;i++)
            {
                if(!mark[i])
                    dfs(i,9999999999);
            }
            cout<<co;
            co=0;
        }
        cout<<endl;
        for(int i=1;i<=n;i++)
        {
            v[i].clear(); 
            mark[i]=0;
        }
    }
    return 0;
}

