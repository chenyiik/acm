#include<bits/stdc++.h>
using namespace std;
int mat2[3][3];
int ans[1050][1050];
int tmp[1050][1050];
int tmp2[1050][1050];
void getmat(int n)
{
    if (n==2)
    {
        for (int i=1;i<=n;i++)
            for (int j=1;j<=n;j++) ans[i][j]=mat2[i][j];
        return;
    }
    getmat(n/2);
    int m=n/2;
    for (int i=1;i<=m;i++)
        for (int j=1;j<=m;j++) tmp[m-j+1][i]=ans[i][j];
    for (int i=1;i<=m;i++)
        for (int j=m+1;j<=n;j++) ans[i][j]=tmp[i][j-m];
    for (int i=1;i<=m;i++)
        for (int j=1;j<=m;j++) tmp2[m-j+1][i]=tmp[i][j];
    for (int i=1;i<=m;i++)
        for (int j=1;j<=m;j++) tmp[i][j]=tmp2[i][j];
    for (int i=m+1;i<=n;i++)
        for (int j=1;j<=m;j++) ans[i][j]=tmp[i-m][j];
    for (int i=1;i<=m;i++)
        for (int j=1;j<=m;j++) tmp2[m-j+1][i]=tmp[i][j];
    for (int i=1;i<=m;i++)
        for (int j=1;j<=m;j++) tmp[i][j]=tmp2[i][j];
    for (int i=m+1;i<=n;i++)
        for (int j=m+1;j<=n;j++) ans[i][j]=tmp[i-m][j-m];
}
int main()
{
    mat2[1][1]=mat2[1][2]=mat2[2][1]=1;mat2[2][2]=-1;
    int n;
    cin>>n;
    getmat(n);
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++) cout<<ans[i][j]<<" \n"[j==n];
    return 0;
}