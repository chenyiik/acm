#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n;
    cin>>n;
    static long long a[5050][5050];
    long long m=(n*(n-1))>>1;
    for (long long i=1;i<=m;i++)
    {
        long long u,v,w;
        cin>>u>>v>>w;
        a[u][v]=a[v][u]=w;
    }
    for (long long i=1;i<=n;i++) a[i][i]=0,sort(a[i]+1,a[i]+n+1);
    long long ans=0;
    for (long long i=1;i<=n;i++)
    {
        for (long long j=2;j<=n;j+=2) ans+=max(a[i][j],a[i][j+1]);
    }
    cout<<ans<<endl;
}