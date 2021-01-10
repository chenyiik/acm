#include<bits/stdc++.h>
using namespace std;
constexpr auto of=true;
using iint=conditional<of,long long,int>::type;
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
    ios::sync_with_stdio(0);
    cin.tie(0);
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
bool samex[1<<22],samey[1<<22],paintx[1<<22],painty[1<<22];
int xlen[22],ylen[22];
void buildx(int l,int r,int rt,int k)
{
    samex[rt]=true;paintx[rt]=0;
    if(l==r) return;
    int m=(l+r)>>1;
    buildx(l,m,rt<<1,k-1);
    buildx(m+1,r,rt<<1|1,k-1);
}
iint allrect=0,okrect=0;
void buildy(int l,int r,int rt,int k)
{
    samey[rt]=true;painty[rt]=0;
    if(l==r) return;
    int m=(l+r)>>1;
    buildy(l,m,rt<<1,k-1);
    buildy(m+1,r,rt<<1|1,k-1);
}
void flipx(int x,int l,int r,int rt,int k)
{
    if(l==r)
    {
        paintx[rt]=!paintx[rt];
        return;
    }
    int m=(l+r)>>1;
    if(x<=m) flipx(x,l,m,rt<<1,k-1);
    else flipx(x,m+1,r,rt<<1|1,k-1);
    if(samex[rt]) okrect-=ylen[k],--xlen[k];
    if(paintx[rt<<1]==paintx[rt<<1|1] && samex[rt<<1] && samex[rt<<1|1])
    {
        paintx[rt]=paintx[rt<<1];
        samex[rt]=true;
    }else samex[rt]=false;
    if(samex[rt]) okrect+=ylen[k],++xlen[k];
}
void flipy(int x,int l,int r,int rt,int k)
{
    if(l==r)
    {
        painty[rt]=!painty[rt];
        return;
    }
    int m=(l+r)>>1;
    if(x<=m) flipy(x,l,m,rt<<1,k-1);
    else flipy(x,m+1,r,rt<<1|1,k-1);
    if(samey[rt]) okrect-=xlen[k],--ylen[k];
    if(painty[rt<<1]==painty[rt<<1|1] && samey[rt<<1] && samey[rt<<1|1])
    {
        painty[rt]=painty[rt<<1];
        samey[rt]=true;
    }
    else samey[rt]=false;
    if(samey[rt]) okrect+=xlen[k],++ylen[k];
}
signed main()
{
    int n,q;
    readint(n,q);
    xlen[n]=1;ylen[n]=1;
    for (int p=n-1;p>=0;p--) xlen[p]=xlen[p+1]<<1,ylen[p]=ylen[p+1]<<1;
    for (int p=n;p>=0;p--) allrect+=xlen[p]*xlen[p];
    okrect=allrect;
    buildx(1,1<<n,1,n);
    buildy(1,1<<n,1,n);
    while(q--)
    {
        int t,x;
        readint(t,x);
        if(t) flipx(x,1,1<<n,1,n);
        else flipy(x,1,1<<n,1,n);
        print(4*(allrect-okrect)+1,'\n');
    }
    return 0;
}