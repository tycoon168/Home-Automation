#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int n;
	cout<<endl<<"ENTER THE NO OF STAIRS  :  ";
	cin>>n;
	vector<long long> ans(n+1,1);
	for(int i=2;i<=n;i++)
		ans[i]=ans[i-1]+ans[i-2];
	cout<<endl<<endl<<"TOTAL NO OF WAYS TO REACH TO THE TOPMOST STAIR IS  :  "<<ans[n]<<endl<<endl;
}
	
