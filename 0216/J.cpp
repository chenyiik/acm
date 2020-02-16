#include<bits/stdc++.h>
#define add(l,r) c[(l)]++,c[(r+1)]--
using namespace std;
int nxt(int a,int x,int n)
{
    a=a+x;
    if (a>n) a-=n;
    if (a<=0) a+=n;
    return a;
}
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    int t;
    cin>>t;
    while (t--)
    {
        static int c[200050],a[200050];
        int n,m;
        cin>>n>>m;
        for (int i=1;i<=m;i++) cin>>a[i];
        memset(c,0,sizeof(c));
        for (int i=1;i<=m;i++)
        {
            int x;
            cin>>x;
            if (x==0) {add(a[i],a[i]);continue;}
            if (abs(x)==n) {add(1,n);add(a[i],a[i]);continue;}
            if (abs(x)==n-1) {add(1,n);continue;}
            int d=nxt(a[i],x,n);
            if (x>0)
            {
                if (d>=a[i]) add(a[i],d);
                else {add(a[i],n);add(1,d);}
            } else
            {
                if (d<=a[i]) add(d,a[i]);
                else {add(1,a[i]);add(d,n);}
            }
        }
        for (int i=1;i<=n+1;i++) c[i]+=c[i-1];
        //for (int i=1;i<=n;i++) cout<<i<<":"<<c[i]<<endl;
        int maxv=0,wh=0;
        for (int i=1;i<=n;i++)
            if (c[i]>maxv)
            {
                maxv=c[i];
                wh=i;
            }
        cout<<wh<<" "<<maxv<<endl;
    }
}