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
    string s1,s2;
    read(s1,s2);
    int n=s1.size(),m=s2.size();
    s1='['+s1;
    s2='['+s2;
    static int G[100050][26];
    memset(G,0x3f,sizeof(G));
    for (int i=n;i>=1;i--)
    {
        for (int j=0;j<=25;j++)
            G[i][j]=G[i+1][j];
        G[i][s1[i]-'a']=i;
    }
    int q;read(q);
    while (q--)
    {
        int l,r;read(l,r);
        static int f[25][25];
        int ans=0;
        for (int i=0;i<=m;i++)
        {
            for (int j=1;j<=m;j++) f[i][j]=100005;
            f[i][0]=l;
        }
        for (int i=1;i<=m;i++)
            for (int j=1;j<=i;j++)
                f[i][j]=min(f[i-1][j],G[f[i-1][j-1]][s2[i]-'a']+1);
        for (int i=1;i<=m;i++)
            for (int j=1;j<=i;j++)
                if (f[i][j]<=r+1) ans=max(ans,j);
        println(m+(r-l+1)-2*ans);
    }
}
signed main()
{
    int t;read(t);
    while (t--) doo();
}