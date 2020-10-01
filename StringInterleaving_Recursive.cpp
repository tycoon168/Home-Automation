#include<iostream>
#include<vector>
#include<string>
using namespace std;
string s1,s2,s3;
bool dp(int i,int j,vector<vector<bool> > &memo,vector<vector<bool> > &sign)
{
	if(sign[i][j])
		return memo[i][j];
	if(i==0&&j==0)
		memo[i][j]=1;
	else if(i==0)
	{
		if(dp(i,j-1,memo,sign)&&s3[i+j-1]==s2[j-1])
			memo[i][j]=1;
		else memo[i][j]=0;
	}
	else if(j==0)
	{
		if(dp(i-1,j,memo,sign)&&s3[i+j-1]==s1[i-1])
			memo[i][j]=1;
		else memo[i][j]=0;
	}
	else
	 {
	 	if(dp(i,j-1,memo,sign)^dp(i-1,j,memo,sign))
	 	{
	 		if(dp(i,j-1,memo,sign))
	 		{
	 			if(s3[i+j-1]==s2[j-1])
	 				memo[i][j]=1;
	 			else memo[i][j]=0;
	 		}
	 		else 
	 		{
	 			if(s3[i+j-1]==s1[i-1])
					memo[i][j]=1;
				else memo[i][j]=0;
			}
		}
		else 
		{
			if(dp(i,j-1,memo,sign)&&dp(i-1,j,memo,sign)&&s3[i+j-1]==s1[i-1])
				memo[i][j]=1;
			else memo[i][j]=0;
		}
	}
	sign[i][j]=1;
	return memo[i][j];
}		
int main()
{
	cout<<endl<<"ENTER THE FIRST STRING  :  ";
	cin>>s1;
	cout<<endl<<endl<<"ENTER THE SECOND STRING  :  ";
	cin>>s2;
	cout<<endl<<endl<<"ENTER THE STRING TO BE CHECKED  :  ";
	cin>>s3;
	int l1=s1.length();
	int l2=s2.length();
	vector<vector<bool> > memo(l1+1,vector<bool> (l2+1));
	vector<vector<bool> > sign(l1+1,vector<bool> (l2+1,0));
	if(dp(l1,l2,memo,sign))
		cout<<endl<<endl<<"GIVEN STRING IS AN INTERLEAVING OF THE TWO STRINGS !!";
	else 
		cout<<endl<<endl<<"GIVEN STRING IS NOT AN INTERLEAVING OF THE TWO STRINGS !!";
	cout<<endl<<endl;
}
