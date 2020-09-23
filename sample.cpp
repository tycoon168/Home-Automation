#include<bits/stdc++.h>
using namespace std;
bool flag;
int ans;
pair<int,int> dfs(int i,vector<int> arr[],vector<bool> &mark)
{
	if(mark[i]==0)
	{
		pair<int,int> t1,t2;
		t1=dfs(arr[i][0],arr,mark);
		t2=dfs(arr[i][1],arr,mark);
		if(t2.first>t1.second)
			return make_pair(min(t1.first,t2.first),max(t1.second,t2.second));
		if(t2.second<t1.first)
			ans++;
		else flag=0;
		return make_pair(min(t1.first,t2.first),max(t1.second,t2.second));
	}
	else 
		return make_pair(arr[i][0],arr[i][0]);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t,n,l,r;
	cin>>t;
	while(t--)
	{
		flag=1;
		ans=0;
		cin>>n;
		vector<int> arr[n+1];
		vector<bool> mark(n+1,0);
		for(int i=1;i<=n;i++)
		{
			cin>>l>>r;
			if(l==-1)
			{
				mark[i]=1;
				arr[i].push_back(r);
			}
			else 
			{
				arr[i].push_back(l);
				arr[i].push_back(r);
			}
		}
		pair<int,int> p=dfs(1,arr,mark);
		if(flag)
			cout<<ans;
		else cout<<-1;
		cout<<endl;
	}
}
