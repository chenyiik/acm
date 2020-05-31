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
    if (!dbg) ios::sync_with_stdio(0),cin.tie(0);
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
struct odtn
{
    iint L,R,val;
    bool operator<(const odtn& b) const
    {
        if (L^b.L) return L<b.L;
        return R<b.R;
    }
};
set<odtn> odt;
using IT=set<odtn>::iterator;
IT split(iint pos)
{
    IT it=odt.lower_bound({pos,-2,-2});
    if (it!=odt.end() && (*it).L==pos) return it;
    --it;
    auto vit=*it;
    iint l,r,v;
    tie(l,r,v)=tie(vit.L,vit.R,vit.val);
    odt.erase(it);odt.insert({l,pos-1,v});
    return odt.insert({pos,r,v}).first;
}
iint num[100050];
void assign(iint l,iint r,iint x)
{
    IT it2=split(r+1),it1=split(l);
    for (auto it=it1;it!=it2;++it)
        num[(*it).val]-=((*it).R-(*it).L+1);
    odt.erase(it1,it2);
    odt.insert({l,r,x});
    num[x]+=r-l+1;
}
signed main()
{
    iint l,c,n;read(l,c,n);
    odt.insert({0,l-1,1});num[1]=l;
    for (iint i=1;i<=n;i++)
    {
        iint p,x,a,b;read(p,x,a,b);
        iint s=num[p]%l;a%=l;b%=l;
        iint ll=(a+s*s%l)%l,rr=(a+(s+b)*(s+b)%l)%l;
        assign(min(ll,rr),max(ll,rr),x);
    }
    iint ans=0;
    for (iint i=1;i<=c;i++) ans=max(ans,num[i]);
    print(ans,'\n');
}