#include<bits/stdc++.h>
using namespace std;
vector<int> G[100050];
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    int n,m;
    cin>>n>>m;
    for (int i=1;i<=m;i++)
    {
        int u,v;
        cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    int t;
    cin>>t;
    for (int d=1;d<=t;d++)
    {
        int dead;cin>>dead;
        static set<int> ans;
        static bool vis[100050];
        if (d==1)
        {
            for (auto v:G[dead]) ans.insert(v),vis[v]=1;
        }else
        {
            for (auto v:G[dead]) vis[v]=1;
            if (vis[dead])
            {
                if (ans.count(dead)) ans.erase(dead);
            }else
            {
                static set<int> tmp;
                tmp.clear();
                for (auto x:G[dead])
                    if (ans.count(x)) tmp.insert(x);
                swap(ans,tmp);
            }
        }
        if (ans.size()==1)
        {
            cout<<d<<" "<<*ans.begin()<<endl;
            return 0;
        }
    }
    cout<<-1<<endl;
}