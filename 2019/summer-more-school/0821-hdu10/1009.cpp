#include<bits/stdc++.h>
using namespace std;
int status[2050][2050];
int ans=0;
void knock(int x,int y)
{
    status[x][y]=0;ans++;
    if(status[x-1][y]==1 || status[x-1][y]==3)
    {
        status[x-1][y]-=1;
        if(status[x-1][y]==0) knock(x-1,y);
    }
    if(status[x+1][y]==1 || status[x+1][y]==3)
    {
        status[x+1][y]-=1;
        if(status[x+1][y]==0) knock(x+1,y);
    }
    if(status[x][y-1]==2 || status[x][y-1]==3)
    {
        status[x][y-1]-=2;
        if(status[x][y-1]==0) knock(x,y-1);
    }
    if(status[x][y+1]==2 || status[x][y+1]==3)
    {
        status[x][y+1]-=2;
        if(status[x][y+1]==0) knock(x,y+1);
    }
}
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    int T;
    cin>>T;
    while (T--)
    {
        int n,m,q;
        cin>>n>>m>>q;
        for (int i=1;i<=n;i++)
        {
            status[i][0]=-1;
            for (int j=1;j<=m;j++)
                status[i][j]=3;
            status[i][m+1]=-1;
        }
        for (int j=1;j<=m;j++)
        {
            status[0][j]=status[n+1][j]=-1;
        }
        while (q--)
        {
            int x,y;
            cin>>x>>y;
            ans=0;
            if (status[x][y]!=0) knock(x,y);
            cout<<ans<<endl;
        }
    }
}