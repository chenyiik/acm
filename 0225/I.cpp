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
struct appt
{
    ll d,s,id;
    bool operator<(const appt& b) const {return d-s<b.d-b.s;}
};
int main()
{
    ll n,c;read(n,c);
    static appt app[505];
    for (ll i=1;i<=n;i++) {ll d,s;read(d,s);app[i]={d,s,i};}
    sort(app+1,app+1+n);
    static ll f[10050];
    static vector<ll> route[10050];
    for (ll i=1;i<=n;i++)
    {
        for (ll j=c;j>=max(app[i].d,app[i].s);j--)
        {
            if (f[j]<f[j-app[i].s]+1)
            {
                f[j]=f[j-app[i].s]+1;
                route[j]=route[j-app[i].s];
                route[j].push_back(app[i].id);
            }
        }
    }
    ll mx=max_element(f+1,f+1+c)-f;
    println(f[mx]);
    reverse(route[mx].begin(),route[mx].end());
    for (auto x:route[mx]) print(x," ");
}