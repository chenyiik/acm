#include<bits/stdc++.h>
using namespace std;
unordered_map<int,int> mp;
pair<int,int> cl[4050];
int main()
{
    int t;
    scanf("%d",&t);
    for (int cas=1;cas<=t;cas++)
    {
        printf("Case #%d: ",cas);
        int n,m;
        scanf("%d%d",&n,&m);
        mp.clear();
        mp[1]=0;mp[n+1]=0;
        for (int i=1;i<=m;i++)
        {
            int l,r;
            scanf("%d%d",&l,&r);
            mp[l]=mp[l]+1;
            mp[r+1]=mp[r+1]-1;
        }
        int cur=0;
        for (auto y:mp) cl[++cur]=y;
        sort(cl+1,cl+1+cur);
        int last=1;
        int pls=0;
        int ans=0;
        int zl=0;
        for (int i=1;i<=cur;i++)
        {
            auto x=cl[i];
            int now=x.first;
            int diff=x.second;
            ans+=pls*(now-last);
            zl+=diff;
            if (zl&1) pls=1;else pls=0;
            last=now;
        }
        printf("%d\n",ans);
    }
}