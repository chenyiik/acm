#include<bits/stdc++.h>
using namespace std;
vector<int> G[100050];
int outd[100050];
double days[100050],ans[100050];
double dfsdays(int p)
{
    if (days[p]!=0||outd[p]==0) return days[p];
    double sump=0;
    for (auto x:G[p])
        sump+=dfsdays(x);
    return days[p]=sump/(1.0*outd[p])+1.0+1.0/(1.0*outd[p]);
}
double dfsans(int p)
{
    if (ans[p]!=0||outd[p]==0) return ans[p];
    double sump=0;
    for (auto x:G[p])
        sump+=dfsans(x);
    return ans[p]=sump/(1.0*outd[p])+days[p]+days[p]/(1.0*outd[p]);
}
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    int T;
    cin>>T;
    while (T--)
    {
        int n,m;
        cin>>n>>m;
        for (int i=1;i<=n;i++) G[i].clear();
        for (int i=1;i<=m;i++)
        {
            int u,v;
            cin>>u>>v;
            G[u].push_back(v);
        }
        for (int i=1;i<=n;i++) outd[i]=G[i].size();
        memset(days,0,sizeof(days));
        double ds=dfsdays(1);
        memset(ans,0,sizeof(ans));
        cout<<fixed<<setprecision(2)<<dfsans(1)<<endl;
    }
}