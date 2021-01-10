#include<bits/stdc++.h>
using namespace std;
vector<int> G[100050];
int main()
{
    int n,m;
    cin>>n>>m;
    for (int i=1;i<=m;i++)
    {
        int u,v;
        cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    static int dist[100050];
    memset(dist,0x3f,sizeof(dist));
    static queue<int> q;
    q.push(1);dist[1]=0;
    while (!q.empty())
    {
        int u=q.front();q.pop();
        for (auto x:G[u])
        {
            if (dist[x]>dist[u]+1)
            {
                dist[x]=dist[u]+1;
                q.push(x);
            }
        }
    }
    cout<<dist[n]-1<<endl;
}