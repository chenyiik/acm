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
int main()
{
    static ld a[9][2];
    for (int i=0;i<9;i++) a[i][0]=1e9;
    int n;read(n);
    for (int i=1;i<=n;i++)
    {
        static ld x,y;read(x,y);
        complex<ld> v(x,y);
        for (int t=3;t<=8;t++)
        {
            static const double pi=acos(-1.0);
            ld ang=2.0*pi/t,la=abs(v),da=(pi-ang)/2,dc=arg(v);
            while (dc<0) dc+=ang;
            while (dc>ang) dc-=ang;
            ld db=pi-da-dc;ld lb=la*sin(db)/sin(da);
            a[t][0]=min(a[t][0],lb),a[t][1]=max(a[t][1],lb);
        }
    }
    int best=3;
    for (int t=3;t<=8;t++)
        if (a[best][0]/a[best][1]<a[t][0]/a[t][1]) best=t;
    println<10>(best,' ',(a[best][0]*a[best][0])/(a[best][1]*a[best][1]));
}