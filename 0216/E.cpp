#include<bits/stdc++.h>
using namespace std;
using dtype=unsigned long long;
const dtype base=131ULL;
struct node
{
    int l,r;
    dtype leftv,rightv;
    node(int _l=0,int _r=0,dtype _leftv=0,dtype _rightv=0):l(_l),r(_r),leftv(_leftv),rightv(_rightv){}
    int len(){return r-l+1;}
    int mid(){return (l+r)>>1;}
};
node tree[100050<<2];
dtype b[100050];
void calcb()
{
    b[0]=1;
    for (int i=1;i<=100000;i++) b[i]=b[i-1]*base;
}
char s[100055];
void build(int l,int r,int k)
{
    tree[k].l=l,tree[k].r=r;
    if (l==r)
    {
        tree[k].rightv=tree[k].leftv=(dtype)(s[l]);
        return;
    }
    int mid=tree[k].mid();
    build(l,mid,k<<1);
    build(mid+1,r,k<<1|1);
    tree[k].leftv=tree[k<<1].leftv+tree[k<<1|1].leftv*b[tree[k<<1].len()];
    tree[k].rightv=tree[k<<1].rightv*b[tree[k<<1|1].len()]+tree[k<<1|1].rightv;
}
void update(int x,int k)
{
    if (tree[k].len()==1 && tree[k].l==x)
    {
        tree[k].rightv=tree[k].leftv=(dtype)(s[x]);
        return;
    }
    int mid=tree[k].mid();
    if (x<=mid) update(x,k<<1);
    else update(x,k<<1|1);
    tree[k].leftv=tree[k<<1].leftv+tree[k<<1|1].leftv*b[tree[k<<1].len()];
    tree[k].rightv=tree[k<<1].rightv*b[tree[k<<1|1].len()]+tree[k<<1|1].rightv;
}
dtype queryleftv(int l,int r,int k,int &len)
{
    if (l<=tree[k].l && tree[k].r<=r)
    {
        dtype res=tree[k].leftv*b[len];
        len+=tree[k].len();
        return res;
    }
    int mid=tree[k].mid();
    dtype res=0;
    if (l<=mid) res+=queryleftv(l,r,k<<1,len);
    if (mid<r) res+=queryleftv(l,r,k<<1|1,len);
    return res;
}
dtype queryrightv(int l,int r,int k,int &len)
{
    if (l<=tree[k].l && tree[k].r<=r)
    {
        dtype res=tree[k].rightv*b[len];
        len+=tree[k].len();
        return res;
    }
    int mid=tree[k].mid();
    dtype res=0;
    if (mid<r) res+=queryrightv(l,r,k<<1|1,len);
    if (l<=mid) res+=queryrightv(l,r,k<<1,len);
    return res;
}
int main()
{
    int t;
    scanf("%d",&t);
    calcb();
    while (t--)
    {
        int n,q;
        scanf("%d%d",&n,&q);
        scanf("%s",s+1);
        build(1,n,1);
        while (q--)
        {
            int op;
            cin>>op;
            if (op==1)
            {
                int st;char ch;
                scanf("%d %c",&st,&ch);
                s[st]=ch;
                update(st,1);
            } else
            {
                int l,r;
                scanf("%d%d",&l,&r);
                int len=0;
                dtype lv=queryleftv(l,r,1,len);
                len=0;
                dtype rv=queryrightv(l,r,1,len);
                if (lv==rv)
                {
                    puts("Adnan Wins");
                }
                else puts("ARCNCD!");
            }
        }
    }
}