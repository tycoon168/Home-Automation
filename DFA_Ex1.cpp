#include<iostream>
#include<string>
using namespace std;
int len=0;
char dfa(char ch,string str)
{
	int temp;
	if(len!=str.length())
      temp=str[len++]-'0';
    if(ch=='A'&&temp==0)
        return dfa('B',str);
    else if(ch=='A'&&temp==1)
        return dfa('C',str);
    if(ch=='B')
        {
        	if(len==str.length())
        	  return 'B';
        	else 
        	  return dfa('B',str);
		}
    else if(ch=='C')
        {
        	if(len==str.length())
        	  return 'C';
        	else 
        	  return dfa('C',str);	  
    	}
} 
int main()
{
	string str;
	cin>>str;
	char s=dfa('A',str);
	if(s=='B')
	  cout<<endl<<"ACCEPTED!!";
	else if(s=='C')
	  cout<<endl<<"REJECTED!!";
}
