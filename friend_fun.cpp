#include<iostream>
using namespace std;
class B;
class A
{
  private:
      int a,b;
  public:
      A(int x=0,int y=0)  : a(x),b(y) {}
      friend ostream & operator<<(ostream &,A);
      friend istream & operator>>(istream &,A &);
      void display()
  { cout<<endl<<"a  :  "<<a<<"  b  :  "<<b;
  }  
};
ostream & operator<<(ostream &k,A l)
{   
    k<<l.a<<l.b;
	return k;
}
istream & operator>>(istream &j,A &i)
{
	//cout<<i.a<<i.b;
	j>>i.a>>i.b;
	return j;
}

int main()
{
	A ob1(4,3);
	cout<<ob1<<endl;
	cin>>ob1;
    operator<<(cout,ob1);
}
    
