#include<iostream>
using namespace std;
class Matrix
{
   private:
        int arr[10][10],m,n;

   public:
        void getArr()
        {   
            cout<<endl<<"Enter the order of the Matrix  :  ";
            cin>>m>>n;
            cout<<endl<<"Enter the elements of the Matrix \n";
            for(int i=0;i<m;i++)                      
            {
              for(int j=0;j<n;j++)
              cin>>arr[i][j];
            }
        }
        void operator+(Matrix m2)
        {
           Matrix temp;
           if(m!=m2.m||n!=m2.n)
           cout<<endl<<"INVALID ORDER OF MATRICES TO ADD\n";
           else
           {   
              for(int i=0;i<m;i++)
              {
                for(int j=0;j<n;j++)
                {
                  temp.arr[i][j]=arr[i][j]+m2.arr[i][j];
                }
              }
              cout<<endl<<endl<<"SUM OF THE MATRICES"<<endl;
              for(int i=0;i<m;i++)
             {
                for(int j=0;j<m;j++)
                      cout<<temp.arr[i][j]<<"  ";
                cout<<endl;
             }
           }
        }
        void operator-(Matrix m2)
        {
           Matrix temp;
           if(m!=m2.m||n!=m2.n)
           cout<<endl<<"INVALID ORDER OF MATICES TO SUBTRACT\n";
           
           else
           {   
              for(int i=0;i<m;i++)
              {
                for(int j=0;j<n;j++)
                {
                  temp.arr[i][j]=arr[i][j]-m2.arr[i][j];
                }
              }
              cout<<endl<<"DIFFERENCE OF TWO MATRICES"<<endl;
              for(int i=0;i<m;i++)
              {
                 for(int j=0;j<m;j++)
                    cout<<temp.arr[i][j]<<"  ";
                 cout<<endl;
              }
           }
        }
        Matrix operator*(Matrix m2)
        {
          Matrix temp;
          if(n!=m2.m)
          cout<<endl<<"INVALID ORDER OF MATRICES TO MULTIPLY\n"; 
            
           else
           {   
              for(int i=0;i<m;i++)
              { 
                for(int j=0;j<m2.n;j++)
                {  
                   int k=0;
                   temp.arr[i][j]=0;
                   while(k!=n)
                  {
                     temp.arr[i][j]+=arr[i][k]*m2.arr[k][j];
                     k++;
                  }
                }
              }
           cout<<endl<<endl<<"PRODUCT OF THE MATRICES"<<endl;
               for(int i=0;i<m;i++)
              {
                  for(int j=0;j<m;j++)
                       cout<<temp.arr[i][j]<<"  ";
                  cout<<endl;
              }
           }
        }
    };

    int main()
    {
          Matrix m1,m2;

          m1.getArr();

          m2.getArr();   
          m1+m2;
          m1-m2;
          m1*m2;
    }
     

