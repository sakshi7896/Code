#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, flag=1;
    cin>>n;
    int a[5]={0};
    int b[5]={0};
    int num, ans=0;
    for(int i=0;i<n;i++)
    {
        cin>>num;
        a[num-1]++;
    }
    for(int j=0;j<n;j++)
    {

        cin>>num;
        b[num-1]++;
    }
    for(int i=0;i<5;i++)
    {

        if(((a[i]+b[i])%2) !=0) {
            flag=0;
            break;
        }
       ans+= abs(a[i]-((a[i]+b[i])/2));
    }
    if(flag==0){ cout<<"-1"<<endl;}
    else cout<<ans/2<<endl;
    return 0;
}
