#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    int n;
    while (cin>>n)
    {
        if (!n) return 0;
        static int a[305];
        for (int i=1;i<=n;i++)
            cin>>a[i],a[i+n]=a[i];
        n<<=1;
        static int pregcd[305][305],f[305][305];
        for (int i=1;i<=n;i++)
            for (int j=1;j<=n;j++) pregcd[i][j]=__gcd(a[i],a[j]);
        int ans=0x3f3f3f3f;memset(f,0x3f,sizeof(f));
        for (int i=1;i<=n;i++) f[i][i+1]=0;
        for (int len=1;len<=n>>1;len++)
            for (int i=1;i+len+1<=n;i++)
            {
                int pos=i+len+1;
                for (int md=i+1;md<pos;md++)
                f[i][pos]=min(f[i][md]+f[md][pos]+pregcd[i][md]+pregcd[md][pos],f[i][pos]);
            }
        for (int i=1;i<=n>>1;i++)
        {
            int pos=i+(n>>1);
            for (int j=i;j<=pos;j++)
                ans=min(f[i][j]+f[j][pos]+pregcd[i][j]+pregcd[j][pos]+pregcd[j][pos],ans);
        }
        for (int i=1;i<=n>>1;i++) ans-=pregcd[i][i+1];
        cout<<ans<<endl;
    }
}