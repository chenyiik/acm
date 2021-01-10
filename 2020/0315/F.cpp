#include<bits/stdc++.h>
using namespace std;
vector<int> G[100050];
int fa[100050];
int getfa(int x)
{
    return fa[x]==x?x:fa[x]=getfa(fa[x]);
}
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    int n,m;
    cin>>n>>m;
    static int tot=n,ans[100050];
    static pair<int,int> e[100050];
    for (int i=1;i<=m;i++)
    {
        cin>>e[i].first>>e[i].second;
        G[e[i].first].push_back(e[i].second);
        G[e[i].second].push_back(e[i].first);
    }
    static int seq[100050];
    for (int i=1;i<=m;i++) cin>>seq[i];
    for (int i=1;i<=n;i++) fa[i]=i;
    for (int i=m;i>=1;i--)
    {
        ans[i]=tot;
        int a=getfa(e[seq[i]].first),b=getfa(e[seq[i]].second);
        if (a!=b)
        {
            fa[b]=a;
            --tot;
        }
    }
    for (int i=1;i<=m;i++) cout<<ans[i]<<endl;
}