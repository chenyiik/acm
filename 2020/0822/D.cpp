#include<bits/stdc++.h>
using namespace std;
constexpr auto of=true;
using iint=conditional<of,long long,signed>::type;
using idouble=conditional<of,long double,double>::type;
constexpr bool dbg=!true;
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
void doo()
{
    iint n,m,s,t,x;
    static vector<pair<iint,iint>> G[100050];
    read(n,m,s,t,x);
    static string lrm;read(lrm);lrm='+'+lrm;
    for (iint i=1;i<=n;i++) G[i].clear();
    for (iint i=1;i<=m;i++)
    {
        iint u,v,w;
        read(u,v,w);
        G[u].push_back({v,w});
        G[v].push_back({u,w});
    }
    /*
    static deque<pair<iint,iint>> q;q.clear();
    static iint dist[100050][2],inq[100050][2];
    memset(dist,0x3f,sizeof(dist));
    memset(inq,0,sizeof(inq));
    if (lrm[s]=='L') dist[s][0]=0,inq[s][0]=1,q.push_back({s,0});
    else if (lrm[s]=='R') dist[s][1]=0,inq[s][1]=1,q.push_back({s,1});
    else {dist[s][0]=dist[s][1]=0;inq[s][0]=inq[s][1]=1;q.push_back({s,0});q.push_back({s,1});}
    while (q.size())
    {
        auto du=q.front();q.pop_front();
        iint u=du.first,h=du.second;
        inq[u][h]=0;
        for (auto vw:G[u])
        {
            iint v=vw.first,w=vw.second;
            char vhc=lrm[v];
            iint vh=-1;
            if (vhc=='L') vh=0;
            if (vhc=='R') vh=1;
            static auto relax=[&](){
                if (dist[u][h]+w<dist[v][vh])
                {
                    dist[v][vh]=dist[u][h]+w;
                    if (!inq[v][vh])
                    {
                        inq[v][vh]=1;
                        if (q.empty()||dist[v][vh]>=dist[q.front().first][q.front().second])
                            q.push_back({v,vh});
                        else q.push_front({v,vh});
                        if (dist[q.front().first][q.front().second]>dist[q.back().first][q.back().second])
                            swap(q.front(),q.back());
                    }
                }
            };
            if (vh!=-1)
            {
                if (vh==h)
                {
                    relax();
                }
                else
                {
                    w+=x;
                    relax();
                }
            }
            else
            {
                vh=h;
                relax();
                vh=h^1;w+=x;
                relax();
            }
        }
    }*/
    static iint dist[100050][2],vis[100050][2];
    memset(dist,0x3f,sizeof(dist));
    memset(vis,0,sizeof(vis));
    struct pqnd
    {
        pair<iint,iint> point;
        iint w;
        bool operator<(const pqnd& b) const
        {
            return w>b.w;
        }
    };
    priority_queue<pqnd> q;
    if (lrm[s]=='L') dist[s][0]=0,q.push({pair<iint,iint>{s,0},0});
    else if (lrm[s]=='R') dist[s][1]=0,q.push({pair<iint,iint>{s,1},0});
    else {dist[s][0]=dist[s][1]=0;q.push({pair<iint,iint>{s,0},0});q.push({pair<iint,iint>{s,1},0});}
    while (q.size())
    {
        auto pw=q.top();q.pop();
        iint u,h,w;w=pw.w;
        tie(u,h)=pw.point;
        if (vis[u][h]) continue;
        vis[u][h]=1;
        for (auto vw:G[u])
        {
            iint v=vw.first,w=vw.second;
            char vhc=lrm[v];
            iint vh=-1;
            if (vhc=='L') vh=0;
            if (vhc=='R') vh=1;
            static auto relax=[&](){
                if (dist[u][h]+w<dist[v][vh])
                {
                    dist[v][vh]=dist[u][h]+w;
                    q.push({pair<iint,iint>{v,vh},dist[v][vh]});
                }
            };
            if (vh!=-1)
            {
                if (vh==h)
                {
                    relax();
                }
                else
                {
                    w+=x;
                    relax();
                }
            }
            else
            {
                vh=h;
                relax();
                vh=h^1;w+=x;
                relax();
            }
        }
    }
    println(min(dist[t][0],dist[t][1]));
}
signed main()
{
    iint t;read(t);
    while (t--) doo();
}