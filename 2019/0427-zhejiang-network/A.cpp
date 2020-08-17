#include<bits/stdc++.h>
using namespace std;
int ecnt[100050];
int fa[100050];
int size[100050];
set<int> roots;
int find(int x)
{
	while (fa[x]!=x)
	{
		int tmp=x;
		x=fa[x];
		fa[tmp]=x;
	}
}
int getecnt(int p)
{
	return ecnt[find(p)];
}
void update_ecnt(int p)
{
	while (fa[p]!=p)
	{
		ecnt[fa[p]]=ecnt[p];
		p=fa[p];
	}
}
void merge(int u,int v)
{
	size[find(u)]+=size[find(v)];
	fa[find(v)]=u;
	ecnt[fa[v]]+=getecnt(v);
}
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	int T;
	cin>>T;
	while(T--)
	{
		int n,q;
		cin>>n>>q;
		roots.clear();
		for (int i=1;i<=n;i++) fa[i]=i,size[i]=1,ecnt[i]=0,roots.insert(i);
		int cnt=n;
		while(q--)
		{
			int op;
			cin>>op;
			if (op==1)
			{
				int u,v;
				cin>>u>>v;
				ecnt[v]++;ecnt[u]++;
				update_ecnt(v);update_ecnt(u);
				merge(u,v);
				update_ecnt(v);update_ecnt(u);
				roots.erase(v);
			}
			if (op==2)
			{
				int k;
				cin>>k;
				if (k>=roots.size()-1) cout<<1<<" ";else cout<<roots.size()-k<<" ";
				for (auto x:roots) 
				{
					k-=((size[x]*(size[x]-1)/2)-ecnt[x]);
				}
				if (k<=0) cout<<roots.size()<<endl;
				else
				{
					int ans=roots.size();
					static priority_queue<int> pq;
					for (auto x:roots) pq.push(size[x]);
					while (k>0 && !pq.empty())
					{
						k-=pq.top();pq.pop();
						ans--;
					}
					cout<<ans<<endl;
				}
			}
		}
	}
	return 0;
}
