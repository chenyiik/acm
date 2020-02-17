#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    static int a[50050];
    for (int i=1;i<=n;i++) cin>>a[i],a[i]+=a[i-1];
    for (int i=1;i<=n;i++)
    {
        int ans=0;
        for (int j=i,step=3;j<=n;j+=step,step+=3)
        {
            int p=min(j+step-1,n);
            ans+=max(0,a[p]-a[j-1]);
        }
        cout<<ans<<endl;
    }
}