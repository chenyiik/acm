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
double l,x,y,vx,vy,h;
int k;
const double pi=acos(-1.0);
const double ang=2.0*pi/3.0;
struct point
{
    double x,y;
    point(double _x,double _y):x(_x),y(_y){}
    point operator+(const point& b) const
    {
        return point(x+b.x,y+b.y);
    }
};
inline point rotate(point a,double rad)
{
    return point(a.x*cos(rad)-a.y*sin(rad),a.x*sin(rad)+a.y*cos(rad));
}
bool check(double t)
{
    double num=0;
    point now=point(x+t*vx,y+t*vy);
    auto calc=[&](point p){return abs(floor(p.y/h));};
    num+=calc(now);
    num+=calc(rotate(now,ang)+point(0,h/2));
    num+=calc(rotate(now,ang*2)+point(0,h/2));
    return num>=k;
}
void doo()
{
    read(l,x,y,vx,vy,k);
    h=sqrt(3.0)/2.0*l;
    double xl=0,r=1e11;
    while (r-xl>1e-6)
    {
        double mid=(xl+r)/2;
        if (check(mid)) r=mid;else xl=mid;
    }
    println<10>((xl+r)/2);
}
signed main()
{
    int t;read(t);
    while (t--) doo();
}