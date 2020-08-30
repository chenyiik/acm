#include<bits/stdc++.h>
using namespace std;
constexpr auto of=true;
using iint=conditional<of,long long,signed>::type;
using idouble=conditional<of,long double,double>::type;
constexpr bool dbg=!true;
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
iint a[5000050],n;
string s;
const iint ba=12289;
iint p[5000050];
const iint sz=12582917;
iint mp[sz+5];
iint gethash(iint l,iint r)
{
    return (a[r]-a[l-1]*p[r-l+1]%sz+sz)%sz;
}
bool chk(iint k,iint id)
{
    if (k==1) return 0;
    iint len=n/k;
    iint l=1,r=len;
    mp[gethash(1,len)]=id;
    for (iint i=1;i<len;i++)
        mp[(gethash(i+1,len)*p[i]%sz+gethash(1,i)%sz+sz)%sz]=id;
    for (iint i=1;i<=k;i++)
    {
        iint tmp=gethash(l,r);
        if (mp[tmp]!=id) return 0;
        l+=len,r+=len;
    }
    return 1;
}
void doo()
{
    read(n);
    read(s);s="0"+s;
    for (iint i=1;i<=n;i++)
        a[i]=(a[i-1]*ba%sz+(s[i]-'a'+1)+sz)%sz;
    bool flg=0;
    static iint tot;
    for (iint i=1;i*i<=n && !flg;i++)
    if (n%i==0)
    {
        flg=flg||chk(i,++tot);
        flg=flg||chk(n/i,++tot);
    }
    println(vector<string>({"No","Yes"})[flg]);
}
signed main()
{
    p[0]=1;
    for (iint i=1;i<=5000005;i++) p[i]=p[i-1]*ba%sz;
    iint t;read(t);
    while (t--) doo();
}