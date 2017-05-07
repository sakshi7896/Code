#include<bits/stdc++.h>
using namespace std;
int * prefix(string p)
{
    int i=1,j=0;
    int * lps= new int[p.length()];
    for(int i=1;i<p.length();)
    {
        if(p[i]==p[j])
        {
            lps[i]=j+1;
            i++;
            j++;
        }
        else
        {
            if(j!=0)
            {
                j=lps[j-1];
            }
            else
            {
                lps[i]=0;
                i++;
            }
        }
    }
    return lps;
}

int kmp(string t, string p)
{   int *lps;
int counter=0;
lps= prefix(p);
    int i=0,j=0;
    while(i<t.length() && j<p.length())
    {
        if(t[i]==p[j])
        {
            i++;j++;
        }
        else
        {
                if(j!=0)
                {
                    j=lps[j-1];
                }
                else
                    i++;
        }

    if(j== p.length()) {counter++; j=lps[j-1];}}
       // return true;
    //return false;
    return counter;
}
int main()
{
    string t, p;
    cout<<"Enter Text and patter\n";
    cin>>p>>t;
    int tlen=t.length();
    int plen=p.length();
    int a=kmp(t,p);
    cout<<a;
    return 0;
}
