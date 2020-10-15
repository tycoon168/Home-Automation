#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main()
{
	string s1,s2,s3;
	cout<<endl<<"ENTER THE FIRST STRING  :  ";
	cin>>s1;
	cout<<endl<<endl<<"ENTER THE SECOND STRING  :  ";
	cin>>s2;
	cout<<endl<<endl<<"ENTER THE STRING TO BE CHECKED  :  ";
	cin>>s3;
	int l1=s1.length();
	int l2=s2.length();
	vector<vector<bool> > ans(l1+1,vector<bool> (l2+1));
	for(int i=0;i<=l1;i++)
	{
		for(int j=0;j<=l2;j++)
		{
			if(i==0&&j==0)
				ans[i][j]=1;
			else if(i==0)
			{
				if(ans[i][j-1]&&s3[i+j-1]==s2[j-1])
					ans[i][j]=1;
				else ans[i][j]=0;
			}
			else if(j==0)
			{
				if(ans[i-1][j]&&s3[i+j-1]==s1[i-1])
					ans[i][j]=1;
				else ans[i][j]=0;
			}
			else 
			{
				if(ans[i][j-1]^ans[i-1][j])
				{
					if(ans[i][j-1])
					{
						if(s3[i+j-1]==s2[j-1])
							ans[i][j]=1;
						else ans[i][j]=0;
					}
					else 
					{
						if(s3[i+j-1]==s1[i-1])
							ans[i][j]=1;
						else ans[i][j]=0;
					}
				}
				else 
				{
					if(ans[i][j-1]&&ans[i-1][j]&&s3[i+j-1]==s1[i-1])
						ans[i][j]=1;
					else ans[i][j]=0;
				}
			}
		}
	}
	if(ans[l1][l2])
		cout<<endl<<endl<<"GIVEN STRING IS AN INTERLEAVING OF THE TWO STRINGS !!";
	else 
		cout<<endl<<endl<<"GIVEN STRING IS NOT AN INTERLEAVING OF THE TWO STRINGS !!";
	cout<<endl<<endl;
}
