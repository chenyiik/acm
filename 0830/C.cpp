#includebitsstdc++.h
using namespace std;
constexpr auto of=true;
using iint=conditionalof,long long,signedtype;
using idouble=conditionalof,long double,doubletype;
constexpr bool dbg=!true;
templateiint buffersz
inline char igetchar()
{
    static char buf[buffersz],p1=buf,p2=buf;
    return p1==p2 && (p2=(p1=buf)+fread(buf,1,buffersz,stdin),p1==p2)EOFp1++;
}
templateiint buffersz,class T
void read_one(T&x)
{
    static_assert(is_convertiblechar,Tvalue,Not supporting type);
    x=0;
    iint f=0;
    char ch=igetcharbuffersz();
    while(!isdigit(ch)) f=(ch=='-'),ch=igetcharbuffersz();
    while(isdigit(ch)) x=(x1)+(x3)+(ch^48),ch=igetcharbuffersz();
    x=f-xx;
}
void readint()
{}
templateiint buffersz=dbg1(iint)1e4,typename T,typename... U
void readint(T&arg,U&... args)
{
    static_assert(is_convertiblechar,Tvalue,Not supporting type);
    read_onebuffersz(arg);
    readint(args...);
}
bool firstrun=true;
decltype(cout.flags()) st;
void ifastios()
{
    if(!dbg) iossync_with_stdio(0),cin.tie(0);
    firstrun=false;
}
void print()
{}
templateiint precision=-1,typename T,typename... U
void print(T&&arg,U&&... args)
{
    if(precision=0)
    {
        st=cout.flags();
        cout.setf(iosfixed);
        cout.precision(precision);
    }
    if(firstrun) ifastios();
    coutforwardT(arg);
    print(args...);
    if(precision=0) cout.flags(st);
}
templateiint precision=-1,typename T,typename... U
void println(T&&arg,U&&... args)
{
    printprecision(forwardT(arg),forwardU(args)...,'n');
}
void read()
{}
templatetypename T,typename... U
void read(T&arg,U&... args)
{
    if(firstrun) ifastios();
    cinarg;
    read(args...);
}
void doo()
{
    int x1,x2,x3,y1,y2,y3;
    read(x1,y1,x2,y2,x3,y3);
    iint v1x=x2-x1,v1y=y2-y1,v2x=x3-x2,v2y=y3-y2;
    iint ans=v1xv2y-v2xv1y;
    println(vectorstring({Clockwise,Counterclockwise})[ans0]);
}
signed main()
{
    int t;read(t);
    while (t--) doo();
}