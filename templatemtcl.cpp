#include<iostream>
using namespace std;

void m1(X a,X b)
{
     if(a>b)
        cout<<a;
     else
        cout<<b;
}
template <class X>
class sample
{
private:
      X   a;
      X   b;
public :
      void getdata(X x,X y)
      {
             a=x;
             b=y;
      }
      void findmax()
      {
          if(a>b)
            cout<<endl<<a;
          else
            cout<<endl<<b;
      }
};
int main()
{
    sample <int> s;
    //m1(4,7);
    s.getdata(4,7);
    s.findmax();
}
