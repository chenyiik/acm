#include<bits/stdc++.h>
using namespace std;
int w,h;
struct point
{
    int x,y,type,aimx,aimy,w;
};
vector<point> trans;
struct edget
{
    int v,w;
};
vector<edget> G[2050];
inline int getid(int x,int y)
{
    return h*x+y;
}
int spfa(int s,int t)
{
    static queue<int> q;
    static bool inq[2050];
    static int cinq[2050];
    static int dist[2050];
    q=queue<int>();
    memset(cinq,0,sizeof(cinq));
    memset(inq,0,sizeof(inq));
    memset(dist,0x3f,sizeof(dist));
    dist[s]=0;
    q.push(s);
    cinq[s]++;
    inq[s]=1;
    while (!q.empty())
    {
        int u=q.front();q.pop();inq[u]=false;
        for (auto x:G[u])
        {
            if (dist[x.v]>dist[u]+x.w)
            {
                dist[x.v]=dist[u]+x.w;
                ++cinq[x.v];
                if (cinq[x.v]>w*h+10) return -0x3f3f3f3f;
                if (!inq[x.v])
                {
                    q.push(x.v);
                    inq[x.v]=true;
                }
            }
        }
    }
    return dist[t];
}
int main()
{
    while (cin>>w>>h)
    {
        for (int i=0;i<2050;i++) G[i].clear();
        if (w+h==0) break;
        int n_ban;cin>>n_ban;
        static int b[50][50];
        memset(b,0,sizeof(b));
        while (n_ban--)
        {
            int x,y;
            cin>>x>>y;
            b[x][y]=1;
        }
        int n_trans;cin>>n_trans;
        trans.clear();
        for (int i=1;i<=n_trans;i++)
        {
            int x,y,aimx,aimy,w;
            cin>>x>>y>>aimx>>aimy>>w;
            b[x][y]=2;
            trans.push_back(point{x,y,2,aimx,aimy,w});
        }
        int s=getid(0,0),t=getid(w-1,h-1);
        for (int i=0;i<w;i++)
            for (int j=0;j<h;j++)
            if (b[i][j]==0 && !(i==w-1 && j==h-1))
            {
                int n=getid(i,j);
                if (i>=1 && b[i-1][j]!=1) G[n].push_back(edget{getid(i-1,j),1});
                if (j<h-1 && b[i][j+1]!=1) G[n].push_back(edget{getid(i,j+1),1});
                if (i<w-1 && b[i+1][j]!=1) G[n].push_back(edget{getid(i+1,j),1});
                if (j>=1 && b[i][j-1]!=1) G[n].push_back(edget{getid(i,j-1),1});
            }
        for (auto x:trans)
        {
            G[getid(x.x,x.y)].push_back(edget{getid(x.aimx,x.aimy),x.w});
        }
        auto ans=spfa(s,t);
        if (ans==-0x3f3f3f3f) puts("Never");
        if (ans==0x3f3f3f3f) puts("Impossible");
        if (ans!=-0x3f3f3f3f && ans!=0x3f3f3f3f) printf("%d\n",ans);
    }
}