#include<bits/stdc++.h>
using namespace std;
constexpr auto of=true;
using iint=conditional<of,long long,int>::type;
using idouble=conditional<of,long double,double>::type;
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
void readint(){}
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
void print(){}
template<iint precision=-1,typename T,typename... U>
void print(T&&arg,U&&... args)
{
    if(precision>=0)
    {
        st=cout.flags();
        cout.setf(ios::fixed);
        cout.precision(precision);
    }
    if(firstrun && !dbg) ifastios();
    cout<<forward<T>(arg);
    print(args...);
    if(precision>=0) cout.flags(st);
}
void read(){}
template<typename T,typename... U>
void read(T&arg,U&... args)
{
    if(firstrun && !dbg) ifastios();
    cin>>arg;
    read(args...);
}
template<typename T>
void ipb(T&container){}
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
int w[105],l[105];
int t[105];
struct edget
{
    int v,w,nxt;
};
edget e[2050*2050/2];
int cnt=0;
int head[2050];
int S,T;
void addedge(int u,int v,int w)
{
    e[cnt]={v,w,head[u]};head[u]=cnt++;
    e[cnt]={u,0,head[v]};head[v]=cnt++;
}
int shead[2050],dist[2050];
int bfs(int S,int T)
{
    memset(dist,-1,sizeof(dist));
    dist[S]=0;
    static queue<int> q;
    while (!q.empty()) q.pop();
    q.push(S);
    while (!q.empty())
    {
        int u=q.front();q.pop();
        for (int i=head[u];~i;i=e[i].nxt)
        {
            int v=e[i].v;
            if (dist[v]==-1 && e[i].w>0)
            {
                dist[v]=dist[u]+1;
                q.push(v);
            }
        }
    }
    return dist[T]>-1;
}
int dfs(int u,int t,int lim)
{
    if (u==t||!lim) return lim;
    int flow=0;
    for (auto &i=shead[u];~i;i=e[i].nxt)
    {
        int v=e[i].v,w=e[i].w;
        if (w>0 && dist[v]==dist[u]+1)
        {
            int f=dfs(v,t,min(lim,w));
            flow+=f;
            lim-=f;
            e[i].w-=f;
            e[i^1].w+=f;
            if (!lim) return flow;
        }
    }
    return flow;
}
int dinic(int S,int T)
{
    int ans=0;
    while (bfs(S,T))
    {
        for (int i=0;i<2050;i++) shead[i]=head[i];
        int tmp;
        while (tmp=dfs(S,T,0x3f3f3f3f))
            ans+=tmp;
    }
    return ans;
}
void trace(int u,int S)
{
    if (u==S) return;
    for (int i=head[u];~i;i=e[i].nxt)
    {
        int v=e[i].v,w=e[i].w;
        if (w && (i&1)) trace(v,S);
    }
    if (u>0 && u<=n)
        print(u,' ');
}
signed main()
{
    memset(head,-1,sizeof(head));
    read(n);for (int i=1;i<=n;i++) read(w[i],l[i]);
    read(m);for (int i=1;i<=m;i++) read(t[i]);
    S=0,T=2*n+m+1;
    for (int i=1;i<=n;i++)
    {
        if (!w[i]) addedge(S,i,1);
        addedge(i,n+i,1);
    }
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
        if (i^j)
        {
            if (l[i]>=w[j] && w[j])
                addedge(n+i,j,1);
        }
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            if (l[i]>=t[j]) addedge(n+i,2*n+j,1);
    for (int i=1;i<=m;i++) addedge(2*n+i,T,1);
    int ans=dinic(S,T);
    //print(ans,'\n');
    if (ans!=m) {print("impossible\n");return 0;}
    for (int i=1;i<=m;i++)
        trace(2*n+i,S),print('\n');
}