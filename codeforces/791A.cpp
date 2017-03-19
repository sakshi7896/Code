#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a,b,ans=0;
    cin>>a>>b;
    while(a<=b)
    {
        a=a*3;
        b=b*2;
        ans++;
    }
    cout<<ans<<endl;
    return 0;
}
