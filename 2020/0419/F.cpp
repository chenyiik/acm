#include<bits/stdc++.h>
using namespace std;
vector<int> G[10050];
int fv[10050],sv[10050];
int bump[10050][21];
int ts=0,l;
bitset<10050> vis[10050];
void dfs(int u,int fa)
{
    fv[u]=++ts;
    bump[u][0]=fa;
    vis[u]=vis[fa];
    vis[u][u]=true;
    for (int i=1;i<=l;i++) bump[u][i]=bump[bump[u][i-1]][i-1];
    for (auto x:G[u])
        if (x!=fa) dfs(x,u);
    sv[u]=++ts;
}
bool isfa(int fa,int child)
{
    return fv[fa]<=fv[child] && sv[fa]>=sv[child];
}
int lca(int u,int v)
{
    if (isfa(u,v)) return u;
    if (isfa(v,u)) return v;
    for (int i=l;i>=0;i--)
        if (!isfa(bump[u][i],v)) u=bump[u][i];
    return bump[u][0];
}
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    int t;
    cin>>t;
    while (t--)
    {
        static int cas=0;
        cout<<"Case "<<++cas<<":\n";
        int n;cin>>n;
        for (int i=1;i<=n;i++) G[i].clear();
        for (int i=1;i<n;i++)
        {
            int u,v;cin>>u>>v;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        ts=0;
        memset(bump,sizeof(bump),0);
        memset(fv,sizeof(fv),0);
        memset(sv,sizeof(sv),0);
        l=ceil(log2(n));
        dfs(1,1);
        int q;cin>>q;
        while (q--)
        {
            int k;cin>>k;
            vector<tuple<int,int>> rt;
            for (int i=1;i<=k;i++)
            {
                int u,v;cin>>u>>v;
                rt.push_back(make_tuple(u,v));
            }
            bitset<10050> res,cur;
            res.set();
            for (auto x:rt)
            {
                int p=lca(get<0>(x),get<1>(x));
                cur=vis[get<0>(x)]^vis[get<1>(x)];
                cur[p]=1;
                res&=cur;
                cur&=0;
            }
            cout<<res.count()<<endl;
        }
    }
}