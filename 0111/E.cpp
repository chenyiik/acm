#include<bits/stdc++.h>
using namespace std;
struct good
{
    long long t,w;
    bool operator<(const good& b) const
    {
        if (t<b.t) return true;
        if (t==b.t) return w<b.w;
        return false;
    }
};
int main()
{
    long long n,m;
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m;
    static long long a[1000050];
    static good t[1000050];
    for (long long i=1;i<=n;i++) cin>>t[i].t>>t[i].w;
    sort(t+1,t+n+1);
    for (long long i=1;i<=m;i++) cin>>a[i];
    static long long now[1000050];
    memset(now,0,sizeof(now));
    long long p=1;
    long long of=0,ans=0;
    for (long long i=1;i<=n;i++)
    {
        while (t[p].t==i && p<=n)
        {
            now[t[p].w]++;
            if (now[t[p].w]>a[t[p].w]) ++of;
            ++p;
        }
        ans+=(of>i)?of-i:0;
    }
    cout<<ans<<endl;
}