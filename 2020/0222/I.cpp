#include<bits/stdc++.h>
using namespace std;
vector<int> G[2050];
int f[2050],vis[2050],sum[2050];
int n,l;
int solve(int u)
{
    if (vis[u]) return sum[u];
    vis[u]=1;sum[u]=0;
    for (auto x:G[u])
        if (x<=l) sum[u]+=solve(x),sum[u]%=int(1e9+7);
        else f[x]=1,sum[u]++;
    return sum[u];
}
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n>>l;
    for (int i=1;i<=l;i++)
    {
        int cnt;
        cin>>cnt;
        while (cnt--) {int tmp;cin>>tmp;G[i].push_back(tmp);}
    }
    solve(1);
    int ans=0;
    for (int i=1;i<=n;i++)
        ans+=f[i];
    cout<<sum[1]%int(1e9+7)<<" "<<ans<<endl;
}