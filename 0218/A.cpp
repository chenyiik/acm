#include<bits/stdc++.h>
using namespace std;
struct point
{
    double x,y;
    point(){x=y=0;}
    void get(){cin>>x>>y;}
};
double dist(point a,point b)
{
    auto sqr=[](double x){return x*x;};
    return ceil(sqrt(sqr(a.x-b.x)+sqr(a.y-b.y)));
}
struct edget
{
    int v;
    double w1,w2;
};
vector<edget> G[1050];
struct stt
{
    point wh;
    vector<pair<int,int>> links;
    stt(){};
};
vector<stt> bus;
point s1,t1;
int B,Ccar,T,N;
double C[105];
int s,t;
double dis[1050],lim[1050];
struct val
{
    int v;
    double d,lm;
    vector<int> fr;
    bool operator<(const val& b) const
    {
        return d>b.d;
    }
};
double ans;
void spfa()
{
    static priority_queue<val> q;
    bool inq[1050];
    memset(inq,0,sizeof(inq));
    for (int i=0;i<=1001;i++) {lim[i]=0;dis[i]=(1e9+7);}
    inq[s]=1;q.push({s,0,0,vector<int>()});dis[s]=0;
    ans=(1e9+7);
    while (!q.empty())
    {
        int u=q.top().v;
        inq[u]=false;
        double lm=q.top().lm,ds=q.top().d;
        vector<int> route=std::move(q.top().fr);
        if (u==90 && route.size()==1) cerr<<q.top().v<<" "<<q.top().lm<<" "<<q.top().d<<endl;
        q.pop();
        for (auto x:G[u])
        {
            if (x.v==u) continue;
            if (dis[x.v]>ds+x.w1 && lm+x.w2<=B)
            {
                if (u==90 && route.size()==1) cerr<<x.v<<endl;
                dis[x.v]=ds+x.w1;
                lim[x.v]=lm+x.w2;
                vector<int> tmp=route;
                tmp.push_back(u);
                q.push({x.v,dis[x.v],lim[x.v],tmp});
                if (tmp.size()>1 && tmp[1]==90)
                {
                    cout<<"\t";
                    for (auto x:tmp) cout<<x<<" ";
                    cout<<dis[x.v]<<endl;
                }
            }
            /*else if (dis[x.v]==dis[u]+x.w1 && lim[u]+x.w2<lim[x.v])
            {
                lim[x.v]=lim[u]+x.w2;
                if (!inq[x.v]) {inq[x.v]=1;q.push(x.v);}
            }*/
        }
        ans=min(ans,dis[t]);
    }
}
vector<int> r[1050][1050];
double f[1050][1050];
double solve(int u,double b)
{
    if (u==t) return 0;
    if (f[u][int(floor(b))]!=-1) return f[u][int(floor(b))];
    f[u][int(floor(b))]=0x3f3f3f3f;
    r[u][int(floor(b))].clear();
    for (auto a:G[u])
    {
        int v=a.v;
        double d=a.w2,cost=a.w1;
        if (d<=b)
        {
            auto ds=cost+solve(v,b-d);
            if (f[u][int(floor(b))]>ds)
            {
                f[u][int(floor(b))]=ds;
                r[u][int(floor(b))]=r[v][int(floor(b)-floor(d))];
                r[u][int(floor(b))].push_back(v);
            }
        }
    }
    return f[u][int(floor(b))];
}
int main()
{
    s1.get(),t1.get();
    cin>>B>>Ccar>>T;
    for (int i=1;i<=T;i++) cin>>C[i];
    cin>>N;
    for (int i=1;i<=N;i++)
    {
        stt tmp;tmp.wh.get();
        int l;
        cin>>l;
        for (int i=1;i<=l;i++)
        {
            int to,by;
            cin>>to>>by;
            tmp.links.push_back({to,by});
        }
        bus.emplace_back(tmp);
    }
    s=0,t=N+1;
    G[s].push_back({t,Ccar*dist(s1,t1),dist(s1,t1)});
    for (int i=1;i<=N;i++)
    {
        G[s].push_back({i,Ccar*dist(s1,bus[i-1].wh),dist(s1,bus[i-1].wh)});
        G[i].push_back({t,Ccar*dist(bus[i-1].wh,t1),dist(bus[i-1].wh,t1)});
    }
    for (int i=1;i<=N;i++)
    {
        auto tl=bus[i-1].wh;
        for (auto x:bus[i-1].links)
        {
            auto tt=bus[x.first].wh;
            G[i].push_back({x.first+1,C[x.second]*dist(tl,tt),dist(tl,tt)});
            G[x.first+1].push_back({i,C[x.second]*dist(tl,tt),dist(tl,tt)});
        }
    }
    //spfa();
    for (int i=0;i<=1005;i++)
        for (int j=0;j<=1005;j++)
            f[i][j]=-1;
    auto tt=solve(s,B);
    if (tt>100000) tt=-1;
    cout<<floor(tt)<<endl;
    //for (auto x:r[s][B]) cout<<x<<" ";
    //cout<<((ans>(1e9-5))?-1:floor(ans))<<endl;
}