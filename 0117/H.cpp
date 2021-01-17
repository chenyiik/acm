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
int quota;
constexpr int maxn=3e4+5;
int T[maxn];
struct query_t
{
    int l,r,id;
    bool operator<(const query_t& b) const
    {
        return l/quota==b.l/quota?r<b.r:l<b.l;
    }
};
query_t query[maxn];
unordered_map<int,int> mp;
int ans[maxn],num[maxn],res;
void add(int x)
{
    mp[T[x]]++;
    num[mp[T[x]]]++;
    if (num[mp[T[x]]]==mp[T[x]]) res++;
}
void sub(int x)
{
    num[mp[T[x]]]--;
    if (num[mp[T[x]]]==mp[T[x]]-1) res--;
    mp[T[x]]--;
}
int main()
{
    int n,m;read(n,m);quota=(int)sqrt(n);
    for (int i=1;i<=n;i++) read(T[i]);
    for (int i=1;i<=m;i++)
    {
        read(query[i].l,query[i].r);query[i].id=i;
    }
    sort(query+1,query+1+m);
    int l=1,r=1;mp[T[1]]=1;res=1;num[1]=1;
    for (int i=1;i<=m;i++)
    {
        while (r<query[i].r) add(++r);
        while (r>query[i].r) sub(r--);
        while (l<query[i].l) sub(l++);
        while (l>query[i].l) add(--l);
        ans[query[i].id]=res;
    }
    for (int i=1;i<=m;i++) println(ans[i]);
}