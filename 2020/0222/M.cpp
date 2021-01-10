#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    int n,x;
    cin>>n>>x;
    static int a[1050];
    for (int i=1;i<=n;i++) cin>>a[i];
    int l=1,ans=1;
    while (l<n)
    {
        int now=1;
        while (l+1<=n && a[l+1]-a[l]<=x) now++,l++;
        ans=max(ans,now);
        l++;
    }
    cout<<ans<<endl;
}