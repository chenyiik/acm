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
    int a[]={(read_one<buffersz>(args),0)...};
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
    ifastios();
    if(cin.good())
        int a[]={(cin>>args,0)...};
    return cin.good();
}
int n;
int a[505][505*2];
int main()
{
    read(n);
    for (int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++) read(a[i][j]);
        a[i][i+n]=1;
    }
    for (int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j++)
            if(a[j][i]){swap(a[j],a[i]);break;}
        if (!a[i][i]) return println(-1),0;
        for (int j=1;j<=n;j++)
            if (a[j][i] && j!=i)
                for (int k=1;k<=2*n;k++) a[j][k]^=a[i][k];
    }
    static int inv[505][505];
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++) inv[i][j]=a[i][j+n];
    static int light[505],ans[505];
    for (int i=1;i<=n;i++)
    {
        memset(light,0,sizeof(light));
        light[i]=1;
        memset(ans,0,sizeof(ans));
        for (int j=1;j<=n;j++)
            for (int i=1;i<=n;i++) ans[j]+=light[i]*inv[i][j];
        for (int j=1;j<=n;j++)
            if (ans[j])
            {
                print(j);
                if (j!=n) print(' ');
            }
        print('\n');
    }
}