//#include<bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
#define INF 0x7f7f7f7f7f7f7f7f
#define MAXN 10050
#define MAXM 5005001
long long n,m,S,T,Sta,End,Ws[MAXM],W,C;
queue<long long>q;
namespace Dinic
{  
    long long v[MAXM],cap[MAXM],en,first[MAXN],next[MAXM];
    long long d[MAXN],cur[MAXN];
    void Init_Dinic(){memset(first,-1,sizeof(first)); en=0; S=1; T=n;}
    void AddEdge(const long long &U,const long long &V,const long long &W)
    {v[en]=V; cap[en]=W; next[en]=first[U]; first[U]=en++;
    v[en]=U; next[en]=first[V]; first[V]=en++;}
    bool bfs()
    {
    	while (!q.empty()) q.pop();
    	memset(d,-1,sizeof(d)); q.push(S); d[S]=0;
        while(!q.empty())
        {
        	long long U=q.front(); q.pop();
            for(long long i=first[U];i!=-1;i=next[i])
            if(d[v[i]]==-1 && cap[i])
            {
                d[v[i]]=d[U]+1;
                q.push(v[i]);
            }
        }
        return d[T]!=-1;
    }
    long long dfs(long long U,long long a)
    {
        if(U==T || !a) return a;
        long long Flow=0,f;
        for(long long &i=cur[U];i!=-1;i=next[i])
        if(d[U]+1==d[v[i]] && (f=dfs(v[i],min(a,cap[i]))))
        {
            cap[i]-=f; cap[i^1]+=f;
            Flow+=f; a-=f; if(!a) break;
        }
        if(!Flow) d[U]=-1;
        return Flow;
    }
    long long max_flow()
    {
    	long long Flow=0,tmp=0;
        while(bfs())
        {
            memcpy(cur,first,(n+5)*sizeof(long long));
            while(tmp=dfs(S,INF)) Flow+=tmp;
        }
        return Flow;
    }
};
namespace SPFA
{
    long long u[MAXM],next[MAXM],v[MAXM],first[MAXN],w[MAXM],en,dis[MAXN];
    bool inq[MAXN];
    void init(){memset(first,0,sizeof(first));en=0;}
    void AddEdge(const long long &U,const long long &V,const long long &W,const long long &C)
    {u[++en]=U;v[en]=V;w[en]=W;Ws[en]=C;next[en]=first[U];first[U]=en;}
    void spfa(const long long &s)
    {
    	while (!q.empty()) q.pop();
    	memset(dis,0x7f,sizeof(dis));
    	dis[s]=0; inq[s]=1; q.push(s);
        while(!q.empty())
        {
        	long long U=q.front();
            for(long long i=first[U];i;i=next[i])
            if(dis[v[i]]>dis[U]+w[i])
            {
                dis[v[i]]=dis[U]+w[i];
                if(!inq[v[i]]) q.push(v[i]),inq[v[i]]=1;
            }
        	q.pop(); inq[U]=0;
        }
    }
    void Rebuild_Graph()
    {
    	Dinic::Init_Dinic();
        for(long long i=1;i<=m;++i)
        if(dis[u[i]]+w[i]==dis[v[i]])
        Dinic::AddEdge(u[i],v[i],Ws[i]);
    }
};
int main()
{
	long long T;
	scanf("%lld",&T);
	while (T--)
	{
	    scanf("%lld%lld",&n,&m);
	    if (n==1) {printf("%lld\n",0);continue;}
	    SPFA::init();
	    for(long long i=1;i<=m;++i)
	    {
	    	scanf("%lld%lld%lld",&Sta,&End,&W);
	    	SPFA::AddEdge(Sta,End,W,W);
	    }
	    SPFA::spfa(1);SPFA::Rebuild_Graph();
	    printf("%lld\n",Dinic::max_flow());
	}
    return 0;
}
