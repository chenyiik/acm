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
    int n,ans=0;read(n);
    static bool ist[2050][2050];
    const double eps=1e-8;
    for (int i=1;i<=n;i++)
    {
        int x1,y1,x2,y2;
        read(x1,y1,x2,y2);
        if (x1==x2||y1==y2) continue;
        if (x1>x2) swap(x1,x2),swap(y1,y2);
        double k=double(y2-y1)/double(x2-x1);
        double b=double(y1)-k*double(x1);
        for (int x=x1;x<x2;x++)
        {
            double h1=k*x+b,h2=k*(x+1)+b;
            if (h1>h2) swap(h1,h2);
            int st=(h1+eps),en=(h2+1-eps);
            for (int l=st;l<en;l++) ist[x][l]=1;
        }
    }
    for (int x=0;x<=2000;x++)
        for (int y=0;y<=2000;y++) ans+=ist[x][y];
    println(ans);
}