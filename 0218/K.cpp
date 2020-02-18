#include<bits/stdc++.h>
using namespace std;
struct et
{
    int u,v;
};
vector<et> p,p1;
vector<vector<int>> fw,fw1;
set<int> lt;
vector<set<int>> res;
void dfs(int v,int u)
{
    if (res[v].count(u)) return;
    if (res[v].size()>1) return;
    res[v].insert(u);
    for (auto x:fw1[v]) dfs(x,u);
}
int main()
{
    int n,m,t;
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m>>t;
    fw.resize(n+1);
    fw1.resize(n+1);
    res.resize(n+1);
    for (int i=1;i<=m;i++)
    {
        int u,v;
        cin>>u>>v;
        p.push_back({u,v});fw[v].push_back(u);
        if (v!=t) {p1.push_back({u,v});fw1[v].push_back(u);}
        else lt.insert(u);
    }
    for (auto x:lt) dfs(x,x);
    static set<int> ans;
    for (auto i:lt) if (res[i].size()==1) ans.insert(i);
    cout<<ans.size()<<endl;
    for (auto x:ans) cout<<x<<endl;
}