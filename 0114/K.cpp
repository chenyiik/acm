#include<bits/stdc++.h>
using namespace std;
struct edget
{
    long long v,w;
};
vector<edget> G[1000050];
vector<long long> info[200050];
long long n,h;
inline long long toid(long long x,long long y,long long n)
{
    return x+(y-1)*n;
}
long long spfa(long long s)
{
    static queue<long long> q;
    static bool inq[1000050];
    static long long dist[1000050];
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
    return dist[toid(1,h+1,n)];
}
int main()
{
    scanf("%d%d",&n,&h);
    for (long long i=1;i<=n;i++) {info[i].clear();info[i].resize(h+1);}
    for (long long i=1;i<=n;i++)
        for (long long j=1;j<=h;j++) scanf("%d",&info[i][j]);
    for (long long i=1;i<=n;i++) G[toid(0,1,n)].push_back({toid(i,1,n),-info[i][1]});
    for (long long i=1;i<=n;i++)
    {
        for (long long j=1;j<h;j++)
        {
            long long u=toid(i,j,n);
            G[u].push_back({toid(i,j+1,n),-info[i][j+1]});
            if (i>1)
                G[u].push_back({toid(i-1,j+1,n),-info[i-1][j+1]});
            if (i<n)
                G[u].push_back({toid(i+1,j+1,n),-info[i+1][j+1]});
        }
    }
    for (long long i=1;i<=n;i++)
        G[toid(i,h,n)].push_back({toid(1,h+1,n),0});
    cout<<-spfa(0)<<endl;
}