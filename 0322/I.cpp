#include<bits/stdc++.h>
using namespace std;
struct edget
{
    int v,cap;
    edget(int _v=0,int _cap=0):v(_v),cap(_cap){};
};
edget e[100050];
int n,m,p,s,t;
int cnt=1;
int pre[100050],tail[505],cur[505],dep[505];
bool flag[505];
void addedge(int u,int v,int cap)
{
    e[++cnt]=edget(v,cap);pre[cnt]=tail[u];tail[u]=cnt;
    e[++cnt]=edget(u,0);pre[cnt]=tail[v];tail[v]=cnt;
}
int dfs(int x,int flow)
{
    if (x==t) return flow;
    int res=0,ff;
    for (int u=cur[x];u;u=pre[u])
    {
        cur[x]=u;
        if (dep[e[u].v]==dep[x]+1 && e[u].cap)
        {
            ff=dfs(e[u].v,min(flow,e[u].cap));
            e[u].cap-=ff;e[u^1].cap+=ff;
            res+=ff;flow-=ff;
            if (!flow) break;
        }
    }
    if (!res) dep[x]=-1;
    return res;
}
bool bfs()
{
    memset(dep,0,sizeof(dep));
    for (int i=0;i<=t;i++) cur[i]=tail[i];
    queue<int> q;
    q.push(s);dep[s]=1;
    while (!q.empty())
    {
        int x=q.front();q.pop();
        for (int u=tail[x];u;u=pre[u])
            if (!dep[e[u].v] && e[u].cap)
            {
                q.push(e[u].v);
                dep[e[u].v]=dep[x]+1;
            }
    }
    return dep[t];
}
int maxflow()
{
    int ans=0;
    while (bfs())
        ans+=dfs(s,0x3f3f3f3f);
    return ans;
}
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m>>p;
    s=0,t=n+m+p+1;
    for (int i=1;i<=n;i++)
    {
        int k;cin>>k;addedge(s,i,1);
        for (int j=1;j<=k;j++)
        {
            int x;cin>>x;
            addedge(i,n+x,1);
        }
    }
    memset(flag,0,sizeof(flag));
    for (int i=1;i<=p;i++)
    {
        int l,r;cin>>l;
        for (int j=1;j<=l;j++)
        {
            int x;cin>>x;
            addedge(n+x,n+m+i,1);
            flag[x]=1;
        }
        cin>>r;addedge(n+m+i,t,r);
    }
    for (int i=1;i<=m;i++) if (!flag[i]) addedge(n+i,t,1);
    cout<<maxflow()<<endl;
}