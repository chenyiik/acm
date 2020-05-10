#include<bits/stdc++.h>
using namespace std;
constexpr auto of=true;
using iint=conditional<of,long long,int>::type;
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
    ios::sync_with_stdio(0);
    cin.tie(0);
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
void read()
{}
template<typename T,typename... U>
void read(T&arg,U&... args)
{
    if(firstrun) ifastios();
    cin>>arg;
    read(args...);
}
template<typename T>
void ipb(T&container)
{}
template<typename T,typename E,typename... U>
void ipb(vector<T>&container,E&&val,U&&... args)
{
    static_assert(is_convertible<E,T>::value,"Wrong value type");
    container.push_back(forward<E>(val));
    ipb(container,args...);
}
template<typename T,typename E,typename... U>
void ipb(list<T>&container,E&&val,U&&... args)
{
    static_assert(is_convertible<E,T>::value,"Wrong value type");
    container.push_back(forward<E>(val));
    ipb(container,args...);
}
template<typename T,typename E,typename... U>
void ipb(deque<T>&container,E&&val,U&&... args)
{
    static_assert(is_convertible<E,T>::value,"Wrong value type");
    container.push_back(forward<E>(val));
    ipb(container,args...);
}
template<typename T,typename E,typename... U>
void ipb(queue<T>&container,E&&val,U&&... args)
{
    static_assert(is_convertible<E,T>::value,"Wrong value type");
    container.push(forward<E>(val));
    ipb(container,args...);
}
template<typename T,typename E,typename... U>
void ipb(set<T>&container,E&&val,U&&... args)
{
    static_assert(is_convertible<E,T>::value,"Wrong value type");
    container.insert(forward<E>(val));
    ipb(container,args...);
}
struct opn
{
    int x,l,r;
};
struct outp
{
    char op;
    int l,r;
};
signed main()
{
    int n;
    static int a[100050],b[100050];
    read(n);
    for(int i=1;i<=n;i++) read(a[i]);
    for(int i=1;i<=n;i++) read(b[i]);
    static int pos[100050];
    int nx=1;
    for(int i=1;i<=n;i++)
    {
        while(nx<=n && a[nx]!=b[i]) ++nx;
        if(nx>n)
        {
            print("-1\n");
            return 0;
        }
        pos[i]=nx;
    }
    nx=1;
    static vector<opn> act;
    static vector<outp> ioutp;
    for(int i=1;i<=n;i++)
    {
        if(pos[i]==pos[i+1]) continue;
        act.push_back({pos[i],nx,i});
        nx=i+1;
    }
    for(int i=act.size()-1;i>=0;i--)
    {
        auto u=act[i];
        if(u.x>=u.l) continue;
        if(a[u.x]>=a[u.x+1])
        {
            ioutp.push_back({'m',u.x+1,u.r});
            ioutp.push_back({'M',u.x,u.r});
        }else
        {
            ioutp.push_back({'M',u.x+1,u.r});
            ioutp.push_back({'m',u.x,u.r});
        }
    }
    for(int i=0;i<act.size();i++)
    {
        auto u=act[i];
        if(u.x<=u.r) continue;
        if(a[u.x]<=a[u.x-1])
        {
            ioutp.push_back({'M',u.l,u.x-1});
            ioutp.push_back({'m',u.l,u.x});
        }else
        {
            ioutp.push_back({'m',u.l,u.x-1});
            ioutp.push_back({'M',u.l,u.x});
        }
    }
    for(int i=0;i<act.size();i++)
    {
        auto u=act[i];
        if(u.l>u.x || u.r<u.x) continue;
        if(u.x>u.l)
        {
            if(a[u.x]>=a[u.x-1])
            {
                ioutp.push_back({'m',u.l,u.x-1});
                ioutp.push_back({'M',u.l,u.x});
            }else
            {
                ioutp.push_back({'M',u.l,u.x-1});
                ioutp.push_back({'m',u.l,u.x});
            }
        }
        if(u.x<u.r)
        {
            if(a[u.x]>=a[u.x+1])
            {
                ioutp.push_back({'m',u.x+1,u.r});
                ioutp.push_back({'M',u.x,u.r});
            }else
            {
                ioutp.push_back({'M',u.x+1,u.r});
                ioutp.push_back({'m',u.x,u.r});
            }
        }
    }
    print(ioutp.size(),'\n');
    for (auto x:ioutp)
        print(x.op,' ',x.l,' ',x.r,'\n');
}