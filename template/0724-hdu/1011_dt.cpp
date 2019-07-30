#include<bits/stdc++.h>
using namespace std;
const size_t maxN=1e5+5;
namespace divided_tree
{
	long long tree[25][maxN];
	long long sorted[maxN];
	long long toLeft[25][maxN];
	void init()
	{
		memset(tree,0,sizeof(tree));
    	memset(toLeft,0,sizeof(toLeft));
    }
	void build(long long l,long long r,long long dep) 
	{
	    if (l==r) return;
	    long long mid=(l+r)>>1;
	    long long same=mid-l+1;
	    long long smid=sorted[mid];
		for (long long i=l;i<=r;i++)
	    if (tree[dep][i]<smid) --same;
	    long long lpos=l,rpos=mid+1;
		for (long long i=l;i<=r;i++)
		{
	        if (tree[dep][i] < smid) tree[dep + 1][lpos++] = tree[dep][i];
			else if (tree[dep][i]==smid && same>0) 
			{
	            --same;
	            tree[dep+1][lpos++]=tree[dep][i];
	        } 
			else tree[dep+1][rpos++]=tree[dep][i];
	        toLeft[dep][i]=toLeft[dep][l-1]+lpos-l;
	    }
	    build(l,mid,dep+1);
	    build(mid+1,r,dep+1);
	}
	
	long long get_kth_small(long long L,long long R,long long l,long long r,long long dep,long long k) 
	{
	    if (l==r) return tree[dep][l];
	    long long mid=(L+R)>>1;
	    long long cnt=toLeft[dep][r]-toLeft[dep][l-1];
	    if (cnt>=k) 
		{
	        long long newl=L+toLeft[dep][l-1]-toLeft[dep][L-1];
	        long long newr=newl+cnt-1;
	        return get_kth_small(L,mid,newl,newr,dep+1,k);
	    } 
		else 
		{
	        long long newr=r+toLeft[dep][R]-toLeft[dep][r];
	        long long newl=newr-(r-l-cnt);
	        return get_kth_small(mid+1,R,newl,newr,dep+1,k-cnt);
	    }
	}
};
int main() 
{
	long long N,Q;
	while (~scanf("%lld%lld",&N,&Q))
	{
		divided_tree::init();
	    for (int i=1;i<=N;i++) 
		{
	        scanf("%lld",&divided_tree::tree[0][i]);
	        divided_tree::sorted[i]=divided_tree::tree[0][i];
	    }
	    sort(divided_tree::sorted+1,divided_tree::sorted+N+1);
	    divided_tree::build(1,N,0);
	    while (Q--)
		{
	        long long s,t;
			scanf("%lld%lld",&s,&t);
	        if (t-s+1<3) {puts("-1");continue;}
	        long long ans=-1;
	        long long l=t-s+1;
	        long long cnt=0;
	        long long l1=divided_tree::get_kth_small(1,N,s,t,0,l),l2=divided_tree::get_kth_small(1,N,s,t,0,l-1);
	        for (long long k=l-2;k>=1 && cnt<=50;k--,cnt++)
			{
				 long long l3=divided_tree::get_kth_small(1,N,s,t,0,k);
				 if (l1<l2+l3)
				 {
				 	ans=l1+l2+l3;
				 	break;
				 }
				 else {l1=l2;l2=l3;}
			}
	        printf("%lld\n",ans);
	    }
	}
    return 0;
}
