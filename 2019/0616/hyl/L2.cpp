#include<bits/stdc++.h>
using namespace std;
int a[1050][1050];
int n,m,h,w,l,r;
bool check(int x)
{
    static int v[1050][1050];
    memset(v,0,sizeof(v));
    for (int i=1;i<=n;i++)
    for (int j=1;j<=m;j++)
        v[i][j]=(a[i][j]<=x);
    for (int i=1;i<=n;i++)
    for (int j=1;j<=m;j++)
        v[i][j]=v[i][j]+v[i-1][j]+v[i][j-1]-v[i-1][j-1];
    for (int i=1;i<=n-h+1;i++)
    for (int j=1;j<=m-w+1;j++)
    {
        int cnt=v[i+h-1][j+w-1]-v[i-1][j+w-1]-v[i+h-1][j-1]+v[i-1][j-1];
        if (cnt>h*w/2) return true;
    }
    return false;
}
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m>>h>>w;
    for (int i=1;i<=n;i++)
    for (int j=1;j<=m;j++) cin>>a[i][j];
    l=1,r=n*m;
    int minx=0x3f3f3f3f;
    while (l<=r)
    {
        int mid=(l+r)/2;
        if (check(mid))
        {
            r=mid-1;minx=min(minx,mid);
        }
        else l=mid+1;
    }
    cout<<minx<<endl;
}