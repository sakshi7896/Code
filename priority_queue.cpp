#include<bits/stdc++.h>
using namespace std;
int main()
{
    priority_queue<long long> p;
    //no of elements
    int n;
    cin>>n;
    int q;
    int type;

    long long x;
    while(n--)
    {
       cin>>x;
       p.push(x);

    }
    //queries

    cin>>q;
    while(q--)
    {
        cin>>type;
        //type 1 is for insertion and 2 for display of max element
        if(type==1) { cin>>x; p.push(x);}
        else cout<<p.top()<<endl;
    }
    return 0;
}
