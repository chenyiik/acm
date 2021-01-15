#include<bits/stdc++.h>
using namespace std;
constexpr auto of=true;
using iint=conditional_t<of,long long,signed>;
using idouble=conditional_t<of,long double,double>;
constexpr bool dbg=false;
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
    if (precision>=0)
    {
        st=cout.flags();
        cout.setf(ios::fixed);
        cout.precision(precision);
    }
    if(firstrun) ifastios();
    cout<<forward<T>(arg);
    print(args...);
    if (precision>=0) cout.flags(st);
}
template<iint precision=-1,typename T,typename... U>
void println(T&&arg,U&&... args)
{
    print<precision>(forward<T>(arg),forward<U>(args)...,'\n');
}
bool read()
{return cin.good();}
template<typename T,typename... U>
bool read(T&arg,U&... args)
{
    if(firstrun) ifastios();
    if (!cin.good()) return cin.good();
    cin>>arg;
    return cin.good() && read(args...);
}
using ll=long long;
struct edget
{
    ll to,next,lim,cost;
};
edget E[1050*1000];
ll head[1050],cnt;
void addedge(ll u,ll v,ll lim,ll cost)
{
    E[cnt].to=v;E[cnt].lim=lim;E[cnt].cost=cost;E[cnt].next=head[u];head[u]=cnt++;
    E[cnt].to=u;E[cnt].lim=0;E[cnt].cost=-cost;E[cnt].next=head[v];head[v]=cnt++;
}
ll n,m,s,t;
ll dist[1050],flow[1050],pre[1050],vis[1050];
ll spfa()
{
    static queue<ll> q;while (!q.empty()) q.pop();q.push(s);
    for (ll i=0;i<=t+10;i++) dist[i]=-0x3f3f3f3f,flow[i]=0x3f3f3f3f,vis[i]=0;
    vis[s]=1;dist[s]=0;
    while (q.size())
    {
        ll u=q.front();q.pop();
        for (ll i=head[u];~i;i=E[i].next)
        {
            ll v=E[i].to,w=E[i].cost,lim=E[i].lim;
            if (lim>0 && (dist[u]+w>dist[v]))
            {
                dist[v]=dist[u]+w;
                flow[v]=min(flow[u],lim);
                pre[v]=i;
                if (vis[v]==0)
                {
                    vis[v]=1;q.push(v);
                }
            }
        }
        vis[u]=0;
    }
    return flow[t]==0x3f3f3f3f?-1:1;
}
ll mcmf()
{
    ll maxflow=0,mincost=0;
    while (spfa()>0)
    {
        mincost+=dist[t]*flow[t];
        maxflow+=flow[t];
        ll v=t;
        while (1)
        {
            ll u=E[pre[v]^1].to;
            E[pre[v]].lim-=flow[t];
            E[pre[v]^1].lim+=flow[t];
            v=u;if (u==s) break;
        }
    }
    return mincost;
}
ll a[1050],b[1050],c[1050];
int main()
{
    ll _t;read(_t);
    while(_t--)
    {
        ll modl;
        read(n,m,modl);
        for (ll i=1;i<=n;i++) read(a[i]);
        for (ll i=1;i<=n;i++) read(b[i]);
        for (ll i=1;i<=n;i++) read(c[i]);
        s=0,t=n<<2;t+=4;
        ll s1=n<<2;s1+=1;
        memset(head,-1,sizeof(head));cnt=0;
        addedge(s,s1,m,0);
        for (ll i=1;i<=n;i++) addedge(s1,i,1,0);
        for (ll i=1;i<=n;i++)
            for (ll j=1;j<=n;j++) addedge(i,n+j,1,(a[j]+b[i])*(a[j]^b[i])%modl);
        for (ll i=1;i<=n;i++) addedge(n+i,i+(n<<1),1,0);
        for (ll i=1;i<=n;i++)
            for (ll j=1;j<=n;j++) addedge(i+(n<<1),j+n*3,1,(c[j]+a[i])*(c[j]^a[i])%modl);
        for (ll i=1;i<=n;i++) addedge(i+3*n,t,1,0);
        println(mcmf());
    }
}