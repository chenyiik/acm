#include<bits/stdc++.h>
using namespace std;
long long d[10050][1<<8];
int color[10050];
long long ans;
struct edget
{
    int u,v,w;
}e[10050];
int get(int k)
{
    return rand()%k;
}
void calc(int n,int m,int k)
{
    for(int i=0;i<=n;i++) color[i]=get(k);
    for(int i=1;i<=n;i++)
        for(int l=0;l<=1<<k;l++) d[i][l]=-1e18;
    for(int i=1;i<=n;i++) d[i][1<<color[i]]=0;
    for(int s=0;s<(1<<k);s++)
        for(int i=1;i<=m;i++)
        {
            auto p=e[i];
            if(s&(1<<color[p.u])) d[p.u][s]=max(d[p.u][s],d[p.v][s^(1<<color[p.u])]+p.w);
            if(s&(1<<color[p.v])) d[p.v][s]=max(d[p.v][s],d[p.u][s^(1<<color[p.v])]+p.w);
        }
    for(int i=1;i<=n;i++) ans=max(ans,d[i][(1<<k)-1]);
}
int main()
{
    int T;
    srand(time(0));
    scanf("%d",&T);
    while(T--)
    {
        int n,m,k;
        scanf("%d%d%d",&n,&m,&k);
        for(int i=1;i<=m;i++)
            scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
        ans=-1;
        int rel=200;
        while(rel--)
        {
            calc(n,m,k);
        }
        if(ans==-1) cout<<"impossible"<<endl; else cout<<ans<<endl;
    }
}