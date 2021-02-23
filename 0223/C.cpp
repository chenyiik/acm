#include<bits/stdc++.h>
using namespace std;
constexpr bool dbg=false;
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
    x=0;ll f=0;
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
inline void ifastios()
{
    static bool firstrun=true;
    if (!firstrun) return;
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
    ifastios();
    if(cin.good())
        int a[]={(cin>>args,0)...};
    return cin.good();
}
vector<int> G[100050];
bool tag[100050];
int sum[100050],ans,n,k;
void dfs(int u,int f)
{
    int cnt=0;
    for (auto x:G[u])
    if (x!=f)
    {
        dfs(x,u);
        sum[u]+=sum[x];
        if (sum[x]) ++cnt;
    }
    if (sum[u]<k) ++cnt;
    if (cnt>=2 && !tag[u]) ++ans;
}
int main()
{
    read(n,k);
    for (int i=1;i<n;i++)
    {
        int u,v,w;read(u,v,w);
        G[u].push_back(v);G[v].push_back(u);
    }
    for (int i=1;i<=k;i++)
    {
        int x;read(x);++ans;
        tag[x]=1;sum[x]=1;
    }
    dfs(1,-1);println(ans);
}