#include<bits/stdc++.h>
using namespace std;
int a[1050][1050];
vector<int> tmp;
int main()
{
    int n,m,h,w;
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m>>h>>w;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++) cin>>a[i][j];
    int ans=0x3f3f3f3f;
    for (int x=1;x<=n-h+1;x++)
        for (int y=1;y<=m-w+1;y++)
        {
            tmp=vector<int>();
            for (int k1=1;k1<=h;k1++)
            for (int k2=1;k2<=w;k2++) tmp.push_back(a[x+k1-1][y+k2-1]);
            sort(tmp.begin(),tmp.end());
            int med=tmp[tmp.size()/2];
            ans=min(ans,med);
        }
    cout<<ans<<endl;
}