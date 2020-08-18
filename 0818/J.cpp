#include<bits/stdc++.h>
using namespace std;
constexpr auto of=true;
using iint=conditional<of,long long,signed>::type;
using idouble=conditional<of,long double,double>::type;
constexpr bool dbg=true;
template<iint buffersz>
inline char igetchar()
{
    static char buf[buffersz],*p1=buf,*p2=buf;
    return p1==p2 && (p2=(p1=buf)+fread(buf,1,buffersz,stdin),p1==p2)?EOF:*p1++;
}
template<iint buffersz,class T>
void read_one(T&x)
{
    static_assert(is_convertible<char,T>::value,"Not supporting type");
    x=0;
    iint f=0;
    char ch=igetchar<buffersz>();
    while(!isdigit(ch)) f|=(ch=='-'),ch=igetchar<buffersz>();
    while(isdigit(ch)) x=(x<<1)+(x<<3)+(ch^48),ch=igetchar<buffersz>();
    x=f?-x:x;
}
void readint()
{}
template<iint buffersz=dbg?1:(iint)1e4,typename T,typename... U>
void readint(T&arg,U&... args)
{
    static_assert(is_convertible<char,T>::value,"Not supporting type");
    read_one<buffersz>(arg);
    readint(args...);
}
bool firstrun=true;
decltype(cout.flags()) st;
void ifastios()
{
    if(!dbg) ios::sync_with_stdio(0),cin.tie(0);
    firstrun=false;
}
void print()
{}
template<iint precision=-1,typename T,typename... U>
void print(T&&arg,U&&... args)
{
    if(precision>=0)
    {
        st=cout.flags();
        cout.setf(ios::fixed);
        cout.precision(precision);
    }
    if(firstrun) ifastios();
    cout<<forward<T>(arg);
    print(args...);
    if(precision>=0) cout.flags(st);
}
template<iint precision=-1,typename T,typename... U>
void println(T&&arg,U&&... args)
{
    print<precision>(forward<T>(arg),forward<U>(args)...,'\n');
}
void read()
{}
template<typename T,typename... U>
void read(T&arg,U&... args)
{
    if(firstrun) ifastios();
    cin>>arg;
    read(args...);
}
void doo()
{
    static vector<tuple<iint,iint,iint,iint>> vec[55];
    iint n,m;read(n,m);
    for (iint i=1;i<=m;i++) vec[i].clear();
    iint ans=0;
    for (iint t,a,b,c,d,i=1;i<=n;i++)
    {
        read(t,a,b,c,d);
        vec[t].push_back(make_tuple(a,b,c,d));
    }
    function<void(iint,iint,iint,iint,iint)> dfs=[&](iint t,iint a,iint b,iint c,iint d)
    {
        if (!t){
            ans=max(ans,a*b*c*d);
            return;
        }
        if (vec[t].empty()) dfs(t-1,a,b,c,d);
        for (auto x:vec[t])
            dfs(t-1,get<0>(x)+a,get<1>(x)+b,get<2>(x)+c,get<3>(x)+d);
    };
    dfs(m,100,100,100,100);
    println(ans);
}
signed main()
{
    iint t;read(t);
    while (t--) doo();
}