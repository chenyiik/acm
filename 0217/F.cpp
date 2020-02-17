#include<bits/stdc++.h>
using namespace std;
int n,l,r;
int a[100050];
bool check(int x)
{
    static int cnt[100050];
    memset(cnt,0,sizeof(cnt));
    auto update=[](int l,int r)
    {
        if (l>r) return;
        cnt[l]++;
        cnt[r+1]--;
    };
    static queue<int> q;
    while (!q.empty()) q.pop();
    update(1,1);
    for (int i=1;i<=n;i++) if (a[i]>=x) q.push(i);
    for (int i=1;i<=n;i++)
    {
        cnt[i]+=cnt[i-1];
        while (!q.empty() && i>q.front()) q.pop();
        bool x=cnt[i];
        if (q.empty()||!x) continue;
        int lim=q.front();
        int en=i+r-1;
        if (en<lim) continue;
        int st=max(lim,i+l-1);
        en=min(n+1,en+1);
        update(st+1,en);
    }
    cnt[n+1]+=cnt[n];
    return cnt[n+1]>0;
}
int main()
{
    cin>>n>>l>>r;
    int il=0;
    for (int i=1;i<=n;i++) cin>>a[i],il=max(il,a[i]);
    int ll=0,rr=il;
    int ans=0;
    while (ll<=rr)
    {
        int mid=(ll+rr)>>1;
        if (check(mid))
        {
            ans=mid;
            ll=mid+1;
        }
        else rr=mid-1;
    }
    cout<<ans<<endl;
}