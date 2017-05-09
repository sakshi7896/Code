#include<bits/stdc++.h>
using namespace std;
void manacher(string s)
{

    char * t= new char[s.length()*2+3];
    t[0]='$';

    for(int i=0;i<s.length();i++)
    {
        t[2*i+1]='#';
        t[2*i+2]=s[i];
    }
    t[s.length()*2+1]='#';
     t[s.length()*2+2]='@';
     //t[s.length()*2+3]='\0';
    //cout<<t;
    int *p= new int[s.length()*2+3];
    for(int i=0;i<(s.length()*2+3);i++)
        p[i]=0;
    int c=0,r=0;
    for(int i=1;i<(s.length()*2+2);i++)
    {
        int mirr=2*c-i;
        if(i<r)
        {
            p[i]=min(r-i, p[mirr]);
        }
         while(t[i+(1+p[i])] == t[i-(1+p[i])])
             p[i]++;
        if((i+p[i])>r)
        {
            c=i;
            r=i+p[i];
        }

    }
    int ans=0;
    c=0;
    for(int i=0;i<(s.length()*2+2);i++)
    {
        if(p[i]>ans)
        {
            ans=p[i];
            c=i;
        }

    }
    cout<<ans<<endl;

    cout<<s.substr((c-1-ans)/2, ans);
}
int main()
{
    string s;
    cin>>s;
    manacher(s);
    return 0;
}
