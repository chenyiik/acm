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
iint G[55][55],n,k,ans;
iint route[55][55];
iint spfa(iint k)
{
    static iint dist[55],inq[55];
    for (iint i=1;i<=n;i++) dist[i]=0x3f3f3f3f,inq[i]=0,route[k][i]=-1;
    static deque<iint> q;q.clear();
    iint s=1;
    dist[s]=0;q.push_back(s);inq[s]=1;
    while (q.size())
    {
        auto u=q.front();q.pop_front();
        inq[u]=0;
        for (iint v=1;v<=n;v++)
            if (u!=v && dist[v]>dist[u]+G[u][v])
            {
                route[k][v]=u;
                dist[v]=dist[u]+G[u][v];
                if(!inq[v])
                {
                    inq[v]=1;
                    if (q.empty()||dist[v]>dist[q.front()]) q.push_back(v);
                    else q.push_front(v);
                }
            }
    }
    return dist[n];
}
void solve(iint k)
{
    if(k==0)
    {
        ans=max(ans,spfa(k));
        return;
    }
    iint t=spfa(k),v=n;
    while (~route[k][v])
    {
        iint u=route[k][v];
        iint t=G[u][v];
        G[u][v]=G[v][u]=0x3f3f3f3f;
        solve(k-1);
        G[u][v]=G[v][u]=t;
        v=u;
    }
}
void doo()
{
    readint(n,k);
    for (iint i=1;i<=n*(n-1)/2;i++)
    {
        iint u,v,w;readint(u,v,w);
        G[u][v]=G[v][u]=w;
    }
    ans=0;
    solve(k);
    println(ans);
}
signed main()
{
    iint t;readint(t);
    while (t--) doo();
}