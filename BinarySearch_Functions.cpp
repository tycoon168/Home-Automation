#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define mkp make_pair
#define pb push_back
#define loop(i,n)   for(ll i=0;i<n;i++)
#define rloop(i,n)  for(ll i=n-1;i>=0;i--)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);  cout.tie(NULL);
#define test int t; cin>>t; while(t--)
#define F first
#define S second
#define all(a) (a.begin(),a.end())
#define pi 3.14159265
 
ll simplebinsrch(vll arr,ll t)
{
	ll s=0,e=arr.size()-1,mid;
	while(s<=e)
	{
		mid=(s+e)/2;
		if(arr[mid]>t)
			e=mid-1;
		else if(arr[mid]<t)
			s=mid+1;
		else return mid;
	}
	return -1;
}

ll firstoccurance(vll arr,ll t)
{
	ll s=0,e=arr.size()-1,mid;
	while(s<e)
	{
		mid=(s+e)/2;
		if(arr[mid]>t)
			e=mid-1;
		else if(arr[mid]<t)
			s=mid+1;
		else e=mid;
	}
	if(s==e&&arr[e]==t)
		return e;
	return -1;
}

ll lastoccurance(vll arr,ll t)
{
	ll s=0,e=arr.size()-1,mid;
	while(s<=e)
	{
		if(s==e)
		{
			if(arr[s]==t)
				return s;
			return -1;
		}
		if(e==s+1)
		{
			if(arr[e]==t)
				return e;
			if(arr[s]==t)
				return s;
			return -1;
		}
		mid=(s+e)/2;
		if(arr[mid]<t)
			s=mid+1;
		else if(arr[mid]>t)
			e=mid-1;
		else s=mid;
	}
	return -1;
}

ll rotation(vll arr)
{
	ll n=arr.size();
	if(n==0)
		return -1;
	ll s=0,e=n-1,p=arr[e],mid;
	while(s<e)
	{
		mid=(s+e)/2;
		if(arr[mid]>p)
			s=mid+1;
		else
			e=mid;
	}
	return s;
}

ll sqroot(ll a)
{
	if(a<0)
		return -1;
	ll s=0,e=a,mid;
	while(s<=e)
	{
		if(s==e)
			return s;
		if(e==s+1)
		{
			if(e*e<=a)
				return e;
			return s;
		}
		mid=(s+e)/2;
		if(mid*mid>a)
			e=mid-1;
		else 
			s=mid;
	}
}

double sqrootd(ll a)
{
	double s=0,e=a,mid,p=1e-9;
	while(e-s>=p)
	{
		mid=(s+e)/2.0;
		if(mid*mid>a)
			e=mid;
		else s=mid;
	}
	return (s+e)/2.0;
}