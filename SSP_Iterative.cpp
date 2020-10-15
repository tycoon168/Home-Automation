#include<iostream>
#include<vector>
#include<stack>
using namespace std;
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
	vector<vector<bool> > ans(n+1,vector<bool> (amt+1,0));
	ans[0][0]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=amt;j++)
		{
			if(j==0)
				ans[i][j]=1;
			else 
			{
				if(j>=arr[i])
					ans[i][j]=ans[i-1][j]|ans[i-1][j-arr[i]];
				else ans[i][j]=ans[i-1][j];
			}
		}
	}
	if(ans[n][amt])
	{
		cout<<endl<<endl<<"GIVEN AMOUNT CAN BE FORMED FROM A SUBSET OF ARRAY ";
		cout<<endl<<endl<<"REQURIED SUBSET IS  :  ";
		int i=n,j=amt;
		stack<int> st;
		while(i&&j)
		{
			if(ans[i][j]!=ans[i-1][j])
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
