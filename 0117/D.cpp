#include<bits/stdc++.h>
using namespace std;
constexpr bool dbg=false;
bool firstrun=true;
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
    static_assert(is_convertible<char,T>::value,"Not supporting type");
    x=0;
    ll f=0;
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
void ifastios()
{
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
    if(firstrun) ifastios();
    if(cin.good())
        int a[]={(cin>>args,0)...};
    return cin.good();
}
int main()
{
    struct peo
    {
        int x,y;
        char t;
    };
    static peo p[1000050];
    int n;
    read(n);
    static int _x[1000050],_y[1000050],sw=0,sb=0;
    for(int i=1;i<=n;i++)
    {
        string stmp;
        read(p[i].x,p[i].y,stmp);
        p[i].t=stmp[0];
        _x[i]=p[i].x,_y[i]=p[i].y;
        sw+=p[i].t=='w';
        sb+=p[i].t!='w';
    }
    sort(_x+1,_x+1+n);
    sort(_y+1,_y+1+n);
    int szx=unique(_x+1,_x+1+n)-_x-1,szy=unique(_y+1,_y+1+n)-_y-1;
    for(int i=1;i<=n;i++) p[i].x=lower_bound(_x+1,_x+1+szx,p[i].x)-_x,p[i].y=lower_bound(_y+1,_y+1+szy,p[i].y)-_y;
    static int w[1000050],b[1000050];
    int ans=0,cw=0,cb=0;memset(w,0,sizeof(w));memset(b,0,sizeof(b));
    for (int i=1;i<=n;i++)
        if (p[i].t=='w') w[p[i].x]++;else b[p[i].x]++;
    for (int i=1;i<=szx;i++)
    {
        cw+=w[i],cb+=b[i];
        ans=max(ans,cw+(sb-cb));
        ans=max(ans,cb+(sw-cw));
    }
    cw=cb=0;memset(w,0,sizeof(w));memset(b,0,sizeof(b));
    for (int i=1;i<=n;i++)
        if (p[i].t=='w') w[p[i].y]++;else b[p[i].y]++;
    for (int i=1;i<=szy;i++)
    {
        cw+=w[i],cb+=b[i];
        ans=max(ans,cw+(sb-cb));
        ans=max(ans,cb+(sw-cw));
    }
    println(ans);
}