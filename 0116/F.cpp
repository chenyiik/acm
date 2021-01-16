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
constexpr auto maxtm=86400;
int main()
{
    struct show
    {
        int r,val,id;
    };
    static vector<show> shows[maxtm+10];
    static int f[1050][maxtm+10];
    memset(f,-1,sizeof(f));
    int n;read(n);
    for (int i=0;i<n;i++)
    {
        int m;read(m);
        while (m--)
        {
            int l,r,val;read(l,r,val);
            shows[l].push_back({.r=r,.val=val,.id=1<<i});
        }
    }
    for (int t=1;t<=maxtm;t++)
    {
        f[0][t]=0;
        for (int s=1;s<=(1<<n)-1;s++) f[s][t]=max(f[s][t],f[s][t-1]);
        for (auto [r,val,id]:shows[t])
            for (int s=0;s<=(1<<n)-1;s++)
            {
                if (f[s][t]==-1) continue;
                f[s|id][r]=max(f[s|id][r],f[s][t]+val);
            }
    }
    println(f[(1<<n)-1][maxtm]);
}