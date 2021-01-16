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
    ll a[]={(read_one<buffersz>(args),0)...};
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
    ll a[]={(cout<<args,0)...};
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
        ll a[]={(cin>>args,0)...};
    return cin.good();
}
struct edget
{
    ll to,lim,next;
};
edget E[100050<<1];
ll head[100050],cnt;
void addedge(ll u,ll v,ll lim)
{
    E[cnt]={.to=v,.lim=lim,.next=head[u]};head[u]=cnt++;
    E[cnt]={.to=u,.lim=0,.next=head[v]};head[v]=cnt++;
}
ll height[100050],flow[100050],maxflow,s,t;
priority_queue<pair<int,int>> pq;
void push(int u)
{
    for (int i=head[u];~i;i=E[i].next)
    {
        auto fl=min(E[i].lim,flow[u]);
        if (fl>0 && (u==s||height[u]-height[E[i].to]==1))
        {
            E[i].lim-=fl;E[i^1].lim+=fl;
            flow[u]-=fl;flow[E[i].to]+=fl;
            if (E[i].to==t) maxflow+=fl;
            if (E[i].to^s && E[i].to^t) pq.push({height[E[i].to],E[i].to});
        }
    }
}
void relabel(int u)
{
    if (u^s && u^t && flow[u]>0) height[u]++,pq.push({height[u],u});
}
void preflow()
{
    maxflow=0;memset(height,0,sizeof(height));
    height[s]=25;
    flow[s]=0x3f3f3f3f;flow[t]=-0x3f3f3f3f;
    while (pq.size()) pq.pop();pq.push({0,s});
    while (pq.size())
    {
        auto u=pq.top().second;pq.pop();
        push(u);relabel(u);
    }
}
ll D[1050],sum=0,EE[1050];
struct edger
{
    ll u,v,w;
};
edger ee[100050<<1];
ll p,rr,c;
bool check(ll lim)
{
    memset(head,-1,sizeof(head));cnt=0;
    s=0,t=p+rr+2;
    for (ll i=1;i<=rr;i++) addedge(s,i,EE[i]);
    for (ll i=1;i<=p;i++) addedge(i+rr,t,D[i]);
    for (ll i=1;i<=c;i++) if (ee[i].w<=lim) addedge(ee[i].v,ee[i].u+rr,0x3f3f3f3f);
    preflow();
    ll ans=maxflow;
    return ans==sum;
}
int main()
{
    readint(p,rr,c);
    for (ll i=1;i<=p;i++) readint(D[i]),sum+=D[i];
    for (ll i=1;i<=rr;i++) readint(EE[i]);
    for (ll i=1;i<=c;i++) readint(ee[i].u,ee[i].v,ee[i].w);
    bool hassol=0;
    ll l=0,r=1e7+50,ans=0;
    while (l<=r)
    {
        ll mid=(l+r)>>1;
        if (check(mid)) {r=mid-1;ans=mid;hassol=1;} else l=mid+1;
    }
    println(vector<ll>({-1,ans})[hassol]);
}