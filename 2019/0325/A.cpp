#include<algorithm>
#include<iostream>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;
#define inf 0x3f3f3f3f
const int maxn = 100010;
const int maxm = 1000100;
struct spot {
	int st[60], en[60], sum;
}spt[maxn];
struct fuck {
	int u, ne, v, w;
}ed[maxm];
struct anst
{
	int from,to,len;
	anst(int _from=0,int _to=0,int _len=0):from(_from),to(_to),len(_len){};
};
vector<anst> ansr;
int n, m, cnt;
int head[maxn], dis[maxn], cur[maxn];
void add(int u, int v, int w) 
{
	ed[cnt].w = w; ed[cnt].v = v; ed[cnt].u = u;
	ed[cnt].ne = head[u]; head[u] = cnt++;
	ed[cnt].w = 0; ed[cnt].v = u; ed[cnt].u = v;
	ed[cnt].ne = head[v]; head[v] = cnt++;
}
int bfs(int st, int en) {
	queue<int>q;
	while (!q.empty())q.pop();
	memset(dis, 0, sizeof(dis));
	dis[st] = 1;
	q.push(st);
	while (!q.empty()) {
		int u = q.front(); q.pop();
		if (u == en)return 1;
		for (int s = head[u]; ~s; s = ed[s].ne) {
			int v = ed[s].v;
			if (dis[v] == 0 && ed[s].w > 0) {
				dis[v] = dis[u] + 1; q.push(v);
			}
		}
	}
	return dis[en] != 0;
}
int dfs(int st, int en, int flow) {
	int res = flow, a;
	if (st == en || flow == 0)return flow;
	for (int &s = cur[st]; ~s; s = ed[s].ne) {
		int v = ed[s].v;
		if (dis[v] == dis[st] + 1 && (a = dfs(v, en, min(res, ed[s].w)))) {
			ed[s].w -= a;
			ed[s ^ 1].w += a;
			res -= a;
			if (!res)break;
		}
	}
	if (res == flow)dis[st] = 0;
	return flow - res;
}
int dinic(int st, int en,int n) 
{
	int ans=0;
	while (bfs(st,en))
	{
		for (int s = 0; s <= n; s++)
			cur[s] = head[s];
		ans += dfs(st, en, inf);
	}
	return ans;
}


int rec(int x) {
	if (x % 2)x += 1;
	return x >> 1;
	return x;
}
int get(int x) 
{
	bool st=1,en=1;
	for (int i=1;i<=m;i++) 
	{
		if (spt[x].st[i]==1) st=0;
		if (spt[x].en[i]==0) en=0;
	}
	if (st==1 && en==1) return 2;
	if (st==1) return 0;
	if (en==1) return 1;
	return -1;
}
bool link(int a,int b)
{
	for (int i=1;i<=m;i++)
	if (spt[a].en[i]!=spt[b].st[i] && spt[b].st[i]!=2) return false;
	return true;
};
int main() 
{
	ios::sync_with_stdio(0);cin.tie(0);
	while (cin>>m>>n) 
	{
		cnt=0;
		memset(head,-1,sizeof(head));
		int sink=2*n+1;
		for (int i=1;i<=n;i++) 
		{
			cin>>spt[i].sum;
			add(2*i-1,2*i,spt[i].sum);
			for (int j=1;j<=m;j++) cin>>spt[i].st[j];
			for (int j=1;j<=m;j++) cin>>spt[i].en[j];
		}
		for (int i=1;i<=n;i++) 
		{
			int t=get(i);
			if (t==1) add(2*i,sink,inf);
			if (t==0) add(0,2*i-1,inf);
			if (t==2) add(2*i,sink,inf),add(0,2*i-1,inf);
		}
		for(int i=1;i<n;i++)
		for(int j=i+1;j<=n;j++)
		{
			if (link(i,j)) add(2*i,2*j-1,inf);
			if (link(j,i)) add(2*j,2*i-1,inf);
		}
		int ans=dinic(0,sink,sink);
		ansr.clear();
		for (int s=0;s<cnt;s+=2) 
		{
			if (ed[s^1].w>0 && ed[s].u!=0 && ed[s].v!=sink && rec(ed[s].u)!=rec(ed[s].v)) 
			ansr.push_back(anst(rec(ed[s].u),rec(ed[s].v),ed[s ^ 1].w));
		}
		cout<<ans<<" "<<ansr.size()<<endl;
		for (vector<anst>::iterator x=ansr.begin();x!=ansr.end();++x) cout<<(*x).from<<" "<<(*x).to<<" "<<(*x).len<<endl;
	}
}