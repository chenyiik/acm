#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    int n,m;
    cin>>n>>m;
    static int mat[1050][1050];
    for (int i=1;i<=n;i++)
    {
        string s;
        cin>>s;
        for (int j=1;j<=m;j++) mat[i][j]=(s[j-1]=='G');
    }
    static int f[1050][1050];
    for (int i=1;i<=n;i++)
    {
        f[i][m]=1;
        for (int j=m-1;j>=1;j--)
            if (mat[i][j+1]==mat[i][j]) f[i][j]=f[i][j+1]+1;else f[i][j]=1;
    }
    /*for (int i=0;i<=m;i++) cerr<<i<<" ";cerr<<endl;
    for (int i=1;i<=n;i++)
    {
        cerr<<i<<" ";
        for (int j=1;j<=m;j++) cerr<<f[i][j]<<" ";cerr<<endl;
    }*/
    int maxl=1;
    for (int j=1;j<=m;j++)
    {
        static stack<int> s;
        while (!s.empty()) s.pop();
        s.push(0);
        static int u[1050],d[1050];
        for (int i=1;i<=n;i++)
        {
            while (f[s.top()][j]>=f[i][j]) s.pop();
            u[i]=s.top()+1;
            s.push(i);
        }
        while (!s.empty()) s.pop();
        s.push(n+1);
        for (int i=n;i>=1;i--)
        {
            while (f[s.top()][j]>=f[i][j]) s.pop();
            d[i]=s.top()-1;
            s.push(i);
        }
        /*cerr<<j<<":"<<endl;
        for (int i=1;i<=n;i++) cerr<<i<<" "<<u[i]<<" "<<d[i]<<endl;*/
        for (int i=1;i<=n;i++)
        {
            int xl=f[i][j],yl=d[i]-u[i]+1;
            int l=min(xl,yl);
            maxl=max(l,maxl);
        }
    }
    cout<<maxl*maxl<<endl;
}