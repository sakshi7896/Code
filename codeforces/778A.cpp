#include<bits/stdc++.h>
using namespace std;

int main()
{

    string s1, s2,s3;
    cin>>s1>>s2;

    long n=s1.length();
    int arr[200009];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int s=0,e=n-1,m;
    while(s<e)
    {
        s3="";
        s3+=s1;
        m=(s+e+1)/2;
        for(int i=0;i<m;i++)
            s3[arr[i]-1]='.';
        //cout<<s3<<" "<<s<<" "<<m<<" "<<e<<endl;
        int j=0;
        for(int i=0;i<n && j<s2.length();i++)
        {
            if(s3[i]==s2[j]) j++;
        }
        if(j==s2.length()) s=m;
        else e=m-1;
    }
    cout<<s<<endl;
    return 0;
}
