#include <bits/stdc++.h>
using namespace std;
struct BIT
{
    long long a[400050];
    int lowbit(int x)
    {
        return x&(-x);
    }
    void add(int x,int d)
    {
        for (;x<=400050;x+=lowbit(x)) a[x]+=d;
    }
    long long sumt(int x)
    {
        long long ans=0;
        for (;x>0;x-=lowbit(x)) ans+=a[x];
        return ans;
    }
    long long sum(int l,int r)
    {
        if (l>0) return sumt(r)-sumt(l-1);
        return sumt(r);
    }
};
BIT b,c;
int a[100050],h[100050];
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    int T;
    cin>>T;
    while (T--)
    {
        int n,m;
        cin>>n>>m;
        for (int i=1;i<=n;i++) cin>>a[i];
        h[1]=a[1];
        b.add(1,a[1]);c.add(1,a[1]);
        for (int i=2;i<=n;i++)
        {
            h[i]=a[i]-a[i-1];
            b.add(i,h[i]);
            if (h[i]>0) c.add(i,h[i]);
        }
        for (int i=1;i<=m;i++)
        {
            int op;
            cin>>op;
            if (op==2) {int l,r;cin>>l>>r;cout<<b.sum(1,l)+c.sum(l+1,r)<<endl;continue;}
            int l,r,d;
            cin>>l>>r>>d;
            b.add(l,d);b.add(r+1,-d);
            if (h[l]>0) c.add(l,d);
            else if (h[l]+d>0) c.add(l,h[l]+d);
            if (h[r+1]>d) c.add(r+1,-d);
            else if (h[r+1]>0) c.add(r+1,-h[r+1]);
            h[l]+=d;h[r+1]-=d;
        }
        memset(b.a,0,sizeof(b.a));memset(c.a,0,sizeof(c.a));
    }
}