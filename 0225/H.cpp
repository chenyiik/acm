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
    ll a[]={(read_one<buffersz>(args),0)...};
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
    ll a[]={(cout<<args,0)...};
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
        ll a[]={(cin>>args,0)...};
    return cin.good();
}
int main()
{
    ll T;read(T);
    while (T--)
    {
        ll a,b,c,d;read(a,b,c,d);
        static auto fn=[&](){return a*a+b*b+c*c+min(a,min(b,c))*7;};
        ll ans=0;
        for (ll i=0;i<=min(d,(ll)1e3);i++)
            for (ll j=0;j<=min((ll)1e3,d-i);j++)
            {
                ll x=d-i-j;
                a+=i,b+=j,c+=x;ans=max(ans,fn());a-=i,b-=j,c-=x;
                a+=i,b+=x,c+=j;ans=max(ans,fn());a-=i,b-=x,c-=j;
                a+=x,b+=i,c+=j;ans=max(ans,fn());a-=x,b-=i,c-=j;
            }
        a+=d;ans=max(ans,fn());a-=d;
        b+=d;ans=max(ans,fn());b-=d;
        c+=d;ans=max(ans,fn());c-=d;
        println(ans);
    }
}