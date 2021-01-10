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
}
template<typename T>
Range<T> range(T end)
{
    return Range<T>(0,end,1);
}
vector<int> G[200050];
int size[200050],dep[200050],f[200050],n;
void init(int x)
{
    size[x]=1;
    dep[x]=dep[f[x]]+1;
    for (auto u:G[x])
    if (u!=f[x])
    {
        f[u]=x;
        init(u);
        size[x]+=size[u];
    }
}
int lc[200050];
deque<pair<int,int>> tur;
signed main()
{
    read(n);
    for (int i=1;i<n;i++)
    {
        int u,v;
        read(u,v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    init(1);
    int alll=0;
    deque<int> yz;
    for (int i=1;i<=n;i++)
        if (size[i]==1)
            yz.push_back(i),lc[f[i]]++,alll++;
    print((1+alll)/2,'\n');
    //random_shuffle(yz.begin(),yz.end());
    for (int i=0;i<(alll+1)/2;i++)
        print(yz[i],' ',yz[i+alll/2],'\n');
    /*for (int i=1;i<=n;i++)
        if (lc[i]) tur.push_back(make_pair(lc[i],i));
    sort(tur.begin(),tur.end());
    for (int i=1;i<=n;i++)
    {
        for (auto x=G[i].begin();x!=G[i].end();++x)
        {
            if (size[*x]!=1)
            {
                G[i].erase(x);
                break;
            }
        }
    }
    while (tur.size())
    {
        if (tur.size()==1) break;
        auto u1=tur.front(),u2=tur.back();
        tur.pop_front();tur.pop_back();
        while (lc[u1.second] && lc[u2.second])
        {
            for (auto x:G[u1.second])
            {
                print(G[u1.second].front(),' ',G[u2.second].front(),'\n');
                G[u1.second].erase(G[u1.second].begin());
                G[u2.second].erase(G[u2.second].begin());
                lc[u1.second]--;
                lc[u2.second]--;
            }
        }
        if (lc[u1.second]) tur.push_front(u1);
        if (lc[u2.second]) tur.push_front(u2);
        if (tur.size()==1) break;
    }
    if (tur.size()==1)
    {
        auto u1=tur.front();
        while(lc[u1.second]>=2)
        {
            print(G[u1.second][0],' ',G[u1.second][1],'\n');
            G[u1.second].erase(G[u1.second].begin());
            G[u1.second].erase(G[u1.second].begin());
            lc[u1.second]-=2;
        }
        if (lc[u1.second])
        {
            print(G[u1.second].front(),' ',1,'\n');
            --lc[u1.second];
        }
        tur.clear();
    }*/
}