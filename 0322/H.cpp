#include<bits/stdc++.h>
using namespace std;
int n,m;
int s[105][105];
int xa,ya,xb,yb;
int loop[105][105];
int color[105][105];
int dx[]={-1,0,0,1};
int dy[]={0,-1,1,0};
bool vis[4][105][105];
int area[4];
void flood(int x,int y,int type)
{
    if (loop[x][y]) return;
    loop[x][y]=type;
    for (int i=0;i<4;i++)
    {
        int newx=x+dx[i],newy=y+dy[i];
        if (newx<1||newx>n||newy<1||newy>m) continue;
        if (s[newx][newy]==1) flood(newx,newy,type);
        if (s[newx][newy]==2) flood(newx+dx[i],newy+dy[i],type);
    }
}
void view(int x,int y,int type)
{
    vis[type][x][y]=1;
    for (int i=0;i<4;i++)
    {
        int newx=x+dx[i],newy=y+dy[i];
        if (newx<1||newx>n||newy<1||newy>m) continue;
        if (!vis[type][newx][newy] && loop[newx][newy]!=type && s[newx][newy]!=2) view(newx,newy,type);
    }
}
void draw(int type)
{
    for (int i=1;i<=n;i++)
    {
        if (!vis[type][i][1] && loop[i][1]!=type && s[i][1]!=2) view(i,1,type);
        if (!vis[type][i][m] && loop[i][m]!=type && s[i][m]!=2) view(i,m,type);
    }
    for (int j=1;j<=m;j++)
    {
        if (!vis[type][1][j] && loop[1][j]!=type && s[1][j]!=2) view(1,j,type);
        if (!vis[type][n][j] && loop[n][j]!=type && s[n][j]!=2) view(n,j,type);
    }
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            if (!s[i][j] && !vis[type][i][j]) color[i][j]|=type;
}
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m;
    for (int i=1;i<=n;i++)
    {
        string str;
        cin>>str;
        for (int j=1;j<=m;j++)
        {
            char ch=str[j-1];
            if (ch=='A') xa=i,ya=j;
            if (ch=='B') xb=i,yb=j;
            s[i][j]=(ch!='.');
        }
    }
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            if (s[i][j])
                s[i][j]+=(s[i-1][j] && s[i+1][j] && s[i][j-1] && s[i][j+1]);
    flood(xa,ya,1);flood(xb,yb,2);
    draw(1);draw(2);
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++) area[color[i][j]]++;
    cout<<area[1]<<" "<<area[2]<<" "<<area[3]<<endl;
}