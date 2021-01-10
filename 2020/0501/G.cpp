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
struct point
{
    int x,y,z;
    point(int _x=0,int _y=0,int _z=0):x(_x),y(_y),z(_z){}
    point operator-(point b)
    {
        return point(x-b.x,y-b.y,z-b.z);
    }
    point operator+(point b)
    {
        return point(x+b.x,y+b.y,z+b.z);
    }
    int getabslen()
    {
        return abs(x)+abs(y)+abs(z);
    }
    bool operator==(point b)
    {
        return (*this-b).getabslen()==0;
    }
};
point s1,t1,s2,t2;
point getop(int opn)
{
    static vector<point> iv={point(1,0,0),point(-1,0,0),point(0,1,0),point(0,-1,0),point(0,0,1),point(0,0,-1),point(0,0,0)};
    return iv[opn];
}
signed main()
{
    read(s1.x,s1.y,s1.z,t1.x,t1.y,t1.z,s2.x,s2.y,s2.z,t2.x,t2.y,t2.z);
    int distance=(t1-s1).getabslen()+(t2-s2).getabslen();
    while (distance)
    {
        print('(',s1.x,' ',s1.y,' ',s1.z,") ");
        print('(',s2.x,' ',s2.y,' ',s2.z,")\n");
        distance=(t1-s1).getabslen()+(t2-s2).getabslen();
        int best=0x3f3f3f3f;
        int u1=0,u2=0;
        for (int tu1=0;tu1<=6;tu1++)
            for (int tu2=0;tu2<=6;tu2++)
            {
                point ds1,ds2;
                ds1=s1+getop(tu1);
                ds2=s2+getop(tu2);
                if (ds1==ds2||ds1==s2||ds2==s1) continue;
                int now=(t1-ds1).getabslen()+(t2-ds2).getabslen();
                if (now<best) best=now,u1=tu1,u2=tu2;
            }
        if (best>=distance)
        {
            while (1)
            {
                int tu1=rand()%7,tu2=rand()%7;
                point ds1,ds2;
                ds1=s1+getop(tu1);
                ds2=s2+getop(tu2);
                if (ds1==ds2||ds1==s2||ds2==s1) continue;
                u1=tu1,u2=tu2;
                break;
            }
        }
        s1=s1+getop(u1);
        s2=s2+getop(u2);
    }
}