#include<iostream>
#include<vector>
using namespace std;
long long dp(int i,vector<long long> &memo,vector<bool> &sign)
{
	if(sign[i])
		return memo[i];
	if(i<=1)
		return 1;
	memo[i]=dp(i-1,memo,sign)+dp(i-2,memo,sign);
	sign[i]=1;
	return memo[i];
}
int main()
{
	int n;
	cout<<endl<<"ENTER THE NO OF STAIRS  : ";
	cin>>n;
	vector<long long> memo(n+1);
	vector<bool> sign(n+1,0);
	cout<<endl<<endl<<"TOTAL NO OF WAYS TO REACH THE TOPMOST STAIR IS  :  "<<dp(n,memo,sign);
	cout<<endl<<endl;
}
