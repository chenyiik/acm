#include<bits/stdc++.h>
using namespace std;
map<string,int> algo2i;
map<vector<int>,int > stu2i;
vector<int> teacher[105];
vector<int> e[150005<<1],G[150005<<1];
int all=0,pcnt=0,n;
int match[150005<<1],used[150005<<1],dist[150005<<1];
/*
bool find(int u)
{
    for (auto x:G[u])
        if (!used[x])
        {
            used[x]=1;
            if (match[x]==0||find(match[x]))
            {
                match[x]=u;
                return true;
            }
        }
    return false;
}
int solve()
{
    int ans=0;
    for (int i=1;i<=n;i++)
    {
        memset(used,0,sizeof(used));
        if (find(i)) ++ans;
    }
    return ans;
}*/
bool bfs()
{
    queue<int> q;
    for (int i=1;i<=n;i++)
    {
        if (!match[i]) dist[i]=0,q.push(i);else dist[i]=0x3f3f3f3f;
    }
    dist[0]=0x3f3f3f3f;
    while (!q.empty())
    {
        int u=q.front();q.pop();
        if (!u) continue;
        for (auto x:G[u])
        {
            if (dist[match[x]]==0x3f3f3f3f)
            {
                dist[match[x]]=dist[u]+1;
                q.push(match[x]);
            }
        }
    }
    return dist[0]!=0x3f3f3f3f;
}
bool dfs(int u)
{
    if (!u) return 1;
    for (auto x:G[u])
    {
        if (dist[match[x]]==dist[u]+1 && dfs(match[x]))
        {
            match[x]=u;match[u]=x;
            return 1;
        }
    }
    dist[u]=0x3f3f3f3f;
    return 0;
}
int solve()
{
    int ans=0;
    while (bfs())
    {
        for (int i=1;i<=n;i++)
            if (!match[i]) ans+=dfs(i);
    }
    return ans;
}
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        int cnt;cin>>cnt;
        while (cnt--)
        {
            string algo;cin>>algo;
            if (!algo2i.count(algo)) algo2i[algo]=++all;
            teacher[i].push_back(algo2i[algo]);
        }
        sort(teacher[i].begin(),teacher[i].end());
    }
    for (int i=1;i<=n;i++)
    {
        int allc=1<<(teacher[i].size());
        for (int ch=1;ch<allc;ch++)
        {
            vector<int> stu;
            for (int j=0;j<teacher[i].size();j++)
                if (ch & (1<<j)) stu.push_back(teacher[i][j]);
            if (!stu2i.count(stu)) stu2i[stu]=++pcnt;
        }
    }
    for (int i=1;i<=n;i++)
    {
        int sz=teacher[i].size();
        for (int ch=1;ch<(1<<sz);ch++)
        {
            vector<int> stu;
            for (int j=0;j<teacher[i].size();j++)
                if (ch & (1<<j)) stu.push_back(teacher[i][j]);
            int u=stu2i[stu];
            for (int dd=ch;dd;dd=ch&(dd-1))
            {
                if (dd==ch) continue;
                stu.clear();
                for (int j=0;j<teacher[i].size();j++)
                    if (dd & (1<<j)) stu.push_back(teacher[i][j]);
                int v=stu2i[stu];
                e[v].push_back(u);
            }
        }
    }
    n=pcnt;
    for (int i=1;i<=n;i++)
        for (auto x:e[i]) G[i].push_back(x+n);
    cout<<n-solve()<<endl;
}