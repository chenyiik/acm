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
iint fa[100050];
iint find(iint x)
{
    if (fa[x]==x) return x;
    return fa[x]=find(fa[x]);
}
void doo()
{
    iint n,m;readint(n,m);
    static iint seq[100050];
    static vector<iint> G[100050];
    for (iint i=1;i<=n;i++) seq[i]=i,fa[i]=i,G[i].clear();
    static iint b[100050];
    for (iint i=1;i<=n;i++) readint(b[i]);
    for (iint i=1;i<=m;i++)
    {
        iint u,v;
        readint(u,v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    sort(seq+1,seq+1+n,[&](iint x,iint y){return b[x]>b[y];});
    for (iint i=1;i<=n;i++) fa[i]=i;
    iint ans=0;
    for (iint tu=1;tu<=n;tu++)
    {
        auto u=seq[tu];
        for (auto v:G[u])
        {
            if (b[v]<b[u]||b[u]==b[v] && find(u)==find(v)) continue;
            ans+=b[find(v)]-b[u];
            fa[find(v)]=u;
        }
    }
    for (iint i=1;i<=n;i++) if (find(i)==i) ans+=b[i];
    println(ans);
}
signed main()
{
    iint t;
    readint(t);
    while (t--) doo();
}