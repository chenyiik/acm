#include<bits/stdc++.h>
using namespace std;
constexpr auto of=true;
using iint=conditional_t<of,long long,signed>;
using idouble=conditional_t<of,long double,double>;
constexpr bool dbg=false;
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
    if (precision>=0)
    {
        st=cout.flags();
        cout.setf(ios::fixed);
        cout.precision(precision);
    }
    if(firstrun) ifastios();
    cout<<forward<T>(arg);
    print(args...);
    if (precision>=0) cout.flags(st);
}
template<iint precision=-1,typename T,typename... U>
void println(T&&arg,U&&... args)
{
    print<precision>(forward<T>(arg),forward<U>(args)...,'\n');
}
bool read()
{return cin.good();}
template<typename T,typename... U>
bool read(T&arg,U&... args)
{
    if(firstrun) ifastios();
    if (!cin.good()) return cin.good();
    cin>>arg;
    return cin.good() && read(args...);
}
signed main()
{
    int n;
    while (read(n))
    {
        static int d[1050][1050];
        int mn=0x3f3f3f3f;
        for (int i=1;i<=n;i++)
            for (int j=1;j<=n;j++) {read(d[i][j]);if (i^j) mn=min(mn,d[i][j]);}
        int c=0;
        for (int i=1;i<n;i++)
            for (int j=i+1;j<=n;j++)
                c+=(d[i][j]==mn);
        println(c);
    }
}