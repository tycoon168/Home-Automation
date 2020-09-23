#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int t,n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		long a,sum=0;
		vector<long> v;
		for(int i=0;i<n;i++)
		{
			cin>>a;
			sum+=a;
			v.push_back(a);
		}
		for(int i=1;i<=n;i++)
		{
			bool flag=0;
			
			if(sum%i==0)
			{
				long val=sum/i,temp=0,count=0,j;
				for(j=0;j<n;j++)
				{
					if(temp+v[j]<val)
						temp+=v[j];
					else if(temp+v[j]==val)
					{
						temp=0;
						count++;
					}
					else break;
				}
				if(j==n&&temp==val)
					count++;
				if(count==i)
					flag=1;
			}
			cout<<flag;
		}
		cout<<endl;
	}
}
