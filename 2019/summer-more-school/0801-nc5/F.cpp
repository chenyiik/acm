#include<bits/stdc++.h>
using namespace std;
int a[5050];
int n;
inline int read()
{
    int f=1,x=0;char ch=getchar();
    while(!isdigit(ch)) {if (ch=='-') f=-1;ch=getchar();}
    while (isdigit(ch)) {x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
inline void print(int x)
{
    if (x<0) {putchar('-');x=-x;}
    if (x>9) print(x/10);
    putchar(x%10+'0');
}
inline void println(int x)
{
    print(x);putchar('\n');
}
int match[5050];
bool used[5050];
bool inans[5050];
vector<int> G[5050];
bool dfs(int u)
{
    inans[u]=1;
    for (auto v:G[u])
    {
        if (used[v]) continue;
        used[v]=1;
        if (match[v]==0||dfs(match[v]))
        {
            match[v]=u;
            return true;
        }
    }
    return false;
}
void hungary(int n)
{
    bool ismatch[5050];
    for (int i=1;i<=n;i++) {
        memset(used, 0, sizeof(used));
        ismatch[i] = dfs(i);
    }
    memset(used,0,sizeof(used));
    memset(inans,0,sizeof(inans));
    for (int i=1;i<=n;i++) if (!ismatch[i]) dfs(i);
    vector<int> ans;
    for (int i=1;i<=n;i++)
        if (__builtin_parity(a[i])==1 && inans[i]) ans.push_back(a[i]);
    for (int i=1;i<=n;i++)
        if (__builtin_parity(a[i])==0 && !used[i]) ans.push_back(a[i]);
    println(ans.size());
    for (auto x:ans) {print(x);putchar(' ');}
}
int main()
{
    n=read();
    for (int i=1;i<=n;i++) a[i]=read();
    for (int i=1;i<=n;i++)
        for (int j=i+1;j<=n;j++)
        {
            int diff=a[i]^a[j];
            if (__builtin_popcount(diff)==1)
                if (__builtin_parity(a[i]))
                G[i].push_back(j);
                else G[j].push_back(i);

        }
    hungary(n);
    return 0;
}