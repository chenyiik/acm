#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    int T;
    cin>>T;
    for (int cas=1;cas<=T;cas++)
    {
        cout<<"Case #"<<cas<<": ";
        int n;
        cin>>n;
        if (n%4>=2) {cout<<"No"<<endl;continue;}
        int nn=(n>>1)<<1;
        cout<<"Yes"<<endl;
        static int a[2050][2050];
        memset(a,0,sizeof(a));
        for (int i=0;i<nn/2;++++i)
        {
            int lim=nn-(i/2)*2-2;
            a[i][i+1]=a[i+1][i]=1;
            for (int j=i+2;j<lim;j++)
            {
                a[i][j]=a[j][i]=1;
                a[i+1][j]=a[j][i+1]=1;
            }
            a[i][nn-i-1]=a[nn-i-1][i]=1;
            a[i+1][nn-i-2]=a[nn-i-2][i+1]=1;
        }
        if (n&1)
        {
            for (int i=0;i<n/2;i++) a[i][n-1]=a[n-1][i]=1;
            a[n-1][n-1]=0;
        }
        for (int i=0;i<n;i++)
        {
            for (int j=0;j<n;j++) cout<<a[i][j];
            cout<<endl;
        }
        for (int i=0;i<n;i++)
        {
            int ans=-1;
            if (i<nn)
            {
                ans=nn-i-1;
                if (i<(nn>>1)) ans^=1;
            }
            else ans=i;
            if (i<n-1) cout<<++ans<<" ";else cout<<++ans<<endl;
        }
    }
    return 0;
}