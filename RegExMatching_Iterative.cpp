#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main()
{
	string s1,s2;
	cout<<endl<<"ENTER THE PARENT STRING  :  ";
	cin>>s1;
	cout<<endl<<endl<<"ENTER THE TEST STRING  :  ";
	cin>>s2;
	int l1=s1.length();
	int l2=s2.length();
	vector<vector<bool> > ans(l1+1,vector<bool> (l2+1,0));
	ans[0][0]=1;
	for(int i=1;i<=l1;i++)
		if(s1[i-1]=='*')
			ans[i][0]=ans[i-2][0];
	for(int i=1;i<=l1;i++)
	{
		for(int j=1;j<=l2;j++)
		{
			if(s1[i-1]==s2[j-1]||s1[i-1]=='.')
				ans[i][j]=ans[i-1][j-1];
			else if(s1[i-1]=='*')
			{
				bool a=0,b=0;
				if(s1[i-2]==s2[j-1]||s1[i-2]=='.')
					a=ans[i][j-1];
				 b=ans[i-2][j];
				 ans[i][j]=a|b;
			}
			else ans[i][j]=0;
		}
	}
	if(ans[l1][l2])
		cout<<endl<<endl<<"TEST STRING IS THE CHILD OF THE PARENT STRING !!";
	else cout<<endl<<endl<<"TEST STRING IS NOT THE CHILD OF THE PARENT STRING !!";
	cout<<endl<<endl;
}
