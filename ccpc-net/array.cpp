#include<bits/stdc++.h>
using namespace std;
const int maxn=100010;
const int m=maxn*100;
int n,q,tot;
int a[maxn];
int t[maxn],lson[m],rson[m],c[m];
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
    int l=1,r=n;
    while (l<r)
    {
        int mid=(l+r)>>1;
        if (pos<=mid)
        {
            lson[newroot]=tot++;
            rson[newroot]=rson[root];
            newroot=lson[newroot];root=lson[root];
            r=mid;
        }
        else{
            rson[newroot]=tot++;lson[newroot]=lson[root];
            newroot=rson[newroot];root=rson[root];
            l=mid+1;
        }
        c[newroot]=c[root]+val;
    }
    return tmp;
}
int query(int root,int pos)
{
    return 0;
}
int main()
{
    return 0;
}