#include<iostream>
#include<vector>
#include<tuple>
using namespace std;
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
	vector<vector<tuple<int,int,int> > > ans(n+1,vector<tuple<int,int,int> > (m+1,make_tuple(0,0,0)));
	int mx=0,storei,storej;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(arr[i-1][j-1]==0)
				ans[i][j]=make_tuple(0,0,0);
			else
			{
				if(get<0>(ans[i-1][j])==0)
					ans[i][j]=make_tuple(get<2>(ans[i][j-1])+1,1,get<2>(ans[i][j-1])+1);
				else if(get<0>(ans[i][j-1])==0)
					ans[i][j]=make_tuple(get<1>(ans[i-1][j])+1,get<1>(ans[i-1][j])+1,1);
				else
				{
					tuple<int,int,int> ans1,ans2;
					if(get<1>(ans[i-1][j])+1>=get<1>(ans[i][j-1]))
						ans1=make_tuple(get<0>(ans[i][j-1])+get<1>(ans[i][j-1]),get<1>(ans[i][j-1]),get<2>(ans[i][j-1])+1);
					else ans1=make_tuple((get<2>(ans[i][j-1])+1)*(get<1>(ans[i-1][j])+1),get<1>(ans[i-1][j])+1,get<2>(ans[i][j-1])+1);

					if(get<2>(ans[i][j-1])+1>=get<2>(ans[i-1][j]))
						ans2=make_tuple((get<1>(ans[i-1][j])+1)*get<2>(ans[i-1][j]),get<1>(ans[i-1][j])+1,get<2>(ans[i-1][j]));
					else	ans2=make_tuple((get<1>(ans[i-1][j])+1)*(get<2>(ans[i][j-1])+1),get<1>(ans[i-1][j])+1,get<2>(ans[i][j-1])+1);
					if(get<0>(ans1)>get<0>(ans2))
						ans[i][j]=ans1;
					else ans[i][j]=ans2;
				}
			}
			if(get<0>(ans[i][j])>mx)
			{
				mx=get<0>(ans[i][j]);
				storei=i-1;
				storej=j-1;
			}
		}
	}
	if(mx)
		cout<<endl<<endl<<"MAXIMUM SUBRECTANGLE OF ALL 1's IS  :  "<<mx<<"  WHICH IS  :   ("<<storei-get<1>(ans[storei+1][storej+1])+1<<","<<storej-get<2>(ans[storei+1][storej+1])+1<<")  --->  ("<<storei<<","<<storej<<")";
	else
		cout<<endl<<endl<<"ALL ELEMENTS OF THE MATRIX ARE 0 !!";
	cout<<endl<<endl;
}
