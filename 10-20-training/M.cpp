#include<bits/stdc++.h>
using namespace std;
long long a[100050],t,n,c;
long long mineaten(long long day)
{
    long long per=day*t;
    long long cnt=1,now=0;
    for (long long i=1;i<=n;i++)
    {
        if (a[i]>per) {cnt=0x3f3f3f3f;break;}
        now+=a[i];
        if (now>per)
        {
            cnt++;
            now=a[i];
        }
    }
    return cnt;
}
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n>>c>>t;
    long long sum=0;
    for (long long i=1;i<=n;i++) cin>>a[i],sum+=a[i];
    long long left=1,right=sum;
    long long ans=0x3f3f3f3f;
    while (left<=right)
    {
        long long mid=(left+right)>>1;
        long long p=mineaten(mid);
        if (p>c) {left=mid+1;}
        else {ans=min(ans,mid);right=mid-1;}
    }
    cout<<ans<<endl;
}