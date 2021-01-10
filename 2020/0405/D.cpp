#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    int r,c;
    cin>>r>>c;
    char s[505][505];
    for (int i=1;i<=r;i++)
        cin>>s[i]+1;
    int ans=0;
    if (r==1)
    {
        for(int i=2;i<=c-1;i++) ans+=(s[1][i]=='.');
        cout<<ans<<endl;
        return 0;
    }
    if (r==2)
    {
        for(int i=2;i<=c-1;i++) ans+=(s[1][i]=='.' && s[2][i]=='.');
        cout<<ans<<endl;
        return 0;
    }
    if (c==1)
    {
        for(int i=2;i<=r-1;i++) ans+=(s[i][1]=='.');
        cout<<ans<<endl;
        return 0;
    }
    if (c==2)
    {
        for(int i=2;i<=r-1;i++) ans+=(s[i][1]=='.' && s[i][2]=='.');
        cout<<ans<<endl;
        return 0;
    }
    for (int i=2;i<=r-1;i++)
        for (int j=2;j<=c-1;j++)
            ans+=(s[i][j]=='.');
    int diff=0;
    for (int i=2;i<=c-1;i++) diff|=(s[1][i]=='#'||s[r][i]=='#');
    for (int i=2;i<=r-1;i++) diff|=(s[i][1]=='#'||s[i][c]=='#');
    cout<<ans+(!diff)<<endl;
}