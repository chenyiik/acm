#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<int> G[2050];
int conn[2050][2050];
vector<pair<int,int>> link;
bool check(int s,int t)
{
    static bool vis[2050];
    memset(vis,0,sizeof(vis));
    vis[s]=1;
    static queue<int> q;
    while (!q.empty()) q.pop();
    q.push(s);
    while (!q.empty())
    {
        int u=q.front();q.pop();
        for (auto v:G[u])
        {
            if (u==s && v==t) continue;
            if (vis[v]) continue;
            q.push(v);vis[v]=true;
            if (v==t) return false;
        }
    }
    if (vis[t]) return false;
    return true;
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i=1;i<=m;i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        G[u].push_back(v);
        link.push_back({u, v});
        conn[u][v]++;
    }
    static vector<pair<int,int>> res;
    for (auto x:link)
    {
        if (conn[x.first][x.second]>1) continue;
        if (check(x.first,x.second)) res.push_back(x);
    }
    printf("%d\n",res.size());
    for (auto x:res)
        printf("%d %d\n",x.first,x.second);
}