#include<bits/stdc++.h>
using namespace std;
const int blocksize=300;
int blockidx[50050];
vector<int> G[50050];
int tsize[50050],fa[50050],dep[50050];
void dfs(int u,int d,int f)
{
    fa[u]=f;tsize[u]=1;dep[u]=d;
    for (auto x:G[u])
        if (x!=f)
        {
            dfs(x,d+1,u);
            tsize[u]+=tsize[x];
        }
}
int top[50050];
void pf(int u,int f,int ts)
{
    top[u]=ts;
    int maxw=0;
    for (auto x:G[u])
        if (x!=f && (maxw==0||tsize[x]>tsize[maxw])) maxw=x;
    if (maxw) pf(maxw,u,ts);
    for (auto x:G[u])
        if (x!=f && x!=maxw) pf(x,u,x);
}
void bfs(int nowd[],vector<int>& v)
{
    static bool inq[50050];
    static queue<int> q;
    while (q.size()) q.pop();memset(inq,0,sizeof(inq));
    for (auto x:v) q.push(x),nowd[x]=0,inq[x]=1;
    while (q.size())
    {
        int u=q.front();q.pop();
        for (auto x:G[u])
            if (!inq[x])
                nowd[x]=nowd[u]+1,inq[x]=1,q.push(x);
    }
}
int alldist[350][50050];
int lca(int u,int v)
{
    while (top[u]!=top[v])
    {
        if (dep[top[u]]<dep[top[v]]) swap(u,v);
        u=fa[top[u]];
    }
    if (dep[u]<dep[v]) swap(u,v);
    return v;
}
int getdist(int u,int v)
{
    return dep[u]+dep[v]-2*dep[lca(u,v)];
}
int dist(int c,int l,int r)
{
    int id1=blockidx[l],id2=blockidx[r];
    int rv=0x3f3f3f3f;
    if (id1==id2) {for (int i=l;i<=r;i++) rv=min(rv,getdist(c,i));return rv;}
    for (int i=id1+1;i<=id2-1;i++) rv=min(rv,alldist[i][c]);
    while (blockidx[l]!=id1+1) rv=min(rv,getdist(c,l++));
    while (blockidx[r]!=id2-1) rv=min(rv,getdist(c,r--));
    return rv;
}
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    for (int i=1;i<=50050;i++) blockidx[i]=1+(i-1)/blocksize;
    int t;cin>>t;
    while (t--)
    {
        static int cas=0;
        cout<<"Case "<<++cas<<":\n";
        static int n;cin>>n;
        for (int i=1;i<=n;i++) G[i].clear();
        for (int i=1;i<n;i++)
        {
            int u,v;cin>>u>>v;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        dfs(1,1,1);
        pf(1,1,1);
        int x=0;
        for (int i=1;i<=blockidx[n]+1;i++)
        {
            static vector<int> inc;inc.clear();
            for (;x<n && blockidx[x+1]==i;x++) inc.push_back(x);
            bfs(alldist[i],inc);
        }
        static tuple<int,int> tag[100050];
        int q;cin>>q;
        while (q--)
        {
            int op;cin>>op;int opn;cin>>opn;
            if (op==1) {cin>>get<0>(tag[opn])>>get<1>(tag[opn]);continue;}
            if (op==2) {tag[opn]=make_tuple(0,0);continue;}
            int k;cin>>k;int res=0x3f3f3f3f;
            while (k--)
            {
                int cm;cin>>cm;
                if (get<0>(tag[cm])>0)
                {
                    int l,r;tie(l,r)=tag[cm];
                    res=min(res,dist(opn,l,r));
                }
            }
            if (res==0x3f3f3f3f) cout<<-1<<endl;else cout<<res<<endl;
        }
    }
}