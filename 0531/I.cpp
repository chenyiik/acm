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
    if (!dbg) ios::sync_with_stdio(0),cin.tie(0);
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
int n,m;
struct edgep
{
    int u,v;
    bool operator<(const edgep& b) const
    {
        if (u^b.u) return u<b.u;
        return v<b.v;
    }
};
map<edgep,int> mp;
struct edget
{
    int u,v,w;
    bool operator<(const edget& b) const
    {
        return w<b.w;
    }
};
vector<edget> E;
int dep[100050],fa[100050],maxdep[100050],weight[100050];
int summst=0;
int getfa(int x)
{
    return fa[x]?getfa(fa[x]):x;
}
void merge(int u,int v,int w)
{
    int fu=getfa(u),fv=getfa(v);
    if (fu==fv) return;
    if (maxdep[fu]>maxdep[fv]) swap(fu,fv);
    fa[fu]=fv;weight[fu]=w;
    if (maxdep[fu]==maxdep[fv]) maxdep[fv]++;
    summst+=w;
}
int getdep(int x)
{
    if (!fa[x]) return dep[x]=0;
    return dep[x]?dep[x]:(dep[x]=getdep(fa[x])+1);
}
int getmaxw(int u,int v)
{
    int r=0;
    while(u^v)
    {
        if (dep[u]<dep[v]) swap(u,v);
        r=max(r,weight[u]);
        u=fa[u];
    }
    return r;
}
signed main()
{
    read(n,m);
    for (int i=1;i<=m;i++)
    {
        int u,v,w;read(u,v,w);
        mp[{u,v}]=mp[{v,u}]=w;
        ipb(E,edget({u,v,w}));
    }
    sort(E.begin(),E.end());
    for (int i=1;i<=n;i++) maxdep[i]=1;
    for (auto x:E)
        merge(x.u,x.v,x.w);
    for (int i=1;i<=n;i++) getdep(i);
    int q;read(q);
    while (q--)
    {
        int u,v;read(u,v);
        print(summst+mp[{u,v}]-getmaxw(u,v),'\n');
    }
}