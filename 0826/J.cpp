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
vector<long long> G[105];
const long long modl=998244353;
int count_mst(long long n)
{
    static long long mat[105][105];
    memset(mat,0,sizeof(mat));
    for (long long i=1;i<=n;i++)
        for (auto j:G[i])
        if (j>i)
        {
            mat[i][j]--,mat[j][i]--;
            mat[i][i]++,mat[j][j]++;
        }
    auto gauss=[&]()
    {
        long long ans=1;
        for (long long i=2;i<=n;i++)
        {
            for(long long j=i+1;j<=n;j++)
            {
                while(mat[j][i])
                {
                    long long p=mat[i][i]/mat[j][i];
                    for(long long k=i;k<=n;k++)
                        mat[i][k]=(mat[i][k]-mat[j][k]*p%modl+modl)%modl;
                    swap(mat[i],mat[j]);
                    ans=-ans;
                }
            }
            ans*=mat[i][i];
            ans%=modl;
        }
        return (ans+modl)%modl;
    };
    return gauss();
}
signed main()
{
    long long n,m;
    read(n,m);
    for (long long i=1;i<=m;i++)
    {
        long long u,v,w;read(u,v,w);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    println(count_mst(n));
}