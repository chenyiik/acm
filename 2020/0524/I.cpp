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
using point=pair<iint,iint>;
using relpoint=pair<idouble,point>;
const idouble eps=1e-11;
const idouble pi=acos(-1.0);
signed main()
{
    freopen("points.in","r",stdin);
    static point p[1050<<1];
    iint t;read(t);
    while (t--)
    {
        iint n,l,r;read(n,l,r);
        l<<=1LL,r<<=1LL;
        for (iint i=1;i<=n;i++) read(p[i].first,p[i].second);
        iint ans=0;
        for (iint i=1;i<=n;i++)
        {
            iint m=0;
            static relpoint pp[1050<<1];
            for (iint j=1;j<=n;j++)
            if (i^j)
                pp[++m]=make_pair(atan2(p[j].second-p[i].second,p[j].first-p[i].first),point(p[j].first-p[i].first,p[j].second-p[i].second));
            sort(pp+1,pp+m+1);
            for (iint j=1;j<=m;j++)
            {
                pp[m+j]=pp[j];
                pp[m+j].first+=2.0*pi;
            }
            for (iint j=1,k=1;j<=m;j++)
            {
                while (k<j+m && pp[k].first+eps<pp[j].first+0.5*pi) ++k;
                iint wh=k;
                while (wh<j+m && fabs(pp[wh].first-(pp[j].first+0.5*pi))<eps)
                {
                    point p1=pp[wh].second,p2=pp[j].second;
                    iint now=abs(p1.second*p2.first-p1.first*p2.second);
                    if (now>=l && now<=r) ++ans;
                    ++wh;
                }
            }
        }
        print(ans,'\n');
    }
}