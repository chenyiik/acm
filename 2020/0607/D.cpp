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
struct edget
{
    iint v,w;
};
vector<edget> G[1050];
iint dist[1050][1050];
void spfa(iint s,iint d[])
{
    for (int i=0;i<=1050;i++) d[i]=0x3f3f3f3f3f3f3f3fLL;
    static deque<iint> q;
    q.clear();q.push_back(s);d[s]=0;
    static bool inq[1050];
    memset(inq,0,sizeof(inq));inq[s]=1;
    while (!q.empty())
    {
        int u=q.front();q.pop_front();inq[u]=0;
        for (auto x:G[u])
        if (d[u]+x.w<d[x.v])
        {
            d[x.v]=d[u]+x.w;
            if (!inq[x.v])
            {
                if (!q.size()||d[x.v]>d[q.front()]) q.push_back(x.v);else q.push_front(x.v);
                inq[x.v]=1;
            }
        }
    }
}
iint s[1050],u[1050],t[1050],n,m,k;
bool chk(iint mt)
{
    static iint f[1050];memset(f,0x3f,sizeof(f));
    f[0]=0;
    for (iint i=0;i<k;i++)
    {
        iint ct=f[i],w=0,mxt=0x3f3f3f3f3f3f3f3fLL;
        for (iint j=i+1;j<=k;j++)
        {
            if (j==i+1) w+=dist[1][u[i+1]];
            else w+=dist[u[j-1]][u[j]];
            ct=max(ct,t[j]);
            mxt=min(mxt,mt-w+s[j]);
            iint wt=w+ct-s[j];
            if (wt<=mt && ct<=mxt) f[j]=min(f[j],ct+w+dist[u[j]][1]);else break;
        }
    }
    return f[k]<0x3f3f3f3f3f3f3f3fLL;
}
signed main()
{
    read(n,m);
    for (iint i=1;i<=m;i++)
    {
        iint u,v,w;read(u,v,w);
        G[u].push_back({v,w});
        G[v].push_back({u,w});
    }
    for (iint i=1;i<=n;i++) spfa(i,dist[i]);
    read(k);
    for (int i=1;i<=k;i++) read(s[i],u[i],t[i]);
    iint l=0,r=0x3f3f3f3f3f3f3f3fLL;
    while (l<r)
    {
        iint mid=(l+r)>>1LL;
        if (chk(mid)) r=mid;else l=mid+1;
    }
    print(l,'\n');
}