#include<bits/stdc++.h>
using namespace std;
constexpr auto of=true;
using iint=conditional<of,long long,int>::type;
using idouble=conditional<of,long double,double>::type;
constexpr bool dbg=false;
template<int buffersz>
inline char igetchar()
{
    static char buf[buffersz],*p1=buf,*p2=buf;
    return p1==p2 && (p2=(p1=buf)+fread(buf,1,buffersz,stdin),p1==p2)?EOF:*p1++;
}
template<int buffersz,class T>
void read_one(T&x)
{
    static_assert(is_convertible<char,T>::value,"Not supporting type");
    x=0;
    int f=0;
    char ch=igetchar<buffersz>();
    while(!isdigit(ch)) f|=(ch=='-'),ch=igetchar<buffersz>();
    while(isdigit(ch)) x=(x<<1)+(x<<3)+(ch^48),ch=igetchar<buffersz>();
    x=f?-x:x;
}
void readint(){}
template<int buffersz=dbg?1:(int)1e4,typename T,typename... U>
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
template<int precision=-1,typename T,typename... U>
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
struct point
{
    double x,y;
    point(double _x=0,double _y=0):x(_x),y(_y){}
};
double cross(point a,point b)
{
    return a.x*b.y-a.y*b.x;
}
double len(point a,point b)
{
    return sqrt((b.x-a.x)*(b.x-a.x)+(b.y-a.y)*(b.y-a.y));
}
double dist_p2l(point p,point l1,point l2)
{
    return cross(point(p.x-l1.x,p.y-l1.y),point(p.x-l2.x,p.y-l2.y))/len(l1,l2);
}
point p[1050];
int n;
int main()
{
    read(n);
    for (int i=1;i<=n;i++) read(p[i].x,p[i].y);
    p[0]=p[n];p[n+1]=p[1];
    double ans=0x3f3f3f3f;
    for (int i=1;i<=n;i++)
        for (int j=1;j<i;j++)
        {
            double mind,maxd;
            mind=0x3f3f3f3f;maxd=-mind;
            for (int k=1;k<=n;k++)
            {
                mind=min(mind,dist_p2l(p[k],p[i],p[j]));
                maxd=max(maxd,dist_p2l(p[k],p[i],p[j]));
            }
            ans=min(ans,maxd-mind);
        }
    print<8>(ans);
}