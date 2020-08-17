#include<bits/stdc++.h>
using namespace std;
namespace segtree
{
    using LL=long long;
    using datatype=LL;
    struct Node
    {
        int l,r;
        LL sum;
        LL leftsum,rightsum,rangesum;
    }segTree[2050*4];

    inline int leftchild(int root)
    { return root<<1; }

    inline int rightchild(int root)
    { return root<<1|1; }

    void clear()
    {
        memset(segTree,0,sizeof(segTree));
    }

    void build(int root,int l,int r)
    {
        segTree[root].l=l;
        segTree[root].r=r;
        segTree[root].leftsum=segTree[root].rightsum=segTree[root].rangesum=segTree[root].sum=0;
        if(l==r) return;
        int mid=(l+r)>>1;
        build(leftchild(root),l,mid);
        build(rightchild(root),mid+1,r);
    }

    void push_up(int root)
    {
        segTree[root].sum=segTree[leftchild(root)].sum+segTree[rightchild(root)].sum;
        segTree[root].leftsum=max(segTree[leftchild(root)].leftsum,segTree[rightchild(root)].leftsum+segTree[leftchild(root)].sum);
        segTree[root].rightsum=max(segTree[rightchild(root)].rightsum,segTree[leftchild(root)].rightsum+segTree[rightchild(root)].sum);
        segTree[root].rangesum=max(segTree[leftchild(root)].rightsum+segTree[rightchild(root)].leftsum,max(segTree[leftchild(root)].rangesum,segTree[rightchild(root)].rangesum));
    }
    void add(int root,int pos,LL v)
    {
        if (segTree[root].l==segTree[root].r)
        {
            segTree[root].sum+=v;
            segTree[root].leftsum+=v;
            segTree[root].rightsum+=v;
            segTree[root].rangesum+=v;
            return;
        }
        int mid=(segTree[root].l+segTree[root].r)/2;
        if (pos<=mid) add(leftchild(root),pos,v);
        else add(rightchild(root),pos,v);
        push_up(root);
    }
}
struct box
{
    int x,y,val;
    bool operator <(const box& b) const
    {
        return x<b.x;
    }
};
box a[2050];
int b[2050];
using LL=segtree::datatype;
int main()
{
    int _;
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>_;
    while (_--)
    {
        int n;
        cin>>n;
        for (int i=1;i<=n;i++) {cin>>a[i].x>>a[i].y>>a[i].val;b[i]=a[i].y;}
        sort(b+1,b+n+1);
        int cnt=unique(b+1,b+n+1)-b-1;
        sort(a+1,a+n+1);
        for (int i=1;i<=n;i++)
            a[i].y=lower_bound(b+1,b+cnt+1,a[i].y)-b;
        LL ans=0;
        int k=0;
        for (int i=1;i<=n;i++)
        {
            if (i==1||a[i].x!=a[i-1].x)
            {
                segtree::build(1,1,cnt);
                for (int j=i;j<=n;j=k)
                {
                    for (k=j;k<=n && a[j].x==a[k].x;k++)
                        segtree::add(1,a[k].y,a[k].val);
                    ans=max(ans,segtree::segTree[1].rangesum);
                }
            }
        }
        cout<<ans<<endl;
    }
}