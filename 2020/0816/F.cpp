#include<bits/stdc++.h>
using namespace std;
constexpr auto of=true;
using iint=conditional<of,long long,signed>::type;
using idouble=conditional<of,long double,double>::type;
constexpr bool dbg=!true;
template<iint buffersz>
inline char igetchar()
{
    static char buf[buffersz],*p1=buf,*p2=buf;
    return p1==p2 && (p2=(p1=buf)+fread(buf,1,buffersz,stdin),p1==p2)?EOF:*p1++;
}
template<iint buffersz,class T>
void read_one(T&x)
{
    static_assert(is_convertible<char,T>::value,"Not supporting type");
    x=0;
    iint f=0;
    char ch=igetchar<buffersz>();
    while(!isdigit(ch)) f|=(ch=='-'),ch=igetchar<buffersz>();
    while(isdigit(ch)) x=(x<<1)+(x<<3)+(ch^48),ch=igetchar<buffersz>();
    x=f?-x:x;
}
void readint()
{}
template<iint buffersz=dbg?1:(iint)1e4,typename T,typename... U>
void readint(T&arg,U&... args)
{
    static_assert(is_convertible<char,T>::value,"Not supporting type");
    read_one<buffersz>(arg);
    readint(args...);
}
bool firstrun=true;
decltype(cout.flags()) st;
void ifastios()
{
    if(!dbg) ios::sync_with_stdio(0),cin.tie(0);
    firstrun=false;
}
void print()
{}
template<iint precision=-1,typename T,typename... U>
void print(T&&arg,U&&... args)
{
    if(precision>=0)
    {
        st=cout.flags();
        cout.setf(ios::fixed);
        cout.precision(precision);
    }
    if(firstrun) ifastios();
    cout<<forward<T>(arg);
    print(args...);
    if(precision>=0) cout.flags(st);
}
template<iint precision=-1,typename T,typename... U>
void println(T&&arg,U&&... args)
{
    print<precision>(forward<T>(arg),forward<U>(args)...,'\n');
}
void read()
{}
template<typename T,typename... U>
void read(T&arg,U&... args)
{
    if(firstrun) ifastios();
    cin>>arg;
    read(args...);
}
void doo()
{
    int n,m;read(n,m);
    static int a[100050];
    for (int i=1;i<=n;i++) read(a[i]);
    static vector<int> G[100050],cnt[100050];
    static int mex[100050];
    for (int i=1;i<=n;i++) mex[i]=0,G[i].clear(),cnt[i].clear();
    for (int i=1;i<=m;i++)
    {
        int u,v;
        read(u,v);
        G[u].push_back(v);G[v].push_back(u);
    }
    for (int i=1;i<=n;i++)
    {
        sort(begin(G[i]),end(G[i]));
        G[i].erase(unique(begin(G[i]),end(G[i])),end(G[i]));
    }
    for (int i=1;i<=n;i++)
    {
        sort(begin(G[i]),end(G[i]),[=](int x,int y){return G[x].size()<G[y].size();});
        cnt[i].resize(G[i].size()+1,0);
    }
    auto add=[&](int u,int x)
    {
        cnt[u][x]++;
        int now=mex[u];
        while (cnt[u][now]) now++;
        mex[u]=now;
    };
    for (int i=1;i<=n;i++)
    {
        for (int j=G[i].size()-1;j>=0;j--)
        {
            auto v=G[i][j];
            if (G[v].size()<=a[i]) break;
            add(v,a[i]);
        }
    }
    int q;read(q);
    auto del=[&](int u,int x)
    {
        cnt[u][x]--;
        if (cnt[u][x]==0) mex[u]=min(mex[u],x);
    };
    while (q--)
    {
        int op;read(op);
        if (op&1)
        {
            int u,x;read(u,x);
            if (G[u].size())
            {
                for (int i=G[u].size()-1;i>=0;i--)
                {
                    int v=G[u][i];
                    if (G[v].size()<=a[u]) break;
                    del(v,a[u]);
                }
                for (int i=G[u].size()-1;i>=0;i--)
                {
                    int v=G[u][i];
                    if (G[v].size()<=x) break;
                    add(v,x);
                }
            }
            a[u]=x;
        }
        else
        {
            int u;read(u);
            println(mex[u]);
        }
    }
}
signed main()
{
    int t;read(t);
    while(t--) doo();
}