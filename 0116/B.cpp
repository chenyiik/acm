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
int sg[105][105];
int mex(int x,int y)
{
    static bool vis[1050];
    memset(vis,0,sizeof(vis));
    for (int i=0;i<x;i++) vis[sg[i][y]]=1;
    for (int j=0;j<y;j++) vis[sg[x][j]]=1;
    for (int i=1;i<=min(x,y);i++) vis[sg[x-i][y-i]]=1;
    for (int i=0;i<1000;i++) if (!vis[i]) return i;
}
int main()
{
    memset(sg,0,sizeof(sg));
    for (int i=0;i<=100;i++) sg[i][i]=sg[i][0]=sg[0][i]=999;
    for (int i=1;i<=100;i++)
        for (int j=1;j<=100;j++)
            if (i^j) sg[i][j]=mex(i,j);
    int n,ans=0;read(n);
    for (int i=1;i<=n;i++)
    {
        int a,b;read(a,b);
        if (sg[a][b]==999) {println('Y');return 0;}
        ans^=sg[a][b];
    }
    println("NY"[ans!=0]);
}