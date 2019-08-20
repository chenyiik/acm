#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<unsigned> vc[50050];
struct linebase
{
    static const int mxbit=32;
    unsigned val[2*mxbit+10];
    void init() {for (int i=0;i<2*mxbit;i++) val[i]=0;}
    void add(unsigned x)
    {
        for (int i=0;i<mxbit;i++)
            if ((1&(x>>i)))
            {
                if (!val[i]) {val[i]=x;break;}
                x^=val[i];
            }
    }
    bool query(unsigned x)
    {
        for (int i=0;i<mxbit;i++)
            if (val[i] && (1&(x>>i))) x^=val[i];
        return !x;
    }
    linebase operator*(linebase b)
    {
        linebase res,tmp;
        tmp.init();res.init();
        for (int i=0;i<mxbit;i++)
        if (val[i])
        {
            unsigned x=val[i],y=val[i];
            for (int j=0;j<mxbit;j++)
            if (1&(x>>j))
            {
                if (b.val[j]) x^=b.val[j],y^=tmp.val[j];
                else {b.val[j]=x,tmp.val[j]=y;break;}
            }
            if (!x) res.add(y);
        }
        return res;
    }
};
namespace segtree
{
    struct node
    {
        unsigned l,r;
        linebase val;
    };
    node tree[200050];
    unsigned root=1;
    void build(int root,int l,int r)
    {
        tree[root].val.init();
        tree[root].l=l;tree[root].r=r;
        if (l==r)
        {
            for (int i=0;i<vc[l].size();i++) tree[root].val.add(vc[l][i]);
            return;
        }
        int mid=(l+r)>>1;
        build(root<<1,l,mid);build(root<<1|1,mid+1,r);
        tree[root].val=tree[root<<1].val*tree[root<<1|1].val;
    }
    bool query(unsigned root,unsigned l,unsigned r,unsigned L,unsigned R,unsigned x)
    {
        if (L<=l && R>=r) return tree[root].val.query(x);
        unsigned mid=(l+r)>>1;
        bool ret=true;
        if (L<=mid) ret=ret && query(root<<1,l,mid,L,R,x);
        if (R>=mid+1) ret=ret && query(root<<1|1,mid+1,r,L,R,x);
        return ret;
    }
}
int main()
{
    freopen("in.txt","r",stdin);
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m;
    for (int i=1;i<=n;i++)
    {
        unsigned n1;
        cin>>n1;
        for (unsigned j=1;j<=n1;j++) {unsigned tmp;cin>>tmp;vc[i].emplace_back(tmp);}
    }
    segtree::build(1,1,n);
    while (m--)
    {
        unsigned l,r;unsigned x;
        cin>>l>>r>>x;
        if (segtree::query(1,1,n,l,r,x)) puts("YES");else puts("NO");
    }
}