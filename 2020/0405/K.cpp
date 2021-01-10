#include<bits/stdc++.h>
using namespace std;
vector<int> G[100050];
bool vis[100050];
int cnt[100050];
int n,m,tot;
vector<tuple<int,int,int>> ans;
bool dfs(int u,int pre)
{
    cnt[u]=++tot;
    vis[u]=true;
    int last=-1;
    for (auto x:G[u])
    {
        if (x==pre) continue;
        if (vis[x])
        {
            if (cnt[x]>cnt[u]) continue;
            if (last==-1) last=x;
            else
            {
                ans.push_back(make_tuple(last,u,x));
                last=-1;
            }
        }else
        {
            if (dfs(x,u))
            {
                if (last==-1) last=x;
                else
                {
                    ans.push_back(make_tuple(last,u,x));
                    last=-1;
                }
            }
        }
    }
    if (last==-1) return true;
    if (pre!=-1) ans.push_back(make_tuple(last,u,pre));
    return false;
}
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m;
    for (int i=1;i<=m;i++)
    {
        int u,v;
        cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    for (int i=1;i<=n;i++)
        if (!vis[i]) dfs(i,-1);
    cout<<ans.size()<<endl;
    for (auto x:ans)
        cout<<get<0>(x)<<" "<<get<1>(x)<<" "<<get<2>(x)<<endl;
}