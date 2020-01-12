#include<bits/stdc++.h>
using namespace std;
struct edget
{
    int v,w;
};
vector<edget> G[100050];
int dist[4][100050];
int n,m;
void spfa(int s)
{
    static bool inq[100050];
    for (int i=1;i<=n;i++) dist[s][i]=0x3f3f3f3f,inq[i]=false;
    dist[s][s]=0;
    static queue<int> q=queue<int>();
    q.push(s);inq[s]=true;
    while (!q.empty())
    {
        int u=q.front();q.pop();inq[u]=false;
        for (auto x:G[u])
            if (dist[s][u]+x.w<dist[s][x.v])
            {
                dist[s][x.v]=dist[s][u]+x.w;
                if (!inq[x.v])
                {
                    inq[x.v]=true;
                    q.push(x.v);
                }
            }
    }
}
struct node
{
    int x,y,z,id,cnt;
    bool operator<(const node&b) const
    {
        if (x!=b.x) return x<b.x;
        if (y!=b.y) return y<b.y;
        if (z!=b.z) return z<b.z;
        return false;
    }
};
int vis[100050];
node e[100050],tmp[100050];
int cc[100050],num=0;
int a[200050];
int lowbit(int x)
{
    return x&(-x);
}
void add(int x,int d)
{
    for (int i=x;i<200050;i+=lowbit(i)) a[i]+=d;
}
int sum(int x)
{
    int ans=0;
    for (int i=x;i;i-=lowbit(i)) ans+=a[i];
    return ans;
}
void cdq(int l,int r)
{
    if(r-l<=1) return;
    int mid=(r+l)>>1;
    cdq(l,mid);cdq(mid,r);
    int lp=l,rp=mid,o=0;
    while(lp<mid && rp<r)
    {
        if(e[lp].y<=e[rp].y)
        {
            add(e[lp].z,1);
            tmp[++o]=e[lp++];
        }
        else
        {
            int res=sum(e[rp].z);
            if(res!=0) vis[e[rp].id]=e[rp].cnt;
            tmp[++o]=e[rp++];
        }
    }
    while(rp<r)
    {
        int res=sum(e[rp].z);
        if(res!=0) vis[e[rp].id]=e[rp].cnt;
        tmp[++o]=e[rp++];
    }
    for(int i=l;i<lp;++i)
        add(e[i].z,-1);
    while(lp<mid) tmp[++o]=e[lp++];
    for(int i=1;i<=o;++i) e[i+l-1]=tmp[i];
}
int main()
{
    cin>>n>>m;
    int sum=n;
    for (int i=1;i<=n;i++) G[i].clear();
    while (m--)
    {
        int u,v,w;
        cin>>u>>v>>w;
        ++u,++v;
        G[u].push_back(edget{v,w});
        G[v].push_back(edget{u,w});
    }
    spfa(1);
    spfa(2);
    spfa(3);
    for (int i=1;i<=n;i++)
    {
        e[i]=node{dist[1][i],dist[2][i],dist[3][i],0,0};
        cc[++num]=dist[3][i];
    }
    sort(cc+1,cc+num+1);
    num=unique(cc+1,cc+num+1)-cc-1;
    for (int i=1;i<=n;i++) e[i].z=lower_bound(cc+1,cc+num+1,e[i].z)-cc;
    sort(e+1,e+n+1);
    int p=1,tot=0;
    for (int i=1;i<=n;i++)
    {
        if (e[i].x==e[i+1].x && e[i].y==e[i+1].y && e[i].z==e[i+1].z) {++p;continue;}
        e[i].cnt=p;
        e[++tot]=e[i];
        p=1;
    }
    n=tot;
    for (int i=1;i<=n;i++) e[i].id=i;
    memset(vis,0,sizeof(vis));
    cdq(1,n+1);
    for (int i=1;i<=n;i++) sum-=vis[i];
    cout<<sum<<endl;
}