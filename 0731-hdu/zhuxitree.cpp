#include<bits/stdc++.h>
using namespace std;
const int maxn=int(1e6+10);
const int M=maxn*30;
int n,q,m,tot,a[maxn],t[maxn],T[maxn],lson[M],rson[M],c[M];
void init_hash()
{
    for (int i=1;i<=n;i++) t[i]=a[i];
    sort(t+1,t+n+1);
    m=unique(t+1,t+n+1)-t-1;
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
int hasht(int x) {
    return lower_bound(t + 1, t + m + 1, x) - t;
}
int update(int root,int pos,int val)
{
    int newroot=tot++,tmp=newroot;
    c[newroot]=c[root]+val;
    int l=1,r=m;
    while (l<r)
    {
        int mid(l+r)>>1;
        if (pos<=mid)
        {
            lson[newroot]=tot++;rson[newroot]=rson[root];
            newroot=lson[newroot];root=lson[root];
            r=mid;
        } else{
            rson[newroot]=tot++;lson[newroot]=lson[root];
            newroot=rson[newroot];root=lson[root];
            l=mid+1;
        }
        c[newroot]=c[root]+val;
    }
    return tmp;
}
int query(int left_root,int right_root,int k)
{
    int l=1,r=m;
    while (l<r)
    {
        int mid=(l+r)>>1;
        if (c[lson[left_root]]-c[lson[right_root]]>=k)
        {
            r=mid;
            left_root=lson[left_root];
            right_root=lson[right_root];
        } else
        {
            l=mid+1;
            k-=c[lson[left_root]]-c[lson[right_root]];
            left_root=rson[left_root];
            right_root=rson[right_root];
        }
    }
    return l;
}
int main()
{
    cin>>n>>q;
    tot=0;
    for (int i=1;i<=n;i++) cin>>a[i];
    init_hash();
    t[n+1]=build(1,m);
    for (int i=n;i;i--)
    {
        int pos=hasht(a[i]);
        t[i]=update(t[i+1],pos,1);
    }
    printf("%d\n",t[query(t[1],t[5],2)]);
}