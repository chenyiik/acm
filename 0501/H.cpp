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
int b,p,d[1050];
map<int,int> nxt;
int k;
int mindist[1050],pos[1050];
queue<int> q;
bool chk(int pid)
{
    int did=pos[pid];
    if (did>=p) return false;
    if (pid>1 && d[did+1]-d[pos[pid-1]]>b) return false;
    if (pid<k && pos[pid+1]<p && d[pos[pid+1]]-d[did+1]<max(mindist[pid],mindist[pid+1])) return false;
    return true;
}
signed main()
{
    read(b,p);
    for (int i=1;i<=p;i++) read(d[i]);
    read(k);
    for (int i=1;i<=k;i++)
    {
        read(mindist[i],pos[i]);
        q.push(i);
    }
    static vector<int> ans;
    while (q.size())
    {
        int u=q.front();q.pop();
        if (chk(u))
        {
            ans.push_back(u);
            pos[u]++;
            q.push(u);
            if (u>1) q.push(u-1);
            if (u<k) q.push(u+1);
        }
    }
    if (pos[1]!=p) {print("impossible");return 0;}
    for (auto x:ans) print(x,' ');
}