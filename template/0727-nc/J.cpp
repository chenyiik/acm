#include<bits/stdc++.h>
using namespace std;
long long dis[1050][1050],k;
struct node{
    long long x,k,d;
    bool operator<(const node &b)const
    {
        return d>b.d;
    }
};
priority_queue<node> pq;
struct edget
{
    long long v,w;
};
vector<edget> e[1050];
void addedge(long long u,long long v,long long w)
{
    e[u].push_back(edget{v,w});
    e[v].push_back(edget{u,w});
}
long long dij(long long s,long long t)
{
    memset(dis,0x3f,sizeof(dis));
    pq.push((node){s,0,0});
    dis[s][0]=0;
    while(!pq.empty())
    {
        node o=pq.top();pq.pop();
        if(o.d!=dis[o.x][o.k]) continue;
        if(o.x==t) return o.d;
        for(auto x:e[o.x])
        {
            if(dis[x.v][o.k]>dis[o.x][o.k]+x.w)
            {
                dis[x.v][o.k]=dis[o.x][o.k]+x.w;
                pq.push((node){x.v,o.k,dis[x.v][o.k]});
            }
            if(o.k<k&&dis[x.v][o.k+1]>dis[o.x][o.k])
            {
                dis[x.v][o.k+1]=dis[o.x][o.k];
                pq.push((node){x.v,o.k+1,dis[x.v][o.k+1]});
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    long long n,m;
    long long s,t;
    cin>>n>>m>>s>>t>>k;
    for(long long i=1;i<=m;i++)
    {
        long long u,v,w;
        cin>>u>>v>>w;
        addedge(u,v,w);
    }
    cout<<dij(s,t)<<endl;
    return 0;
}