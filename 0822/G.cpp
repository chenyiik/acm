#include<bits/stdc++.h>
using namespace std;
constexpr auto of=true;
using iint=conditional<of,long long,signed>::type;
using idouble=conditional<of,long double,double>::type;
constexpr bool dbg=!true;
template<int buffersz>
inline char igetchar()
{
    static char buf[buffersz],*p1=buf,*p2=buf;
    return p1==p2 && (p2=(p1=buf)+fread(buf,1,buffersz,stdin),p1==p2)?EOF:*p1++;
}
template<int buffersz,class T>
void read_one(T&x)
{
    static_assert(is_convertible<char,T>::value,"Not supporting type");
    x=0;
    int f=0;
    char ch=igetchar<buffersz>();
    while(!isdigit(ch)) f|=(ch=='-'),ch=igetchar<buffersz>();
    while(isdigit(ch)) x=(x<<1)+(x<<3)+(ch^48),ch=igetchar<buffersz>();
    x=f?-x:x;
}
void readint()
{}
template<int buffersz=dbg?1:(int)1e4,typename T,typename... U>
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
template<int precision=-1,typename T,typename... U>
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
template<int precision=-1,typename T,typename... U>
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
int match[100050],vis[100050];
vector<int> G[200050];
bool dfs(int u)
{
    for(auto v:G[u])
    {
        if(vis[v]) continue;
        vis[v]=1;
        if(!match[v] || dfs(match[v]))
        {
            match[v]=u;
            return true;
        }
    }
    return false;
}
map<int,int> l,r;
void doo()
{
    int n;readint(n);
    for (int i=1;i<=n;i++) G[i].clear();
    l.clear();r.clear();
    int lcnt=0,rcnt=0;
    for (int i=1;i<=n;i++)
    {
        int x,t;readint(t,x);
        if (!l[x-t]) l[x-t]=++lcnt;
        if (!r[x+t]) r[x+t]=++rcnt;
        G[l[x-t]].push_back(r[x+t]);
        match[i]=0;
    }
    int ans=0;
    for (int i=1;i<=lcnt;i++)
    {
        memset(vis,0,sizeof(int)*(rcnt+1));
        ans+=dfs(i);
    }
    println(ans);
}
signed main()
{
    int t;readint(t);
    while (t--) doo();
}