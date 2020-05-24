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
signed main()
{
    freopen("lcm.in","r",stdin);
    static vector<iint> fact[100050];
    for (iint i=1;i<=100000;i++)
        for (iint j=i;j<=100000;j+=i) fact[j].push_back(i);
    iint t;read(t);
    while (t--)
    {
        iint ans=0;
        static iint sum[100050],rm[100050];
        iint n;read(n);
        static iint v[100050];
        memset(sum,0,sizeof(sum));
        memset(rm,0,sizeof(rm));
        for (iint i=1;i<=n;i++)
        {
            read(v[i]);
            for (auto dx:fact[v[i]]) sum[dx]+=v[i];
        }
        for (iint i=1;i<=n;i++)
        {
            for (iint j=fact[v[i]].size()-1;j>=0;j--)
            {
                iint dx=fact[v[i]][j];
                ans+=(sum[dx]-rm[dx])*v[i]/dx;
                ans%=iint(1e9+7);
                for (auto x:fact[dx]) rm[x]+=sum[dx]-rm[dx];
                rm[dx]=0;
            }
        }
        print(ans,'\n');
    }
}