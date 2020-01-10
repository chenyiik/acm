#include<bits/stdc++.h>
using namespace std;
struct ss
{
    int x,y,z;
};
vector<int> v[200050];
int cnt[200050];
bool vis[200050];
vector<int> ans;
ss p[200050];
void dfs(int rt)
{
    for (int i=0;i<3;i++)
    {
        cnt[p[v[rt][i]].x]=0;
        cnt[p[v[rt][i]].y]=0;
        cnt[p[v[rt][i]].z]=0;
    }
    for (int i=0;i<3;i++)
    {
        cnt[p[v[rt][i]].x]++;
        cnt[p[v[rt][i]].y]++;
        cnt[p[v[rt][i]].z]++;
    }
    for (int i=0;i<3;i++)
    {
        auto t=p[v[rt][i]].x;
        if (cnt[t]>=2 && !vis[t])
        {
            ans.push_back(t);
            vis[t]=1;
            dfs(t);
            break;
        }
        t=p[v[rt][i]].y;
        if (cnt[t]>=2 && !vis[t])
        {
            ans.push_back(t);
            vis[t]=1;
            dfs(t);
            break;
        }
        t=p[v[rt][i]].z;
        if (cnt[t]>=2 && !vis[t])
        {
            ans.push_back(t);
            vis[t]=1;
            dfs(t);
            break;
        }
    }
}
int main()
{
    int n;
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>p[i].x>>p[i].y>>p[i].z;
        v[p[i].x].push_back(i);
        v[p[i].y].push_back(i);
        v[p[i].z].push_back(i);
    }
    for (int i=0;i<3;i++)
    {
        ++cnt[p[v[1][i]].x];
        ++cnt[p[v[1][i]].y];
        ++cnt[p[v[1][i]].z];
    }
    vis[1]=1;
    ans.push_back(1);
    for (int i=0;i<3;i++)
    {
        auto t=p[v[1][i]].x;
        if (cnt[t]>=2 && !vis[t])
        {
            ans.push_back(t);
            vis[t]=1;
            dfs(t);
            break;
        }
        t=p[v[1][i]].y;
        if (cnt[t]>=2 && !vis[t])
        {
            ans.push_back(t);
            vis[t]=1;
            dfs(t);
            break;
        }
        t=p[v[1][i]].z;
        if (cnt[t]>=2 && !vis[t])
        {
            ans.push_back(t);
            vis[t]=1;
            dfs(t);
            break;
        }
    }
    for (auto x:ans) cout<<x<<" ";
}