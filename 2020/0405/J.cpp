#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    int n;
    cin>>n;
    static string s[25][50050];
    static int cnt[25];
    for (int i=1;i<=n;i++)
    {
        string str;cin>>str;
        cnt[i]=1;
        for (int j=1;j<(1<<str.size());j++,cnt[i]++)
            for (int k=0;k<str.size();k++)
                if (j>>k & 1)
                    s[i][cnt[i]].push_back(str[k]);
        --cnt[i];
        sort(s[i]+1,s[i]+cnt[i]+1);
    }
    static int f[25][50050];
    for (int i=1;i<=cnt[1];i++)
    {
        f[1][i]=s[1][i].size();
        if (i>1) f[1][i]=max(f[1][i],f[1][i-1]);
    }
    for (int i=2;i<=n;i++)
        for (int j=1;j<=cnt[i];j++)
        {
            f[i][j]=-0x3f3f3f3f;
            if (j>1) f[i][j]=max(f[i][j],f[i][j-1]);
            if (s[i][j]<=s[i-1][1]) continue;
            int t=lower_bound(s[i-1]+1,s[i-1]+cnt[i-1]+1,s[i][j])-s[i-1]-1;
            if (t>=1)
                f[i][j]=max(f[i][j],int(f[i-1][t]+s[i][j].size()));
        }
    int ans=f[n][cnt[n]];
    if (ans<0) ans=-1;
    cout<<ans<<endl;
}