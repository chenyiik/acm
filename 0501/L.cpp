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
iint stx,sty;
typedef pair<iint,iint> pres;
map<pres,iint> mp;
iint res=0;
iint classify(iint x,iint y)
{
    iint dx=x-stx,dy=y-sty;
    if (dx==0) dy/=abs(dy);
    if (dy==0) dx/=abs(dx);
    if (dx!=0 && dy!=0)
    {
        iint t=__gcd(abs(dx),abs(dy));
        dx/=t,dy/=t;
    }
    auto rdl=make_pair(dx,dy);
    if (mp[rdl]>0) return mp[rdl];
    mp[rdl]=++res;
    return mp[rdl];
}
vector<pair<iint,iint>> cl[1000050];
vector<iint> redl[1000050];
iint lis(vector<iint>& vec)
{
    static iint f[1000050];
    for (iint i=0;i<vec.size();i++) f[i]=0x3f3f3f3f;
    f[0]=vec[0];iint l=1;
    for (iint i=1;i<vec.size();i++)
    {
        if (vec[i]>f[l-1]) f[l++]=vec[i];
        else f[lower_bound(f,f+vec.size(),vec[i])-f]=vec[i];
    }
    return l;
}
int main()
{
    read(stx,sty);
    iint n;read(n);
    for (iint i=1;i<=n;i++)
    {
        iint x,y,h;read(x,y,h);
        iint id=classify(x,y);
        x-=stx,y-=sty;
        cl[id].push_back({sqrt(x*x+y*y),h});
    }
    for (iint i=1;i<=res;i++) sort(cl[i].begin(),cl[i].end());
    for (iint i=1;i<=res;i++)
        for (auto x:cl[i]) redl[i].push_back(x.second);
    iint ans=0;
    for (iint i=1;i<=res;i++)
        ans+=lis(redl[i]);
    print(ans);
}