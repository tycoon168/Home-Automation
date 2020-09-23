/*#include<bits/stdc++.h>
using namespace std;

/*class complex{
    public: 
        int a,b;
    private:
        static int c;
    public: 
        complex(int x,int y)
        {
            a=x,b=y;
        }
        complex()
        {

        }
        void operator=(complex c)
        {
            a=c.a;
            b=c.b;
        }
        friend void operator++(complex &);
        friend void fun();
        ostream& operator<<(ostream &x)
        {
            x<<a+b<<endl;
            return x;
        }
        void add(int a,int b)
        {
            this->a=a;
            this->b=b;
            cout<<this->a<<" "<<this->b<<" "<<this<<endl;
        }
};
int complex::c;
void fun()
{
    cout<<"value of c : "<<(complex::c)<<endl;
}
void operator++(complex &c)
{
    c.a++,c.b++;
}
int main()
{
    complex c1,c2(3,4),c3=complex(c2);
    c1=c2; //c1.operator=(c2) operator=(c1,c2)
    //c1++ //c1.operator++(int) operator++(c1,int)
    cout.operator<<(c1.a+c1.b)<<endl;
    cout<<c2.a+c2.b<<endl;
    operator++(c2); //c2.operator-()
    c2<<cout;
    fun();
    complex *p=&c2;
    p->add(3,4);
    cout<<p<<endl;
}
class A{
    public :
        virtual void f1()
        {
            cout<<"A ka f1\n";
        }
};
class B: public A{
    public :
        void f1(int x)
        {
            cout<<"B ka f1 "<<x<<endl;
        }
};
int main()
{
    A a;
    B b;
    A *p=new B;
    a.f1();
    b.f1(4);
    p->f1();
}
class temp;
class complex{
    int a,b;
    public :
        complex(): a(5),b(10)
        {

        }
        complex(int a,int b=0)
        {
            this->a=a;
            this->b=b;
        }
        void show()
        {
            cout<<"a="<<a<<" b="<<b<<endl;
        }
        complex(complex &d)
        {
            a=d.a;
            b=d.b+1;
        }
        void setvalue(int a,int b)
        {
            this->a=a;
            this->b=b;
        }
};
class temp{
    int n,m;
    public :
        temp()
        {
            n=100,m=200;
        }
        void show()
        {
            cout<<"n="<<n<<" m="<<m<<endl;
        }
        operator complex()
        {
            complex temp;
            temp.setvalue(n,m);
            return temp;
        }
};
int main()
{
    temp t;
    complex c2(4,5),c1;
    c2.show();
    t.show();
    c1=t;
    c1.show();
    try{
        throw 10;
        cout<<"Hello\n";
    }
    catch(...)
    {
        cout<<"in catch\n";
    }
}
namespace myspace 
{
    int a;
    void fun()
    {
        cout<<"Hello\n";
    }
}
namespace ms=myspace;
using namespace ms;
int main()
{
    int a=10;
    a=5;
    cout<<ms::a<<endl;
    fun();
}
class sample
{
    private :
        int a,b;
        class example
        {
            int c;
            public : 
                example()
                {
                    c=10;
                }
                void show()
                {
                    cout<<"c="<<c<<endl;
                }
        };
        example e;
    public : 
        sample(): a(1),b(2)
        {}
        void showdata()
        {
            cout<<"a="<<a<<endl<<"b="<<b<<endl;
            e.show();
        }
};

int main()
{
    sample s;   
    s.showdata();
    array<int,3> arr;
    arr[0]=1;
    cout<<arr[0]<<endl;
    arr.fill(2);
    for(int i=0;i<arr.size();i++)
        cout<<arr.at(i);
}

int main()
{
    ofstream fout;
    fout.open("test.txt",ios::app);
    string str;
    getline(cin,str); 
    fout<<str;
}*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
ll n,b;
cin>>n>>b;
vector< ll > a;
for(ll i=0;i<n;i++) {
ll k;
cin>>k;
a.push_back(k);
}
vector< pair< ll, ll > > mi1(n);
priority_queue< pair< ll, ll > , vector< pair< ll, ll >  > , greater < pair< ll, ll > > > pq;
for(ll i=n-1,j=0;j<b;i--,j++)
pq.push(make_pair(a[i],i));
mi1[n-1]=pq.top();
ll i=n-b-1;
ll j=n-2;
while(j>=0) {
if(i>=0)
pq.push(make_pair(a[i],i));
while(pq.top().second>j)
pq.pop();
mi1[j]=pq.top();
j--;
i--;
}
ll ans=0;
ll last=n;
i=n-1;
while(i>=0) {
pair< ll, ll > k1=mi1[i];
ans+=(last-mi1[i].second)*mi1[i].first;
last=mi1[i].second;
i=last-1;
}
cout<<ans<<endl;
return 0;
}
