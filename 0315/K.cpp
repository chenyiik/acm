#include<bits/stdc++.h>
using namespace std;
struct edget
{
    int v,w,w2;
    edget(int _v=0,int _w=0,int _w2=0):v(_v),w(_w),w2(_w2){};
};
int n,m;
int dis[100050][3];
vector<edget> G[100050];
struct status
{
    int v,mod;
    bool operator<(const status& b)const
    {
        if (v!=b.v) return v<b.v;
        return mod<b.mod;
    }
};
void spfa(int s)
{
    dis[s][0]=0;
    static queue<status> q;
    static set<status> inq;
    q.push({s,0});inq.insert({s,0});
    while (!q.empty())
    {
        auto u=q.front();q.pop();
        inq.erase(inq.find(u));
        for (auto x:G[u.v])
        {
            if (dis[u.v][u.mod]+x.w<dis[x.v][(u.mod+x.w2)%3])
            {
                dis[x.v][(u.mod+x.w2)%3]=dis[u.v][u.mod]+x.w;
                if (!inq.count({x.v,(u.mod+x.w2)%3}) && x.v!=n)
                {
                    inq.insert({x.v,(u.mod+x.w2)%3});
                    q.push({x.v,(u.mod+x.w2)%3});
                }
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m;
    for (int i=1;i<=m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        G[u].push_back(edget(v,w,1));
        G[v].push_back(edget(u,w,1));
    }
    for (int i=1;i<=n;i++) dis[i][0]=dis[i][1]=dis[i][2]=0x3f3f3f3f;
    spfa(1);
    static priority_queue<pair<int,string>,vector<pair<int,string>>,greater<pair<int,string>>> pq;
    pq.push({dis[n][0],"me"});
    pq.push({dis[n][1],"Gon"});
    pq.push({dis[n][2],"Killua"});
    while (!pq.empty()) {cout<<pq.top().second<<endl;pq.pop();}
}