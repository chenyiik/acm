#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,k;
    while (cin>>n>>k)
    {
        bool clo[1000050];
        memset(clo,0,sizeof(clo));
        int now=0;
        int ans=0;
        while (k--)
        {
            int x;
            cin>>x;
            for (int i=1;i*x<=n;i++)
            {
                clo[i*x]=!clo[i*x];
                now+=(clo[i*x])?1:-1;
            }
            ans=max(ans,now);
        }
        cout<<ans<<endl;
    }
}