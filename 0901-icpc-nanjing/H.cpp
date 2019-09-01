#include<bits/stdc++.h>
using namespace std;
int d[305][305];
int dist[305];
void spfa(int s,int n)
{
    memset(dist,0x3f,sizeof(dist));
    dist[s]=0;
    queue<int> q;
    while (!q.empty()) q.pop();
    static bool inq[305];
    memset(inq,0,sizeof(inq));
    inq[s]=true;q.push(s);
    while (!q.empty())
    {
        int u=q.front();q.pop();
        for (int i=0;i<n;i++)
            if (d[u][i]!=0x3f3f3f3f)
                if (dist[u]+d[u][i]<dist[i])
                {
                    dist[i]=dist[u]+d[u][i];
                    if (!inq[i])
                    {
                        inq[i]=true;
                        q.push(i);
                    }
                }
        inq[u]=false;
    }
}
int main()
{
    int t;
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>t;
    while (t--)
    {
        int n,m;
        cin>>n>>m;
        memset(d,0x3f,sizeof(d));
        for (int i=1;i<=m;i++)
        {
            int u,v,w;
            cin>>u>>v>>w;
            d[u][v]=w;
        }
        for (int i=1;i<=6;i++)
        {
            int u,v;
            cin>>u>>v;
            spfa(v,n);
            cout<<-dist[u]<<endl;
            d[u][v]=-dist[u];
        }
    }
}