#include<bits/stdc++.h>
using namespace std;
vector<string> s[2];
int divide(const string& str)
{
    int cnt=0;
    for (int i=0;i<str.size();i++)
        for (int j=i+1;j<str.size();j++)
            if (str[i]>str[j]) ++cnt;
    return cnt&1;
}
int conn(const string& a,const string& b)
{
    int cnt=0;
    for (int i=0;i<a.size();i++) cnt+=a[i]!=b[i];
    return cnt==2;
}
int G[505][505];
bool vis[505];
int n,l,r;
int match[505];
bool dfs(int x)
{
    for (int j=0;j<r;j++)
        if (G[x][j] && !vis[j])
        {
            vis[j]=true;
            if (match[j]==-1 || dfs(match[j]))
            {
                match[j]=x;
                return true;
            }
        }
    return false;
}
int find()
{
    l=s[0].size(),r=s[1].size();
    int ans=0;
    memset(match,-1,sizeof(match));
    for (int i=0;i<l;i++)
    {
        memset(vis,0,sizeof(vis));
        if (dfs(i))
        {
            ++ans;
        }
    }
    return ans;
}
int main()
{
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        string str;
        cin>>str;
        int wh=divide(str);
        s[wh].emplace_back(str);
    }
    for (int i=0;i<s[0].size();i++)
        for (int j=0;j<s[1].size();j++)
            G[i][j]=conn(s[0][i],s[1][j]);
    cout<<n-find()<<endl;
}