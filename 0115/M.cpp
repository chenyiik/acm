#include<bits/stdc++.h>
using namespace std;
char mp[1050][1050];
int fa[2000050],tot=0,n,m;
const char wall[2]={'/','\\'};
int find(int x)
{
    return (fa[x]==x)?x:fa[x]=find(fa[x]);
}
void merge(int x,int y)
{
    auto fx=find(x),fy=find(y);
    if (fx==fy) {++tot;return;}
    fa[fy]=fx;
}
inline int getid(int x,int y)
{
    return x*(m+1)+y;
}
int main()
{
    scanf("%d%d",&n,&m);
    for (int i=0;i<=n;i++)
        for (int j=0;j<=m;j++) fa[getid(i,j)]=getid(i,j);
    for (int i=0;i<n;i++)
    {
        scanf("%s",mp[i]);
        for (int j=0;j<m;j++)
        {
            if (mp[i][j]==wall[0]) merge(getid(i+1,j),getid(i,j+1));
            if (mp[i][j]==wall[1]) merge(getid(i,j),getid(i+1,j+1));
        }
    }
    printf("%d\n",tot);
}