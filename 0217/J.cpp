#include<bits/stdc++.h>
using namespace std;
int fa[100050];
vector<int> son[100050];
int l[100050],r[100050],ans[100050];
int sz[100050],heavyson[100050],num,n,k;
int find(int x)
{
    return (x==fa[x])?x:(fa[x]=find(fa[x]));
}
void merge(int u,int v)
{
    int f1=find(u),f2=find(v);
    if (f1!=f2) {fa[f2]=f1;num--;}
}
void solve(int p)
{
    merge(l[p],r[p]);
    for (auto x:son[p]) solve(x);
}
void clear(int p)
{
    fa[l[p]]=l[p],fa[r[p]]=r[p];
    for (auto x:son[p]) clear(x);
}
void dfs(int u,bool cln)
{
    for (auto x:son[u])
    {
        if (x==heavyson[u]) continue;
        num=k;
        dfs(x,true);
    }
    num=k;
    if (heavyson[u]!=-1) dfs(heavyson[u],false);
    for (int x:son[u])
        if (x!=heavyson[u]) solve(x);
    merge(l[u],r[u]);
    ans[u]=num;
    if (cln) clear(u);
}
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n>>k;
    for (int i=2;i<=n;i++)
    {
        int x;
        cin>>x;
        son[x].push_back(i);
    }
    for (int i=1;i<=n;i++) cin>>l[i]>>r[i];
    for (int i=n;i>=1;i--)
    {
        sz[i]=1;
        for (auto x:son[i]) sz[i]+=sz[x];
    }
    for (int i=1;i<=n;i++)
    {
        int id=-1,hs=0;
        for (auto x:son[i])
            if (sz[x]>hs)
            {
                hs=sz[x];
                id=x;
            }
        heavyson[i]=id;
    }
    for (int i=1;i<=k;i++) fa[i]=i;
    dfs(1,false);
    for (int i=1;i<=n;i++) cout<<ans[i]<<endl;
}