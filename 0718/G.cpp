#include<bits/stdc++.h>
using namespace std;
constexpr auto of=true;
using iint=conditional<of,long long,signed>::type;
using idouble=conditional<of,long double,double>::type;
constexpr bool dbg=!!true;
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
}
template<typename T>
Range<T> range(T end)
{
    return Range<T>(0,end,1);
}
int fa[800050];
int getfa(int x)
{
    if (fa[x]==x) return x;
    return fa[x]=getfa(fa[x]);
}
inline void merge(int x,int y)
{
    fa[y]=x;
}
void go()
{
    static vector<int> G[800050];
    static int head[800050<<1],nxt[800050<<1],tail[800050<<1];
    int n,m;readint(n,m);
    for (int i=0;i<n;i++)
    {
        fa[i]=i;
        head[i]=tail[i]=i;
        nxt[i]=-1;G[i].clear();
    }
    for (int i=0;i<m;i++)
    {
        int u,v;readint(u,v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    int q;readint(q);
    while (q--)
    {
        int x;readint(x);
        if (getfa(x)!=x) continue;
        int nh=-1,nt=-1;
        for (int i=head[x];~i;i=nxt[i])
        {
            for (auto j:G[i])
                if (getfa(j)!=x)
                {
                    int xfa=getfa(j);
                    if (~nh) nxt[nt]=head[xfa];else nh=head[xfa];
                    merge(x,xfa);nt=tail[xfa];
                }
        }
        head[x]=nh;tail[x]=nt;
    }
    for (int i=0;i<n;i++) print(getfa(i)," \n"[i==n-1]);
}
signed main()
{
    int t;readint(t);
    while (t--) go();
}