#include<bits/stdc++.h>
using namespace std;
using point=tuple<double,double>;
constexpr auto& getx(point& p){return get<0>(p);}
constexpr auto& gety(point& p){return get<1>(p);}
point p[25];
int n;
map<double,int> cnt;
int ans=0;
bool vis[25];
void dfs(int cur,int pairs)
{
    if (pairs==(n>>1))
    {
        int res=0;
        for (auto x:cnt)
        {
            int nm=x.second;
            res+=(nm*(nm-1))>>1;
        }
        ans=max(ans,res);
        return;
    }
    if (vis[cur]) {dfs(cur+1,pairs);return;}
    vis[cur]=1;
    for (int i=cur+1;i<=n;i++)
    if (!vis[i])
    {
        vis[i]=1;
        double k=1e9;
        if (getx(p[i])-getx(p[cur])!=0) k=(gety(p[i])-gety(p[cur]))/(getx(p[i])-getx(p[cur]));
        cnt[k]++;
        dfs(cur+1,pairs+1);
        cnt[k]--;
        vis[i]=0;
    }
    vis[cur]=0;
}
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    for (int i=1;i<=n;i++) cin>>getx(p[i])>>gety(p[i]);
    dfs(1,0);
    cout<<ans<<endl;
}