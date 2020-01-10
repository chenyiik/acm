#include<iostream>
#include<queue>
#include<cstring>
#include<cstdio>
using namespace std;
int n,m;
int edge[505][505],flow[505],height[505];
int s,t,maxflow;
queue<int> q;
void init()
{
	maxflow=0;
	s=0,t=n;
	height[s]=n;
	flow[s]=0x3f3f3f3f;
	flow[t]=-flow[s];
}
void push(int x)
{
	for (int i=0;i<=n;i++)
	{
		int tmp=min(edge[x][i],flow[x]);
		if (tmp>0 && (x==s||height[x]-height[i]==1))
		{
			edge[x][i]-=tmp,edge[i][x]+=tmp;
			flow[x]-=tmp,flow[i]+=tmp;
			if (i==t) maxflow+=tmp;
			if (i!=s && i!=t) q.push(i);
		}
	}
}
void relabel(int x)
{
	if (x!=s && x!=t && flow[x]>0)
	{
		height[x]++;
		q.push(x);
	}
}
void preflow()
{
	q.push(s);
	while (!q.empty())
	{
		int x=q.front();q.pop();
		push(x);relabel(x);
	}
}
int main()
{
    int N,F,D;
    //ios::sync_with_stdio(0);cin.tie(0);
    while(~scanf("%d%d%d",&N,&F,&D))
    {
        memset(edge,0,sizeof(edge));
        n=F+D+2*N+1;
        init();
        for(int i=1;i<=F;i++) edge[0][i]=1;
        for(int i=n-D;i<=n-1;i++) edge[i][n]=1;
        for(int i=1;i<=N;i++) edge[F+2*i-1][F+2*i]=1;
        for(int i=1;i<=N;i++)
        {
			int k1,k2,u;
            scanf("%d%d",&k1,&k2);
            while(k1--)
            {
                scanf("%d",&u);
                edge[u][F+2*i-1]=1;
            }
            while(k2--)
            {
                scanf("%d",&u);
                edge[F+2*i][F+2*N+u]=1;
            }
        }
       preflow();
       cout<<maxflow<<endl;
    }
    return 0;
}