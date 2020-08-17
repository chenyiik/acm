#include<bits/stdc++.h>
using namespace std;
int main()
{
    static long long a[int(3e6)+50],b[int(3e6)+50];
    long long n;
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    cin>>b[1];
    long long sum=b[1],minn=a[1];
    long long ans=sum*minn;
    for (int i=2;i<=n;i++)
    {
        cin>>b[i];
        ans=max(ans,a[i]*b[i]);
        if (sum<0) sum=b[i],minn=a[i];
        else
        {
            sum+=b[i];
            minn=min(a[i],minn);
            ans=max(ans,sum*minn);
        }
    }
    for (int i=2;i<=n;i++)
    {
        if (sum>0) sum=b[i],minn=a[i];
        else
        {
            sum+=b[i];
            minn=min(a[i],minn);
            ans=max(ans,sum*minn);
        }
    }
    cout<<ans<<endl;
}