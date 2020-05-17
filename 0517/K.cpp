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
vector<pair<int,int>> mv={{1,0},{-1,0},{0,1},{0,-1}};
string s[35];
int n,m,bias,cnt;
struct edget
{
    int v,w,nxt;
};
edget edges[200050];
int head[5050];
void addedge(int u,int v,int w)
{
    edges[cnt]={v,w,head[u]};head[u]=cnt++;
    edges[cnt]={u,0,head[v]};head[v]=cnt++;
}
int S,T;
int d[5050];
bool bfs()
{
    static queue<int> q;while (q.size()) q.pop();
    memset(d,-1,sizeof(d));
    d[S]=0;q.push(S);
    while (q.size())
    {
        int u=q.front();q.pop();
        for (int i=head[u];~i;i=edges[i].nxt)
        {
            int v=edges[i].v,w=edges[i].w;
            if (w && !(~d[v]))
            {
                q.push(v);d[v]=d[u]+1;
            }
        }
    }
    return ~d[T];
}
int dfs(int u,int f)
{
    if (u==T||!f) return f;
    int res=0;
    for (int i=head[u];~i;i=edges[i].nxt)
    {
        int v=edges[i].v,w=edges[i].w;
        if (w && !(d[v]-d[u]-1))
        {
            res=dfs(v,min(w,f));
            if (res)
            {
                edges[i].w-=res;
                edges[i^1].w+=res;
                return res;
            }
        }
    }
    d[u]=-1;
    return res;
}
int dinic()
{
    int flow=0,res;
    while (bfs())
        while (res=dfs(S,0x3f3f3f3f))
            flow+=res;
    return flow;
}
signed main()
{
    while (getline(cin,s[0]))
    {
        m=s[0].size(),n=1;
        while (getline(cin,s[n]) && s[n].size()) n++;
        bias=n*m;memset(head,-1,sizeof(head));cnt=0;
        for (int i=0;i<bias;i++) addedge(i,i+bias,1);
        S=bias<<1;T=S|1;
        for (int i=0;i<n;i++)
            for (int j=0;j<m;j++)
            {
                int idx=i*m+j;
                if (s[i][j]=='W') addedge(S,idx,1);
                idx+=bias;
                if (s[i][j]=='N') addedge(idx,T,1);
                for (auto km:mv)
                {
                    int x=i+km.first,y=j+km.second;
                    if (x>=0&&y>=0&&x<n&&y<m&&((s[i][j]=='W'&&s[x][y]=='I')||(s[i][j]=='I'&&s[x][y]=='N')))
                    {
                        int idx2=x*m+y;
                        addedge(idx,idx2,1);
                    }
                }
            }
        print(dinic(),'\n');
    }
}