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
set<int> ss[21][21];
string s="f11451419191145141919";
void dfs(int l,int r)
{
    if (ss[l][r].size()) return;
    if (r-l<=3)
    {
        int num=stoi(s.substr(l,r-l+1));
        if (num<=5000) ss[l][r].insert(num);
    }
    for (int i=l;i<r;i++)
    {
        dfs(l,i);dfs(i+1,r);
        for (auto x:ss[l][i])
            for (auto y:ss[i+1][r])
            {
                if (x+y<=5000)
                    ss[l][r].insert(x+y);
                if (x*y<=5000)
                    ss[l][r].insert(x*y);
            }
    }
}
int ans[5050];
signed main()
{
    memset(ans,-1,sizeof(ans));
    int tx=0;
    for (int t=1;t<=12;t++)
    {
        dfs(1,t);
        for (auto x:ss[1][t])
            if (ans[x]==-1) ans[x]=t,tx++;
    }
    int cas;read(cas);
    while (cas--)
    {
        int n;read(n);
        println(ans[n]);
    }
}