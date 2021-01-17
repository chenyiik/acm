#include<bits/stdc++.h>
using namespace std;
constexpr bool dbg=false;
bool firstrun=true;
using ll=long long;
using ld=long double;
template<ll buffersz>
inline char igetchar()
{
    static char buf[buffersz],*p1=buf,*p2=buf;
    return p1==p2 && (p2=(p1=buf)+fread(buf,1,buffersz,stdin),p1==p2)?EOF:*p1++;
}
template<ll buffersz,typename T>
void read_one(T&x)
{
    static_assert(is_convertible<char,T>::value,"Not supporting type");
    x=0;
    ll f=0;
    char ch=igetchar<buffersz>();
    while(!isdigit(ch)) f|=(ch=='-'),ch=igetchar<buffersz>();
    while(isdigit(ch)) x=(x<<1)+(x<<3)+(ch^48),ch=igetchar<buffersz>();
    x=f?-x:x;
}
template<ll buffersz=dbg?1:(ll)1e4,typename... U>
void readint(U&... args)
{
    int a[]={(read_one<buffersz>(args),0)...};
}
void ifastios()
{
    if constexpr(!dbg) ios::sync_with_stdio(0),cin.tie(0);
    firstrun=false;
}
template<ll precision=-1,typename... U>
void print(U&&... args)
{
    auto st=cout.flags();
    if constexpr(precision>=0)
    {
        cout.setf(ios::fixed);
        cout.precision(precision);
    }
    int a[]={(cout<<args,0)...};
    if constexpr(precision>=0) cout.flags(st);
}
template<ll precision=-1,typename... U>
void println(U&&... args)
{
    print<precision>(forward<U>(args)...,'\n');
}
template<typename... U>
bool read(U&... args)
{
    if(firstrun) ifastios();
    if(cin.good())
        int a[]={(cin>>args,0)...};
    return cin.good();
}
constexpr int maxn=3e5+5;
int T[maxn];
vector<int> G[maxn];
bool vis[maxn];
vector<pair<int,int>> ans;
void dfs(int u,int p)
{
    vis[u]=1;
    for (auto v:G[u])
        if (!vis[v]) dfs(v,u);
    if (u^p && T[u])
    {
        ans.emplace_back(make_pair(p,u));
        T[u]=0;T[p]^=1;
    }
}
int main()
{
    int n,m,k;read(n,m,k);
    for (int i=1;i<=m;i++)
    {
        int u,v;read(u,v);
        T[u]^=1,T[v]^=1;
    }
    for (int i=1;i<=k;i++)
    {
        int u,v;read(u,v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    for (int i=1;i<=n;i++)
        if (!vis[i])
        {
            dfs(i,i);
            if (T[i]) return println("NO"),0;
        }
    println("YES");
    println(ans.size());
    for (auto [u,v]:ans) println(u," ",v);
}