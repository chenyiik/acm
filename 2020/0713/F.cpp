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
int a[5050][5050];
vector<int> b[5050];
signed main()
{
    int n,m,k;
    read(n,m,k);
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
        a[i][j]=i*(j/__gcd(i,j));
    deque<int> q;
    for (int j=1;j<=m;j++)
    {
        q.clear();
        for (int i=1;i<=n;i++)
        {
            while (q.size() && a[i][j]>a[q.back()][j]) q.pop_back();
            q.push_back(i);
            while (q.back()-q.front()+1>k) q.pop_front();
            if (i>k-1) b[j].push_back(a[q.front()][j]);
        }
    }
    iint ans=0;
    for (int i=0;i<b[1].size();i++)
    {
        q.clear();
        for (int j=1;j<=m;j++)
        {
            while (q.size() && b[j][i]>b[q.back()][i]) q.pop_back();
            q.push_back(j);
            while (q.back()-q.front()+1>k) q.pop_front();
            if (j>k-1) ans+=b[q.front()][i];
        }
    }
    print(ans,'\n');
}