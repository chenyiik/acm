#include<bits/stdc++.h>
using namespace std;
const int fibt=50;
vector<long long> hive[int(4e5+50)];
int used=0;
int alloc()
{
	hive[used].clear();
	hive[used].reserve(fibt+1);
	return used++;
}
struct node
{
	int v;
	int l,r;
}tree[int(4e5+50)];
long long a[int(1e5+5)];
vector<long long> merge2(const vector<long long>& a,const vector<long long>& b)
{
	vector<long long> c;
	int i=0,j=0;
	while (i<a.size() && j<b.size() && c.size()<fibt)
	if (a[i]>=b[j]) c.push_back(a[i++]);
	else c.push_back(b[j++]);
	while (i<a.size() && c.size()<fibt) c.push_back(a[i++]);
	while (j<b.size() && c.size()<fibt) c.push_back(b[j++]);
	return c;
}
vector<long long> merge(const vector<long long>& a,const vector<long long>& b)
{
	vector<long long> c(a.size()+b.size());
	merge(a.begin(),a.end(),b.begin(),b.end(),c.begin(),[](const long long &x,const long long &y){return x>y;});
	if (c.size()>fibt) c.resize(fibt);
	return c;
}
void up(int x)
{
	hive[tree[x].v]=std::move(merge(hive[tree[x<<1].v],hive[tree[x<<1|1].v]));
}
void build(int x,int l,int r)
{
	tree[x].v=alloc();
	tree[x].l=l,tree[x].r=r;
	if (l==r) 
	{
		hive[tree[x].v].push_back(a[l]);
		/*cout<<tree[x].l<<" "<<tree[x].r<<" ";
		for (auto xx:tree[x].v) cout<<xx<<" ";
		cout<<endl;*/
		return;
	}
	int mid=(l+r)>>1;
	build(x<<1,l,mid);
	build(x<<1|1,mid+1,r);
	up(x);
	/*cout<<tree[x].l<<" "<<tree[x].r<<" ";
	for (auto xx:tree[x].v) cout<<xx<<" ";
	cout<<endl;*/
}
vector<long long> query(int x,int l,int r)
{
	vector<long long> ans;
	int ll=tree[x].l,rr=tree[x].r;
	if (ll>=l && rr<=r) return hive[tree[x].v];
	int mid=(ll+rr)>>1;
	if (l<=mid) ans=merge(ans,query(x<<1,l,r));
	if (r>mid) ans=merge(ans,query(x<<1|1,l,r));
	return ans;
}
int main()
{
	int n,q;
	ios::sync_with_stdio(0);cin.tie(0);
	while(cin>>n>>q)
	{
		used=0;
		for (int i=1;i<=n;i++) cin>>a[i];
		build(1,1,n);
		while (q--)
		{
			int l,r;
			cin>>l>>r;
			long long ans=-1;
			vector<long long> res=std::move(query(1,l,r));
			for (int i=0;i<res.size()-2;i++)
			{
				long long x=res[i],y=res[i+1],z=res[i+2];
				if (x<y+z) {ans=x+y+z;break;}
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}
