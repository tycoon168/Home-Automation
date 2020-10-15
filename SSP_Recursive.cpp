#include<iostream>
#include<vector>
#include<stack>
using namespace std;
bool dp(int i,int j,vector<vector<bool> > &memo,vector<vector<bool> > &sign,vector<int> &arr)
{
	if(sign[i][j])
		return memo[i][j];
	bool var;
	if(i==0)
		var=0;
	else if(j==0)
		var=1;
	else 
	{
		if(j>=arr[i])
			var=dp(i-1,j,memo,sign,arr)|dp(i-1,j-arr[i],memo,sign,arr);
		else var=dp(i-1,j,memo,sign,arr);
	}
	memo[i][j]=var;
	sign[i][j]=1;
	return memo[i][j];
}
int main()
{
	int n,amt;
	cout<<endl<<"ENTER THE SIZE OF THE ARRAY  :  ";
	cin>>n;
	vector<int> arr(n+1);
	cout<<endl<<endl<<"ENTER THE ELEMENTS OF THE ARRAY  :  ";
	for(int i=1;i<=n;i++)
		cin>>arr[i];
	cout<<endl<<endl<<"ENTER THE TOTAL AMOUNT  :  ";
	cin>>amt;
	vector<vector<bool> > memo(n+1,vector<bool> (amt+1,0));
	vector<vector<bool> > sign(n+1,vector<bool> (amt+1,0));
	memo[0][0]=1;
	sign[0][0]=1;
	if(dp(n,amt,memo,sign,arr))
	{
		cout<<endl<<endl<<"GIVEN AMOUNT CAN BE FORMED FROM A SUBSET OF ARRAY ";
		cout<<endl<<endl<<"REQURIED SUBSET IS  :  ";
		int i=n,j=amt;
		stack<int> st;
		while(i&&j)
		{
			bool a=dp(i,j,memo,sign,arr);
			bool b=dp(i-1,j,memo,sign,arr);
			if(a!=b)
			{
				st.push(arr[i]);
				j-=arr[i];
			}
			i--;
		}
		while(!st.empty())
		{
			cout<<st.top()<<" ";
			st.pop();
		}
	}
	else 
		cout<<endl<<endl<<"GIVEN AMOUNT CAN'T BE FORMED FROM ANY SUBSET OF ARRAY ";
}
