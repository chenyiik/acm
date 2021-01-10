#include<bits/stdc++.h>
using namespace std;
int a[300050],b[300050];
int f1[300050][20],f2[300050][20];
void pre1(int n)
{
    for (int i=1;i<=n;i++) f1[i][0]=a[i];
    for (int j=1;(1<<j)<=n;j++)
        for(int i=1;i+(1<<j)-1<=n;i++)
            f1[i][j]=max(f1[i][j-1],f1[i+(1<<j-1)][j-1]);
}
void pre2(int n)
{
    for (int i=1;i<=n;i++) f2[i][0]=b[i];
    for (int j=1;(1<<j)<=n;j++)
        for(int i=1;i+(1<<j)-1<=n;i++)
            f2[i][j]=min(f2[i][j-1],f2[i+(1<<j-1)][j-1]);
}
int rmq1(int l,int r)
{
    int k=int(log2(r-l+1));
    return max(f1[l][k],f1[r-(1<<k)+1][k]);
}
int rmq2(int l,int r)
{
    int k=int(log2(r-l+1));
    return min(f2[l][k],f2[r-(1<<k)+1][k]);
}
bool chk(int n,int x)
{
    for (int i=1;i<=n;i++)
        if (i-x>=0)
        {
            int x1=rmq1(i-x+1,i),x2=rmq2(i-x+1,i);
            if (x2-x1+1>=x) return true;
        }
    return false;
}
int main()
{
    int n;
    while (cin>>n)
    {
        for (int i=1;i<=n;i++) cin>>a[i]>>b[i];
        pre1(n),pre2(n);
        int l=1,r=n+1;
        while (l<r)
        {
            int mid=(l+r)>>1;
            if (chk(n,mid)) l=mid+1;else r=mid;
        }
        cout<<l-1<<endl;
    }
}