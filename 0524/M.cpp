#include<bits/stdc++.h>
using namespace std;
constexpr auto of=true;
using iint=conditional<of,long long,signed>::type;
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
    //if (!dbg) ios::sync_with_stdio(0),cin.tie(0);
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
struct node
{
    int x,y,val;
    node(int _x=0,int _y=0,int _val=0):x(_x),y(_y),val(_val){}
    bool operator<(const node& b) const
    {
        if (x^b.x) return x<b.x;
        return val>b.val;
    }
};
node a[100050<<2];
int b[100050];
int c[100050<<1];
inline int lowbit(int x){return x&(-x);}
void add(int x,int d)
{
    for (;x;x-=lowbit(x)) c[x]+=d;
}
int sum(int x)
{
    int ans=0;
    for (;x<100050*2;x+=lowbit(x)) ans+=c[x];
    return ans;
}
signed main()
{
    freopen("business.in","r",stdin);
    int t;readint(t);
    while (t--)
    {
        memset(c,0,sizeof(c));
        int n,q;readint(n,q);
        int m=0,sz=0;
        for (int i=1;i<=n;i++)
        {
            int x,q,r;readint(x,q,r);
            a[m++]=node(x,q-x,1);
            a[m++]=node(x+r+1,q-x,-1);
            b[sz++]=q-x;
        }
        sort(b,b+sz);
        sz=unique(b,b+sz)-b;
        sort(a,a+m);
        int p=0;
        while (q--)
        {
            int y,d;readint(y,d);
            while (p<m && a[p].x<=y)
            {
                add(lower_bound(b,b+sz,a[p].y)-b+1,a[p].val);
                ++p;
            }
            print(sum(lower_bound(b,b+sz,d-y)-b+1)," \n"[q==0]);
        }
    }
}