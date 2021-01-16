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
    ll a[]={(read_one<buffersz>(args),0)...};
}
void ifastios()
{
    if(!dbg) ios::sync_with_stdio(0),cin.tie(0);
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
    if(firstrun) ifastios();
    if(cin.good())
        ll a[]={(cin>>args,0)...};
    return cin.good();
}
//pb_ds tree
#include <ext/pb_ds/assoc_container.hpp>
template<typename T>
using kthset=__gnu_pbds::tree<T,__gnu_pbds::null_type,greater<T>,__gnu_pbds::splay_tree_tag,__gnu_pbds::tree_order_statistics_node_update>;
template<typename T,typename U>
using kthmap=__gnu_pbds::tree<T,U,greater<T>,__gnu_pbds::splay_tree_tag,__gnu_pbds::tree_order_statistics_node_update>;
ll revpair(vector<pair<ll,ll>> &s)
{
    sort(s.begin(),s.end());
    static kthset<ll> t;t.clear();
    ll ans=0;
    for (auto x:s)
    {
        ans+=t.order_of_key(x.second);
        t.insert(x.second);
    }
    return ans;
}
int main()
{
    ll x,y,h,v;read(x,y,h,v);
    ll ans=(h+1)*(v+1);
    static vector<pair<ll,ll>> t;t.clear();
    for (ll i=1;i<=h;i++)
    {
        pair<ll,ll> x;
        read(x.first,x.second);
        t.emplace_back(x);
    }
    ans+=revpair(t);
    t.clear();
    for (ll i=1;i<=v;i++)
    {
        pair<ll,ll> x;
        read(x.first,x.second);
        t.emplace_back(x);
    }
    ans+=revpair(t);
    println(ans);
}