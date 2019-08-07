#include<bits/stdc++.h>
using namespace std;
struct pt
{
    int x,y,val;
};
pt nval[2050];
int xval[2050],yval[2050];
unordered_map<int,int> mpx;
unordered_map<int,int> mpy;
int matrix[2050][2050];
int nxt[2050][2050];
int qz[2050][2050];
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n;
        scanf("%d",&n);
        mpx.clear(),mpy.clear();
        for (int i=1;i<=n;i++) {scanf("%d%d%d",&nval[i].x,&nval[i].y,&nval[i].val);xval[i]=nval[i].x;yval[i]=nval[i].y;}
        sort(xval+1,xval+1+n);
        int cntx=unique(xval+1,xval+1+n)-xval-1;
        for (int i=1;i<=cntx;i++) mpx[xval[i]]=i;
        sort(yval+1,yval+1+n);
        int cnty=unique(yval+1,yval+1+n)-yval-1;
        for (int i=1;i<=cnty;i++) mpy[yval[i]]=i;
        memset(matrix,0,sizeof(matrix));
        for (int i=1;i<=n;i++) for (int j=1;j<=n;j++) nxt[i][j]=cntx+1;
        for (int i=1;i<=n;i++) matrix[mpx[nval[i].x]][mpy[nval[i].y]]+=nval[i].val;
        for (int i=1;i<=cnty;i++)
        {
            int lastnz=0;
            for(int j=1;j<=cntx;j++)
            {
                matrix[i][j]=matrix[i][j]+matrix[i-1][j];
                if(matrix[i][j]!=0)
                {
                    nxt[i][lastnz]=j;
                    lastnz=j;
                }
            }
        }
        int ans=0;
        for (int i=1;i<=cnty;i++)
        for (int j=i;j<=cnty;j++)
        {
            int sum=0;
            for (int k=min(nxt[i][0],nxt[j][0]);k<=cntx;k=min(nxt[i][k],nxt[j][k]))
            {
                sum=sum+(matrix[j][k]-matrix[i-1][k]);
                if (sum<0) sum=0;
                if (sum>ans) ans=sum;
            }
        }
        cout<<ans<<endl;
    }
}