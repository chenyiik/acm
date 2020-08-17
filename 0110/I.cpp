#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    while (cin>>n>>m)
    {
        if (n+m==0) break;
        static int l[10050],r[10050];
        for (int i=1;i<=n;i++)
        {
            int t;
            cin>>t>>t;
            cin>>l[i]>>r[i];
            r[i]+=l[i];
        }
        while (m--)
        {
            int x,y;
            cin>>x>>y;y+=x;
            int ans=0;
            for (int i=1;i<=n;i++)
                if (!(r[i]<=x||y<=l[i])) ++ans;
            cout<<ans<<endl;
        }
    }
}