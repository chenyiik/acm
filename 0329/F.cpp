#include<bits/stdc++.h>
using namespace std;
struct edget
{
    long long u,v,w,id;
};
edget e1[200050],e2[200050];
vector<long long> g1[200050],g2[200050];
long long n,m,tot1,tot2;
long long dis[200050],dis2[200050];
void spfa()
{
    long long s=1;
    memset(dis,0x3f,sizeof(dis));
    static bool inq[200050];memset(inq,0,sizeof(inq));
    static queue<long long> q;while(q.size()) q.pop();
    q.push(s);inq[s]=1;dis[s]=0;
    while (q.size())
    {
        long long u=q.front();q.pop();inq[u]=0;
        for (auto x:g1[u])
        {
            auto e=e1[x];
            if (dis[e.v]>dis[u]+e.w)
            {
                dis[e.v]=dis[u]+e.w;
                if (!inq[e.v]) {q.push(e.v);inq[e.v]=1;}
            }
        }
    }
}
void spfa2()
{
    long long s=2;
    memset(dis2,0x3f,sizeof(dis2));
    static bool inq[200050];memset(inq,0,sizeof(inq));
    static queue<long long> q;while(q.size()) q.pop();
    q.push(s);inq[s]=1;dis2[s]=0;
    while (q.size())
    {
        long long u=q.front();q.pop();inq[u]=0;
        for (auto x:g2[u])
        {
            auto e=e2[x];
            if (dis2[e.v]>dis2[u]+e.w)
            {
                dis2[e.v]=dis2[u]+e.w;
                if (!inq[e.v]) {q.push(e.v);inq[e.v]=1;}
            }
        }
    }
}
long long dfn[200050],low[200050],now=1;
edget e3[200050];
vector<long long> g3[200050];
long long tot3;
bool isb[200050];
void tarjan(long long u,long long pre)
{
    dfn[u]=low[u]=now++;
    for (auto x:g3[u])
    {
        auto e=e3[x];
        if (e.v!=pre)
        {
            if (!dfn[e.v])
            {
                tarjan(e.v,u);
                low[u]=min(low[u],low[e.v]);
                if (low[e.v]>dfn[u]) isb[e.id]=1;
            }
            else low[u]=min(low[u],dfn[e.v]);
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m;
    for (long long i=1;i<=m;i++)
    {
        long long u,v,w;
        cin>>u>>v>>w;
        e1[++tot1]=(edget){u,v,w,i};
        e2[++tot2]=(edget){v,u,w,i};
        g1[u].push_back(tot1);
        g2[v].push_back(tot2);
    }
    spfa();spfa2();
    long long dist=dis[2];
    for (long long i=1;i<=tot1;i++)
    {
        auto e=e1[i];
        if (dis[e.u]+dis2[e.v]+e.w==dist)
        {
            e3[++tot3]=(edget){e.u,e.v,1,e.id};
            g3[e.u].push_back(tot3);
            e3[++tot3]=(edget){e.v,e.u,1,e.id};
            g3[e.v].push_back(tot3);
        }
    }
    tarjan(1,-1);
    static long long ans[200050];
    for (long long i=1;i<=tot1;i++)
    {
        auto e=e1[i];
        if (dis[e.v]+dis2[e.u]+e.w<dist) ans[e.id]=1;else if (isb[e.id]) ans[e.id]=2;
    }
    for (long long i=1;i<=m;i++)
        cout<<vector<string>({"SOSO","HAPPY","SAD"})[ans[i]]<<endl;
}