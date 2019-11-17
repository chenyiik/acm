#include<bits/stdc++.h>
using namespace std;
const int maxn=4050;
const int N=4005,M=3200000;
const int inf=0x3f3f3f3f;
const int INF=inf;
struct edge {
    int to, capacity, cost, rev;
    edge() {}
    edge(int to, int _capacity, int _cost, int _rev) :to(to), capacity(_capacity), cost(_cost), rev(_rev) {}
};
namespace Min_Cost_Max_Flow {
    int V, H[maxn + 5], dis[maxn + 5], PreV[maxn + 5], PreE[maxn + 5];
    vector<edge> G[maxn + 5];
    //调用前初始化
    void Init(int n) {
        V = n;
        for (int i = 0; i <= V; ++i)G[i].clear();
    }
    //加边
    void Add_Edge(int from, int to, int cap, int cost) {
        G[from].push_back(edge(to, cap, cost, G[to].size()));
        G[to].push_back(edge(from, 0, -cost, G[from].size() - 1));
    }
    //flow是自己传进去的变量，就是最后的最大流，返回的是最小费用
    int Min_cost_max_flow(int s, int t, int f, int& flow) {
        int res = 0; fill(H, H + 1 + V, 0);
        while (f) {
            priority_queue <pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > q;
            fill(dis, dis + 1 + V, INF);
            dis[s] = 0; q.push(pair<int, int>(0, s));
            while (!q.empty()) {
                pair<int, int> now = q.top(); q.pop();
                int v = now.second;
                if (dis[v] < now.first)continue;
                for (int i = 0; i < G[v].size(); ++i) {
                    edge& e = G[v][i];
                    if (e.capacity > 0 && dis[e.to] > dis[v] + e.cost + H[v] - H[e.to]) {
                        dis[e.to] = dis[v] + e.cost + H[v] - H[e.to];
                        PreV[e.to] = v;
                        PreE[e.to] = i;
                        q.push(pair<int, int>(dis[e.to], e.to));
                    }
                }
            }
            if (dis[t] == INF)break;
            for (int i = 0; i <= V; ++i)H[i] += dis[i];
            int d = f;
            for (int v = t; v != s; v = PreV[v])d = min(d, G[PreV[v]][PreE[v]].capacity);
            f -= d; flow += d; res += d*H[t];
            for (int v = t; v != s; v = PreV[v]) {
                edge& e = G[PreV[v]][PreE[v]];
                e.capacity -= d;
                G[v][e.rev].capacity += d;
            }
        }
        return res;
    }
    int Max_cost_max_flow(int s, int t, int f, int& flow) {
        int res = 0;
        fill(H, H + 1 + V, 0);
        while (f) {
            priority_queue <pair<int, int> > q;
            fill(dis, dis + 1 + V, -INF);
            dis[s] = 0;
            q.push(pair<int, int>(0, s));
            while (!q.empty()) {
                pair<int, int> now = q.top(); q.pop();
                int v = now.second;
                if (dis[v] > now.first)continue;
                for (int i = 0; i < G[v].size(); ++i) {
                    edge& e = G[v][i];
                    if (e.capacity > 0 && dis[e.to] < dis[v] + e.cost + H[v] - H[e.to]) {
                        dis[e.to] = dis[v] + e.cost + H[v] - H[e.to];
                        PreV[e.to] = v;
                        PreE[e.to] = i;
                        q.push(pair<int, int>(dis[e.to], e.to));
                    }
                }
            }
            if (dis[t] == -INF)break;
            for (int i = 0; i <= V; ++i)H[i] += dis[i];
            int d = f;
            for (int v = t; v != s; v = PreV[v])d = min(d, G[PreV[v]][PreE[v]].capacity);
            f -= d; flow += d;
            res += d*H[t];
            for (int v = t; v != s; v = PreV[v]) {
                edge& e = G[PreV[v]][PreE[v]];
                e.capacity -= d;
                G[v][e.rev].capacity += d;
            }
        }
        return res;
    }
};
int a[2050];
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n,k;
        scanf("%d%d",&n,&k);
        for (int i=1;i<=n;i++) scanf("%d",&a[i]);
        Min_Cost_Max_Flow::Init(2*n+3);
        for (int i=1;i<=n;i++)
        {
            Min_Cost_Max_Flow::Add_Edge(i,i+n,1,-a[i]);
            for (int j=i+1;j<=n;j++)
                if (a[i]<=a[j])
                    Min_Cost_Max_Flow::Add_Edge(i+n,j,1,0);
        }
        int ss=0,s2=2*n+1,tt=2*n+2;
        Min_Cost_Max_Flow::Add_Edge(ss,s2,k,0);
        for (int i=1;i<=n;i++) Min_Cost_Max_Flow::Add_Edge(s2,i,1,0);
        for (int i=1;i<=n;i++) Min_Cost_Max_Flow::Add_Edge(i+n,tt,1,0);
        int fl=0;
        printf("%d\n",-Min_Cost_Max_Flow::Min_cost_max_flow(ss,tt,INF,fl));
    }
    return 0;
}