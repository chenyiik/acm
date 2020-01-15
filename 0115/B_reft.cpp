#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,k;
    cin>>n>>k;
    vector<int> ans,v;
    unordered_map<int,bool> vis;
    unordered_map<int,int> las;
    for (int i=1;i<=n;i++)
    {
        int tmp;
        cin>>tmp;
        las[tmp]=i;
        v.push_back(tmp);
    }
    for (int i=0;i<n;i++)
    if (!vis[v[i]])
    {
        while (!ans.empty() && v[i]<ans[ans.size()-1] && i<las[ans[ans.size()-1]])
        {
            vis[ans[ans.size()-1]]=0;
            ans.pop_back();
        }
        vis[v[i]]=1;
        ans.push_back(v[i]);
    }
    for (auto x:ans) cout<<x<<" ";
}