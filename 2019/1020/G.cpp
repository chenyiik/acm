#include<bits/stdc++.h>
using namespace std;
struct edge
{
    int u,v,w;
    double c;
    int next;
}e[200050];
int cnt=0,head[200050];
int n;
void addedge(int u,int v,int w,double c)
{
    e[cnt]=edge{u,v,w,c,head[u]};
    head[u]=cnt++;
    e[cnt]=edge{v,u,0,-c,head[v]};
    head[v]=cnt++;
}
double d[200050];
int p[200050],a[200050];
int ns,s,t;
bool inq[200050];
bool doo(int &flow,double &cost)
{
    for (int i=1;i<=ns;i++) {d[i]=1e18,inq[i]=false;}
    d[s]=0,p[s]=0,a[s]=0x3f3f3f3f;
    static queue<int> q;
    while (!q.empty()) q.pop();
    q.push(s),inq[s]=true;
    while (!q.empty())
    {
        int u=q.front();q.pop();inq[u]=false;
        for (int x=head[u];x!=-1;x=e[x].next)
        {
            int v=e[x].v,w=e[x].w;
            double c=e[x].c;
            if (w>0 && d[v]>d[u]+c)
            {
                d[v]=d[u]+c;
                p[v]=x;
                a[v]=min(a[u],w);
                if (!inq[v])
                {
                    q.push(v);
                    inq[v]=true;
                }
            }
        }
    }
    if (fabs(d[t]-1e18)<1e-8) return false;
    flow+=a[t];cost+=a[t]*d[t];
    for (int u=t;u!=s;u=e[p[u]].u)
    {
        e[p[u]].w-=a[t];
        e[p[u]^1].w+=a[t];
    }
    return true;
}
void mcmf(int& flow,double& cost)
{
    flow=0;
    cost=0;
    while (doo(flow,cost));
}
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    static int mt[205][205];
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++) cin>>mt[i][j];
    ns=(n+2)*n+2;
    s=0,t=ns-1;
    cnt=0;memset(head,-1,sizeof(head));
    for (int i=1;i<=n;i++)
    {
        addedge(s,n*n+i,1,0);
        addedge(n*n+n+i,t,1,0);
    }
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
        {
            addedge(n*n+i,(j-1)*n+i,1,0);
            addedge((j-1)*n+i,n*n+n+j,1,-log10(mt[j][i]));
        }
    int flow=0;
    double cost=0;
    mcmf(flow,cost);
    for (int i=n*n+1;i<=n*n+n;i++)
        for (int j=head[i];j!=-1;j=e[j].next)
            if (e[j].w==0)
            {
                cout<<(e[j].v-1)/n+1;
                cout<<" \n"[i==n*n+n];
                break;
            }
    return 0;
}
