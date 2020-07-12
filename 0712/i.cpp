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
template<class T>
struct Range
{
    T st,en,stp,sz;
    struct iter
    {
        T mCurrentValue;
        Range&mRange;
        int mCurrentStep;
        iter(int start,Range&range):mCurrentStep(start),mRange(range)
        {mCurrentValue=mRange.st+mCurrentStep*mRange.stp;}
        T operator*()
        {return mCurrentValue;}
        bool operator!=(const iter&b)
        {return mCurrentStep!=b.mCurrentStep;}
        const iter*operator++()
        {
            mCurrentValue+=mRange.stp,mCurrentStep++;
            return this;
        }
    };
    Range(T begin,T end,T step=1):st(begin),en(end),stp(step)
    {sz=(en-st)/stp+(st+sz*stp!=en);};
    iter begin()
    {return iter(0,*this);}
    iter end()
    {return iter(sz,*this);}
};
template<typename T>
Range<T> range(T begin,T end,T step=1)
{
    static_assert(is_integral<T>::value,"Not supporting type");
    return Range<T>(begin,end,step);
};
template<typename T>
Range<T> range(T end)
{
    return Range<T>(0,end,1);
};
const int N=255,M=2550;
int s,t;
int n,m,k,hd[N],nxt[M*3],to[M*3],cost[M*3],las[M*3],tot;
int cur[N],dis[N],q[M],D=0,ans=0,fl=0;
bool vis[N],inq[N];
void add(int u,int v,int w,int c)
{
    nxt[++tot]=hd[u],to[tot]=v,las[tot]=w,cost[tot]=c,hd[u]=tot;
    nxt[++tot]=hd[v],to[tot]=u,las[tot]=0,cost[tot]=-c,hd[v]=tot;
}
bool spfa()
{
    int nw,hed=N,tail=N+1;
    memset(dis,127,sizeof dis);
    memset(inq,0,sizeof inq);
    dis[s]=0,q[++hed]=s,inq[s]=1;
    while(hed>=tail)
    {
        nw=q[tail++];
        for(int i=hd[nw];i!=-1;i=nxt[i])
        {
            if(las[i] && dis[to[i]]>dis[nw]+cost[i])
            {
                dis[to[i]]=dis[nw]+cost[i];
                if(!inq[to[i]])
                {
                    if(dis[to[i]]<dis[q[tail]])q[--tail]=to[i];
                    else q[++hed]=to[i];
                }
                inq[to[i]]=1;
            }
        }
        inq[nw]=0;
    }
    for(int i=0;i<=t;i++)
        for(int j=hd[i];j!=-1;j=nxt[j])
            cost[j]-=dis[to[j]]-dis[i];
    D+=dis[t];
    return dis[t]<=2e9;
}
int dfs(int pos,int flow)
{
    if(pos==t) {fl+=flow;return ans+=flow*D,flow;}
    vis[pos]=1;
    int l=flow,tp;
    for(int&i=cur[pos];i!=-1;i=nxt[i])
    {
        if(las[i] && !cost[i] && !vis[to[i]])
        {
            tp=dfs(to[i],min(l,las[i]));
            las[i]-=tp,las[i^1]+=tp;
            l-=tp;
            if(!l)return flow;
        }
    }
    return flow-l;
}
void mcmf()
{
    fl=0;
    while(spfa())
    {
        do
        {
            memset(vis,0,sizeof vis);
            for(int i=s;i<=t;i++)cur[i]=hd[i];
        }while(dfs(s,2e9));
    }
    //if (fl==v) printf("%d/%d\n",ans/__gcd(ans,v),v/__gcd(ans,v));else puts("NaN");
}
signed main()
{
    while (cin>>n>>m)
    {
        s=0,t=n<<1|1;
        ans=0,D=0;
        memset(hd,-1,sizeof hd);
        memset(nxt,-1,sizeof nxt);
        memset(to,0,sizeof to);
        memset(las,0,sizeof las);
        memset(cur,0,sizeof cur);
        memset(dis,0,sizeof dis);
        memset(q,0,sizeof q);
        memset(vis,0,sizeof vis);
        memset(inq,0,sizeof inq);
        tot=-1;
        auto stot=0;
        static int d[255];
        for (int i=1;i<=n;i++)
        {
            cin>>d[i];
            add(s,i,d[i],0);
            add(i+n,t,d[i],1);
            stot+=d[i];
        }
        for (int i=1;i<=m;i++)
        {
            int x,y;cin>>x>>y;
            add(x,y+n,1,1);
            add(y,x+n,1,1);
        }
        mcmf();
        puts(fl==stot?"Yes":"No");
    }
}