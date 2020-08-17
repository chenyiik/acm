#include<bits/stdc++.h>
using namespace std;
bool notlink[10][10];
int conn[10][10];
int n;
bool vis[10];
int go[10];
bool succ(int dep)
{
    int mask=0;
    for (int i=0;i<dep-1;i++)
        mask|=conn[go[i]][go[i+1]];
    if (mask!=(1<<n)-1) return false;
    for (int i=0;i<dep-1;i++)
        if (notlink[go[i]][go[i+1]]) return false;
    if (dep==0) return false;
    return true;
}
int ans=0;
void dfs(int dep)
{
    if (dep>10) return;
    for (int i=1;i<=9;i++)
        if (!vis[i])
        {
            vis[i]=1;
            go[dep]=i;
            dfs(dep+1);
            vis[i]=0;
        }
    if (dep>=2)
        ans+=succ(dep);
}
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    memset(notlink,0,sizeof(notlink));
    notlink[1][3]=notlink[3][1]=notlink[4][6]=notlink[6][4]=notlink[7][9]=notlink[9][7]=true;
    notlink[1][7]=notlink[7][1]=notlink[2][8]=notlink[8][2]=notlink[3][9]=notlink[9][3]=true;
    notlink[1][9]=notlink[9][1]=notlink[3][7]=notlink[7][3]=true;
    cin>>n;
    memset(conn,0,sizeof(conn));
    for (int i=1;i<=n;i++)
    {
        int u,v;
        cin>>u>>v;
        conn[u][v]=conn[v][u]=1<<(i-1);
    }
    dfs(0);
    cout<<ans<<endl;
}