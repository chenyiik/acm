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
ll a[1000050],ans;
vector<ll> pi,pj;
void get(ll lj,ll rj,ll li,ll ri)
{
    ll mid=(lj+rj)>>1;if (lj>rj) return;
    ll mx=0,pos=-1;
    for (ll i=li;i<=ri;i++)
    if (pj[mid]>pi[i])
    {
        ll tmp=(a[pi[i]]+a[pj[mid]])*(pj[mid]-pi[i]);
        if (tmp>mx){mx=tmp;pos=i;}
    }
    if (pos==-1) return;
    ans=max(ans,mx);
    get(lj,mid-1,li,pos);
    get(mid+1,rj,pos,ri);
}
int main()
{
    ll n;read(n);
    for(ll i=1;i<=n;i++) read(a[i]);
    ll mx=0;
    for (ll i=1;i<=n;i++)
        if (a[i]>mx)
        {
            mx=a[i];pi.push_back(i);
        }
    mx=0;
    for (ll i=n;i>=1;i--)
        if (a[i]>mx)
        {
            mx=a[i];pj.push_back(i);
        }
    reverse(pj.begin(),pj.end());
    get(0,pj.size()-1,0,pi.size()-1);
    println(ans);
}