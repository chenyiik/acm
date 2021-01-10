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
    if (x==fa[x]) return x;
    return fa[x]=find(fa[x]);
}
iint sza[100050],szb[100050];
iint ans=0,a,b;
void merge(iint x,iint y)
{
    iint fx=find(x),fy=find(y);
    if (fx!=fy)
    {
        fa[fx]=fy;
        iint a1=sza[fx],a2=sza[fy];
        iint b1=szb[fx],b2=szb[fy];
        ans-=b1*b2*(a-a1-a2)+(b1*b2+a1*b2+b1*a2)*(b-b1-b2);
        sza[fy]+=sza[fx];
        szb[fy]+=szb[fx];
    }
}
constexpr iint modl=1e9+7;
void doo()
{
    iint n;read(n);
    a=b=ans=0;
    for (iint i=1;i<=n;i++)
    {
        iint t;read(t);
        a+=(t&1)?1:0;sza[i]=(t&1)?1:0;
        b+=(t&1)?0:1;szb[i]=(t&1)?0:1;
        fa[i]=i;
    }
    if (b>=1) ans+=b*(b-1)*a/2;
    if (b>=2) ans+=b*(b-1)*(b-2)/6;
    println(ans%modl);
    for (iint i=1;i<n;i++)
    {
        iint x,y;read(x,y);
        merge(x,y);
        println(ans%modl);
    }
}
signed main()
{
    iint t;read(t);
    while (t--) doo();
}