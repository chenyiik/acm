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
const int maxsz=100050;
int t[(maxsz+50)<<2],lazy[(maxsz+50)<<2];
void init(int x=1,int l=0,int r=maxsz)
{
    lazy[x]=0;
    if (l==r) {t[x]=1;return;}
    int mid=(l+r)>>1;
    init(x<<1,l,mid);init(x<<1|1,mid+1,r);
    t[x]=t[x<<1]+t[x<<1|1];
}
void down(int x=1,int l=0,int r=maxsz)
{
    t[x]=-t[x];
    if (l!=r)
    {
        lazy[x<<1]^=1;
        lazy[x<<1|1]^=1;
    }
    lazy[x]=0;
}
void update(int l,int r,int x=1,int ll=0,int rr=maxsz)
{
    if (lazy[x]) down(x,ll,rr);
    if (l>r || ll>r || rr<l) return;
    if (l<=ll && rr<=r)
    {
        lazy[x]^=1;down(x,ll,rr);return;
    }
    int mid=(ll+rr)>>1;
    update(l,r,x<<1,ll,mid);
    update(l,r,x<<1|1,mid+1,rr);
    t[x]=t[x<<1]+t[x<<1|1];
}
int query(int l,int r,int x=1,int ll=0,int rr=maxsz)
{
    if (l>r || ll>r || rr<l) return 0;
    if (lazy[x]) down(x,ll,rr);
    if (l<=ll && rr<=r) return t[x];
    int mid=(ll+rr)>>1;
    return query(l,r,x<<1,ll,mid)+query(l,r,x<<1|1,mid+1,rr);
}
signed main()
{
    freopen("reflection.in","r",stdin);fflush(stdin);
    int T;readint(T);
    while (T--)
    {
        int q;readint(q);
        init();
        while (q--)
        {
            int x;readint(x);
            printf("%d\n",query(0,x-1));
            update(x,maxsz);
        }
    }
}