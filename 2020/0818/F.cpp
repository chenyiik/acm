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
using it=unsigned long long;
it fib[1000050<<1];
it doo()
{
    it a,b,c;
    a=b=c=0;
    it n;
    readint(n);
    for (it i=1;i<=n;i++)
    {
        bool x;readint(x);
        if (x) a+=fib[i];
    }
    readint(n);
    for (it i=1;i<=n;i++)
    {
        bool x;readint(x);
        if (x) b+=fib[i];
    }
    readint(n);
    static bool x[1000050<<1];
    for (it i=1;i<=n;i++)
    {
        readint(x[i]);
        if (x[i]) c+=fib[i];
    }
    it d=a*b;
    for (it i=1;i<n;i++)
        if (!x[i] && !x[i-1] && !x[i+1])
            if (c+fib[i]==d)
                return i;
    return 0;
}
signed main()
{
    fib[0]=1;fib[1]=1;
    for (it i=1;i<=1000000*2+10;i++) fib[i]=fib[i-1]+fib[i-2];
    int t;readint(t);
    while (t--) println(doo());
}