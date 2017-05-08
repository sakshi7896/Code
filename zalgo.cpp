#include<bits/stdc++.h>
using namespace std;
int * z(string ans)
{
    int *z1= new int[ans.length()];
    int k1,l=0,r=0;
    for(int k=1;k<ans.length();k++)
    {
        if(k>r)
        {
            l=r=k;
            while(r<ans.length() && (ans[r]==ans[r-l]))
            {
                r++;
            }
            z1[k]=r-l;
            r--;
        }
        else
        {
            //inside the box
            k1=k-l;

            //if not out of right
            if((z1[k1])<(r-k+1))
            {
                z1[k]=z1[k1];
            }
            else{
                l=k;
                while(r<ans.length() && (ans[r]==ans[r-l]))
                {
                    r++;
                }
                z1[k]=r-l;
                r--;
            }

        }
    }
     /*for(int i=0;i<ans.length();i++)
                cout<<z1[i];*/
            return z1;
}

void zalgo(string p, string t)
{

    string ans;
    int plen=p.length();
    int tlen=t.length();
    int i;
    for( i=0;i<plen;i++)
        ans+=p[i];
    ans+='$';
    for( i=0;i<tlen;i++)
        ans+=t[i];

    //cout<<ans.length()<<ans;
    int *z2=z(ans);
    for(int i=0;i<(plen+tlen+1);i++)
        if(z2[i]==plen)
            cout<<"\nfound at"<<(i-plen-1)<<endl;
}
int main()
{
    string p,t;
    cin>>p>>t;
    zalgo(p,t);
    return 0;
}
