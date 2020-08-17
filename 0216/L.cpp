#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        for (int i=1;i<=n;i++)
        {
            int ans=0,x;
            cin>>x;
            while (x)
            {
                ans+=x&1;
                x>>=1;
            }
            cout<<ans<<" \n"[i==n];
        }
    }
}