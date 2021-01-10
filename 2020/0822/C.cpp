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
    static iint f[1000050];
    for (iint i=0;i<=1000050;i++) f[i]=-0x3f3f3f3f3f3f3f3fLL;
    f[50000]=0;
    iint n,m;read(n,m);
    static pair<iint,iint> b[2050];
    for (iint i=1;i<=n+m;i++)
    {
        read(b[i].first,b[i].second);
        if (i<=n) b[i].first=-b[i].first;
    }
    random_shuffle(b+1,b+n+m+1);
    for (iint i=1;i<=n+m;i++)
    {
        if (b[i].first>0)
        {
            for (iint j=100000;j>=b[i].first;j--)
                if (f[j-b[i].first]+b[i].second>f[j]) f[j]=f[j-b[i].first]+b[i].second;
        }
        else
        {
            for (iint j=0;j<=100000+b[i].first;j++)
                if (f[j-b[i].first]+b[i].second>f[j]) f[j]=f[j-b[i].first]+b[i].second;
        }
    }
    println(f[50000]);
}
signed main()
{
    iint t;read(t);
    while (t--) doo();
}