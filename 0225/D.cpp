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
    ll wds;read(wds);
    static string wd[22];
    for (ll i=1;i<=wds;i++) read(wd[i]);
    ll trans;read(trans);
    static unordered_map<string,string> tran;
    static unordered_map<string,ll> cor,incor;
    for (ll i=1;i<=trans;i++)
    {
        string helan,english,verdict;
        read(helan,english,verdict);
        tran[helan]=english;
        if (verdict.front()=='c') cor[helan]++;else incor[helan]++;
    }
    ll all=1,c=1;
    for (ll i=1;i<=wds;i++)
        all*=cor[wd[i]]+incor[wd[i]],c*=cor[wd[i]];
    if (all==1)
    {
        for (ll i=1;i<=wds;i++) print(tran[wd[i]],' ');print('\n');
        println(vector<string>({"in",""})[c],"correct");
    }
    else println(c," correct\n",all-c," incorrect");
}