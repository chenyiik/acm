#include<bits/stdc++.h>
using namespace std;
int n;
vector<int> G[100050];
int fa[100050];
vector<int> son[100050];
int a[100050],b[100050],sa[100050],sb[100050];
double dv[100050];
void dfs(int rt,int fr)
{
	fa[rt]=fr;
	for (auto x:G[rt])
	if (x!=fr)
	{
		son[rt].push_back(x);
		dfs(x,rt);
	}
}
void stat(int rt)
{
	sa[rt]=a[rt],sb[rt]=b[rt];
	for (auto x:son[rt])
	{
		stat(x);
		sa[rt]+=sa[x],sb[rt]+=sb[x];
	}
	dv[rt]=1.0*sa[rt]/sb[rt];
}
vector<int> res;
void getseq(int rt)
{
	res.push_back(rt);
	sort(son[rt].begin(),son[rt].end(),[](int a,int b){return dv[a]>dv[b];});
	for (auto x:son[rt])
		getseq(x);
}
long long allb=0;
int main()
{
	ios::sync_with_stdio(0);
	int t;cin>>t;
	while (t--)
	{
		cin>>n;
		for (int i=1;i<=n;i++) cin>>b[i],sb[i]=0,dv[i]=0;
		for (int i=1;i<=n;i++) cin>>a[i],sa[i]=0;
		for (int i=1;i<=n;i++) G[i].clear(),son[i].clear(),fa[i]=-1;
		for (int i=1;i<n;i++) 
		{
			int u,v;cin>>u>>v;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		dfs(1,-1);
		stat(1);res.clear();
		getseq(1);
		//cout<<"res:";
		//for (auto x:res) cout<<x<<",";cout<<endl;
		allb=sb[1];
		long long ans=0;
		for (auto x:res)
		{
			allb-=b[x];
			ans+=1LL*a[x]*allb;
		}
		cout<<ans<<endl;
	}
}
