#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>T;
    while (T--)
    {
        int n,k;
        cin>>n>>k;
        static int a[int(1e4+50)];
        int sum=0;
        for (int i=1;i<=n;i++) cin>>a[i],sum+=a[i];
        sort(a+1,a+n+1);
        int sk=k;
        int minpos=0,stp=0;
        for (int i=1;i<=n;i++) if (a[i]>0) {minpos=a[i];stp=i;break;}
        int maxneg=-0x3f3f3f3f,stn=0;
        if (stp>1) maxneg=a[stp-1],stn=stp-1;
        for (int i=1;i<=n;i++)
        {
            if (sk<=0) break;
            if (a[i]<=0) {sum+=2*(-a[i]);sk--;a[i]=-a[i];}
        }
        sort(a+1,a+n+1);
        if (sk>0)
        {
            if (sk&1)
            {
                sum-=2*a[1];
            }
        }
        cout<<sum<<endl;
    }
}