#include<bits/stdc++.h>
using namespace std;
const int maxn=int(1e6+10);
const int M=maxn*30;
int n,m=maxn-10,tot,a[maxn],T[maxn],lson[M],rson[M],c[M];
void Rd(int &res){
	res=0;
	char c;
	while(c=getchar(),!isdigit(c));
	do{
		res=(res*10)+(c^48);
	}while(c=getchar(),isdigit(c));
}
inline void out(int x){
	if(x>9)out(x/10);
	putchar(x%10+'0');
}
int build(int l,int r)
{
	int root=tot++;
	c[root]=0;
	if (l!=r)
	{
		int mid=(l+r)>>1;
		lson[root]=build(l,mid);
		rson[root]=build(mid+1,r);
	}
	return root;
}
int update(int root,int pos,int val)
{
	int newroot=tot++,tmp=newroot;
	c[newroot]=c[root]+val;
	int l=1,r=m;
	while (l<r)
	{
		int mid=(l+r)>>1;
		if (pos<=mid)
		{
			lson[newroot]=tot++;rson[newroot]=rson[root];
			newroot=lson[newroot];root=lson[root];
			r=mid;
		} else{
			rson[newroot]=tot++;lson[newroot]=lson[root];
			newroot=rson[newroot];root=rson[root];
			l=mid+1;
		}
		c[newroot]=c[root]+val;
	}
	return tmp;
}
int query(int left_root,int right_root,int x)
{
	int l=1,r=m;
	int sum=0;
	while (l<r)
	{
		int mid=(l+r)>>1;
		if (mid <= x){
			sum+=c[lson[left_root]]-c[lson[right_root]];
			l=mid+1;
			left_root=rson[left_root];
			right_root=rson[right_root];
		}else{
			r=mid;
			left_root=lson[left_root];
			right_root=lson[right_root];
		}
	}
	return sum;
}
int main()
{
	int cas;
	Rd(cas);
	while(cas--){
		int X=0;
		int Q;
		tot=0;
		Rd(n),Rd(Q);
		for(int i=1;i<=n;i++)
			Rd(a[i]);
		T[n+1]=build(1,m);
		for (int i=n;i;i--)
			T[i]=update(T[i+1],a[i],1);
		while(Q--){
			int L,R,p,K;
			Rd(L),Rd(R),Rd(p),Rd(K);
			L^=X;
			R^=X;
			p^=X;
			K^=X;
			int l=0,r=m;
			while(l<=r){
				int mid=(l+r)>>1;
				int b=min(m,p+mid);
				int a=max(1,p-mid);
				if(query(T[L],T[R+1],b)-query(T[L],T[R+1],a-1)>=K){
					X=mid;
					r=mid-1;
				}else{
					l=mid+1;
				}
			}
			out(X);
			puts("");
		}
	}
}
