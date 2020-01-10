#include<bits/stdc++.h>
using namespace std;
map<int,int> cnt1,cnt2;
int main()
{
    int T;
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>T;
    while (T--)
    {
        int n,m;
        cin>>n>>m;
        static int a[int(1e3)+50][int(1e3)+50];
        for (int i=1;i<=n;i++)
            for (int j=1;j<=m;j++) cin>>a[i][j];
        int ans=0;
        for (int i=1;i<=n-1;i++)
        {
            cnt1.clear();cnt2.clear();
            for (int j=1;j<=m;j++)
            {
                cnt1[a[i][j]]++;
                cnt2[a[i+1][j]]++;
            }
            for (int j=1;j<=m;j++)
            {
                if (cnt2[a[i][j]]>0)
                {
                    ans+=min(cnt1[a[i][j]],cnt2[a[i][j]]);
                    cnt2[a[i][j]]=0;
                }
            }
        }
        cout<<ans<<endl;
    }
}