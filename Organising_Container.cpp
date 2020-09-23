#include<iostream>
using namespace std;


int main(){
    int q;
    long long int i,j,k,l,store;
    cin >> q;
    for(int a0 = 0; a0 < q; a0++){
        int n;
        cin >> n;
        long int M[n][n]={0};
        for(int M_i = 0;M_i < n;M_i++){
           for(int M_j = 0;M_j < n;M_j++){
              cin >> M[M_i][M_j];
           }
        }
       for(i=0;i<n-1;i++)
       {
           long long int temp1=0,temp2=0;
           for(j=i+1;j<n;j++)
           {
               temp1+=M[j][i];
               temp2+=M[i][j];
           }     
           if(temp1!=temp2)
                 break;
           else
           {
                   l=i+1;
                   store=M[i][l];

               for(k=i+1;k<n;k++)
               {
                   if(store<M[k][i])
                   {
                       while(M[k][i]!=0)
                       {
                           if(store<M[k][i])
                           {
                               M[k][i]-=store;
                               M[i][l]=0;
                               M[k][l]+=store;
                               l++;
                               store=M[i][l];
                           }
                           else
                           {
                               M[i][l]-=M[k][i];
                               M[k][i]=0;
                               store=M[i][l];
                               M[k][l]+=M[k][i];
                           }
                       }
                   }
                  
                   else
                   {
                      M[i][l]-=M[k][i];
                      M[k][i]=0;
                      M[k][l]+=M[k][i];
                      store=M[i][l];
                   }  
                   }
               for(int a=i+1;a<n;a++)
                   cout<<M[i][a]<<"        "<<M[a][i]<<endl<<endl;
              }
           }
        if(i==n-1)
            cout<<"Possible"<<endl;
        else
            cout<<"Impossible"<<endl;
    }
    return 0;
}