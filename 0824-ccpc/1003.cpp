#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using std::min;
using std::swap;
using std::vector;
using std::sort;
using std::merge;
using std::lower_bound;
char s[100050]; //1..n
int n,m;
int sa[100050],rank[100050],height[100050],c[100050];
int x[100050],y[100050];
int st[22][100050];
inline void getsa()
{
    m=128;
    memset(c,0,sizeof(c));
    for(int i=1;i<=n;i++) ++c[x[i]=s[i]];
    for(int i=2;i<=m;i++) c[i]+=c[i-1];
    for(int i=n;i>=1;i--) sa[c[x[i]]--]=i;
    for(int k=1;k<=n;k<<=1)
    {
        int num=0;
        for(int i=n-k+1;i<=n;i++) y[++num]=i;
        for(int i=1;i<=n;i++)
            if(sa[i]>k) y[++num]=sa[i]-k;
        for(int i=1;i<=m;i++) c[i]=0;
        for(int i=1;i<=n;i++) ++c[x[i]];
        for(int i=2;i<=m;i++) c[i]+=c[i-1];
        for(int i=n;i>=1;i--) sa[c[x[y[i]]]--]=y[i],y[i]=0;
        swap(x,y);
        x[sa[1]]=1;
        num=1;
        for(int i=2;i<=n;i++)
            x[sa[i]]=(y[sa[i]]==y[sa[i-1]] && y[sa[i]+k]==y[sa[i-1]+k]) ? num : ++num;
        if(num==n) break;
        m=num;
    }
}
inline void getheight()
{
    int k=0;
    for(int i=1;i<=n;i++) rank[sa[i]]=i;
    for(int i=1;i<=n;i++)
    {
        if(rank[i]==1) continue;
        if(k) --k;
        int j=sa[rank[i]-1];
        while(j+k<=n && i+k<=n && s[i+k]==s[j+k]) ++k;
        height[rank[i]]=k;
    }
}
void getst()
{
    for (int i=1;i<=n;i++) st[0][i]=height[i];
    for (int k=1;k<=20;k++)
        for (int i=1;i+(1<<k)-1<=n;i++)
            st[k][i]=min(st[k-1][i],st[k-1][i+(1<<k-1)]);
}
int lcp(int x,int y)
{
    int l=rank[x],r=rank[y];
    if (l>r) swap(l,r);
    if (l==r) return n-x+1;
    int t=int(log2(r-l));
    return min(st[t][l+1],st[t][r-(1<<t)+1]);
}
struct segtree
{
    int l,r,size;
    int lchild,rchild;
};
segtree trees[3000050];
int root[100050];
int ndcnt=0;
void build(int root,int l,int r)
{
    int mid=(l+r)>>1;
    trees[root].l=l,trees[root].r=r,trees[root].size=0;
    if (l==r) return;
    build(trees[root].lchild=++ndcnt,l,(l+r)>>1);
    build(trees[root].rchild=++ndcnt,1+(l+r)>>1,r);
}
int find(int left,int right,int k)
{
    if (trees[left].l==trees[left].r) return trees[left].l;
    int sz=trees[trees[right].lchild].size-trees[trees[left].lchild].size;
    if (k<=sz) return find(trees[left].lchild,trees[right].lchild,k);
    return find(trees[left].rchild,trees[right].rchild,k-sz);
}
void ins(int left,int late,int pos)
{
    int mid=(trees[left].l+trees[left].r)>>1;
    trees[late]=trees[left];trees[late].size++;
    if (trees[left].l==trees[left].r) return;
    if (pos<=mid) ins(trees[left].lchild,trees[late].lchild=++ndcnt,pos);
    if (pos>mid) ins(trees[left].rchild,trees[late].rchild=++ndcnt,pos);
}
int main()
{
    int t;
    scanf("%d",&t);
    while (t--)
    {
        int q;
        scanf("%d%d",&n,&q);
        scanf("%s",s+1);
        getsa();
        getheight();
        getst();
        //for (int i=1;i<=n;i++) printf("%d:%s\n",sa[i],s+sa[i]);puts("");
        //for (int i=1;i<=n;i++) printf("%d:%s\n",rank[i],s+i);puts("");
        //for (int i=1;i<=n;i++) printf("%d:%d\n",i,height[i]);
        int N=n;
        ndcnt=0;
        build(root[0]=++ndcnt,1,N);
        for (int i=1;i<=N;i++)
            ins(root[i-1],root[i]=++ndcnt,sa[i]);
        while (q--)
        {
            int l,r,k;
            scanf("%d%d%d",&l,&r,&k);
            int ll,rr;
            int len=r-l+1;
            int left=1,right=rank[l],ans=rank[l];
            while (left<=right)
            {
                int mid=(left+right)>>1;
                if (lcp(l,sa[mid])>=len)
                {
                    right=mid-1;
                    ans=mid;
                }
                else left=mid+1;
            }
            ll=ans;
            ans=rank[l];
            left=rank[l],right=n;
            while (left<=right)
            {
                int mid=(left+right)>>1;
                if (lcp(l,sa[mid])>=len)
                {
                    left=mid+1;
                    ans=mid;
                }
                else right=mid-1;
            }
            rr=ans;
            if (rr-ll+1<k) puts("-1");
            else printf("%d\n",find(root[ll-1],root[rr],k));
        }
    }
}