#include<iostream>
#include<queue>
#include<bits/stdc++.h>
using namespace std;
int main()
{
        queue<int> q;
        cout<<q.size()<<endl;
        q.push(10);
        q.push(20);
        q.push(30);
        q.pop();
        cout<<endl<<q.size()<<endl;
        priority_queue<int> pq;
        pq.push(50);
        pq.push(30);
        //pq.push(30);
        //priority_queue<int>::iterator it=pq.end();
        cout<<pq.top()<<endl;
        string a;
        cin>>a;
        cout<<a;
        cin>>a;
        cout<<a<<endl<<a.size()<<endl;
        pair<int,char> p;
        p.first=10;
        p.second='A';
        cout<<p.first<<endl<<p.second<<endl;
       
        
       
}
