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
struct point
{
    double x,y;
    point(double _x=0,double _y=0):x(_x),y(_y){}
};
struct vec2
{
    double x,y;
    vec2(double _x=0,double _y=0):x(_x),y(_y){}
    vec2(point _s=point(0,0),point _t=point(0,0)):x(_t.x-_s.x),y(_t.y-_s.y){}
    double norm() {return sqrt(x*x+y*y);}
};
double dist(point a,point b)
{
    return vec2(a,b).norm();
}
const double eps=1e-5;
bool eq(double a,double b)
{
    return fabs(a-b)<eps;
}
double cross(vec2 a,vec2 b)
{
    return a.x*b.y-a.y*b.x;
}
void run()
{
    static point p[25];
    for (int i=1;i<=20;i++) read(p[i].x,p[i].y);p[21]=p[1];p[22]=p[2];p[0]=p[20];
    int st=0;
    for (int i=1;i<=20;i++)
    {
        if (eq(dist(p[i],p[i+1]),9))
        {
            st=i;break;
        }
    }
    vec2 bas(p[st],p[st+1]);
    vec2 r(p[st-1],p[st+2]);
    bool isright=cross(bas,r)>0;
    print(isright?"right":"left",'\n');
}
signed main()
{
    int t;read(t);
    while (t--)
    {
        run();
    }
}