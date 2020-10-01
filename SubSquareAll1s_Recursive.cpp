#include<iostream>
#include<vector>
using namespace std;
int dp(int i,int j,vector<vector<int> > &memo,vector<vector<bool> > &sign,vector<vector<int> > &arr)
{
	if(sign[i][j])
		return memo[i][j];
	if(i==0||j==0)
		return memo[i][j];
	if(arr[i-1][j-1]==0)
		memo[i][j]=0;
	else memo[i][j]=1+min(min(dp(i-1,j,memo,sign,arr),dp(i,j-1,memo,sign,arr)),dp(i-1,j-1,memo,sign,arr));
	sign[i][j]=1;
	return memo[i][j];
}
int main()
{
	int n,m;
	cout<<endl<<"ENTER THE ORDER OF THE MATRIX  :  ";
	cin>>n>>m;
	vector<vector<int> > arr(n,vector<int> (m));
	cout<<endl<<endl<<"ENTER THE CONTENTS OF THE MATRIX  :  \n";
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			cin>>arr[i][j];
	int mx=0,storei,storej;
	vector<vector<int> > memo(n+1,vector<int> (m+1,0));
	vector<vector<bool> > sign(n+1,vector<bool> (m+1,0));
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(dp(i,j,memo,sign,arr)>mx)
			{
				mx=dp(i,j,memo,sign,arr);
				storei=i-1;
				storej=j-1;
			}
	if(mx)
		cout<<endl<<endl<<"MAXIMUM SUBSQUARE OF ALL 1's IS  :  "<<mx<<"  WHICH IS  :   ("<<storei-mx+1<<","<<storej-mx+1<<")  --->  ("<<storei<<","<<storej<<")";
	else 
		cout<<endl<<endl<<"ALL ELEMENTS OF THE MATRIX ARE 0 !!";
	cout<<endl<<endl;
}
		
