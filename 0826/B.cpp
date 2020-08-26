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
    if(!dbg) ios::sync_with_stdio(0),cin.tie(0);
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
template<iint precision=-1,typename T,typename... U>
void println(T&&arg,U&&... args)
{
    print<precision>(forward<T>(arg),forward<U>(args)...,'\n');
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
iint getval(string s,iint radix)
{
    iint fac=1,ans=0;
    for (iint i=s.size()-1;i>=0;i--)
    {
        iint bval=isdigit(s[i])?s[i]-'0':s[i]-'A'+10;
        ans+=bval*fac;
        fac*=radix;
    }
    return ans;
}
iint doo(string& s)
{
    iint e=2;
    string a,b,c;
    iint opn;
    static map<char,iint> opers({{'+',1},{'-',2},{'*',3},{'/',4}});
    for (iint i=0,k=0;i<s.size();i++)
    {
        if (isdigit(s[i]))
            e=max(e,s[i]-'0'+1LL);
        if (isupper(s[i]))
            e=max(e,s[i]-'A'+11LL);
        if (opers[s[i]])
        {
            a=string(s,0,i);
            k=i;
            opn=opers[s[i]];
        }
        if (s[i]=='=')
        {
            b=string(s,k+1,i-k-1);
            c=string(s,i+1);
        }
    }
    while (e<=16)
    {
        iint va,vb,vc;
        va=getval(a,e);
        vb=getval(b,e);
        vc=getval(c,e);
        if (opn==1) if (va+vb==vc) return e;
        if (opn==2) if (va-vb==vc) return e;
        if (opn==3) if (va*vb==vc) return e;
        if (opn==4) if (va==vc*vb) return e;
        e++;
    }
    return -1;
}
signed main()
{
    string s;
    while (cin>>s) println(doo(s));
}