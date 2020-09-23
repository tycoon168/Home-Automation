#include<bits/stdc++.h>
using namespace std;

int mat[1000][10];
void print(string str);
struct Tuple
{
    int Rank[2];
    int index;
};

bool cmp(Tuple a,Tuple b)
{
    return (a.Rank[0] == b.Rank[0])?(a.Rank[1]<b.Rank[1]?1:0):(a.Rank[0]<b.Rank[0]?1:0);
}

void buildSuffixArray(string str)
{
    int len = str.length();
    Tuple pat[len];

    for(int i=0;i<len;i++)
    {
        pat[i].Rank[0] = str[i]-'a'+1;
        pat[i].Rank[1] = 0;
        pat[i].index = i;
    }

    sort(pat,pat+len,cmp);

    int prev0 = pat[0].Rank[0];
    int prev1 = pat[0].Rank[1];
    int c =1;
    for(int i=0;i<=len-1;i++)
    {
        if(pat[i].Rank[0] == prev0 && pat[i].Rank[1] == prev1)
        {
            mat[pat[i].index][0] = c;
        }
        else
        {
            c++;
            mat[pat[i].index][0] = c;
        }
        prev0 = pat[i].Rank[0];
        prev1 = pat[i].Rank[1];
    }
    //print(str);
    for(int i=1;i<10;i++)
    {
        int t = pow(2,i);
        for(int j=0;j<len;j++)
        {
            pat[j].Rank[0] = mat[j][i-1];
            if((j+t-1) <= len-1)
                pat[j].Rank[1] = mat[j+t-1][i-1];
            else
                pat[j].Rank[1] = 0;
            pat[j].index = j;
        }

        sort(pat,pat+len,cmp);

        int prev0 = pat[0].Rank[0];
        int prev1 = pat[0].Rank[1];
        c =1;
        for(int k=0;k<=len-1;k++)
        {
            if(pat[k].Rank[0] == prev0 && pat[k].Rank[1] == prev1)
            {
                mat[pat[k].index][i] = c;
            }
            else
            {
                c++;
                mat[pat[k].index][i] = c;
            }
            prev0 = pat[k].Rank[0];
            prev1 = pat[k].Rank[1];
        }
        //print(str);
    }
    for(int i=0;i<len;i++)
    {
        cout << pat[i].index << " ";
    }
    cout << endl;
}

void print(string str)
{
    int len = str.length();
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<len;j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main()
{
    string str;
    cin >> str;
    buildSuffixArray(str);
    //print(str);
    return 0;
}
