#include<bits/stdc++.h>
using namespace std;
struct edget
{
    long long v,w;
};
vector<edget> G[100050<<1];
long long dist[100050<<1];
long long spfa(long long s)
{
    static queue<long long> q;
    static bool inq[100050<<1];
    memset(dist,0x3f,sizeof(dist));
    dist[s]=0;q.push(s);inq[s]=1;
    while (!q.empty())
    {
        long long u=q.front();q.pop();
        inq[u]=0;
        for (auto x:G[u])
        {
            long long v=x.v,w=x.w;
            if (dist[v]>dist[u]+w)
            {
                dist[v]=dist[u]+w;
                if (!inq[v])
                {
                    inq[v]=1;
                    q.push(v);
                }
            }
        }
    }
}
int main()
{
    long long n,m,k;
    cin>>n>>m>>k;
    for (long long i=1;i<=m;i++)
    {
        long long u,v,w;
        cin>>u>>v>>w;
        G[u+n].push_back({v,w});
        G[v+n].push_back({u,w});
    }
    for (long long i=1;i<=n;i++)
    {
        long long w;
        cin>>w;
        G[i].push_back({i+n,w});
    }
    for (long long i=1;i<=k;i++)
    {
        long long v;
        cin>>v;
        G[0].push_back({v,0});
    }
    spfa(0);
    for (long long i=1;i<=n;i++) cout<<dist[i+n]<<endl;
}