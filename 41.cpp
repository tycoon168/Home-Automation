#include<bits/stdc++.h>
using namespace std;
#define ll unsigned long long
#define mkp make_pair
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define pii pair<int,int>
#define pb push_back
#define F first
#define S second
#define mi map<int,int>
#define mii map<pii,int>
const int N=(1e6+1),mod=(1e9)+7;
int n;//k,m,p;//
string s;
int flag=1;
map<string,int> mp;
ll fact[N];
void factorial(int n)
{
	fact[0]=1;
	for(int i=1;i<=n;i++)
		fact[i]=(fact[i-1]*i)%mod;
}
ll powermod(ll x,ll y)
{
	x=x%mod;
	ll res=1;
	while (y)
	{
		if (y&1)
			res=(res*x)%mod;
		x=(x*x)%mod;
		y>>=1;
	}
	return res;
}
int main()
{
	fast;
	cin>>n;
	factorial(n);
	string s;
	for(int i=0;i<n;i++)
	{
		cin>>s;mp[s]++;
	}
	ll d=1;
	for(auto it:mp)
	{
		int t=it.S;
		d=(d*fact[t])%mod;
	}
	ll ans=powermod(d,mod-2);
	ans=(ans*fact[n])%mod;
	cout<<ans<<endl;
}
