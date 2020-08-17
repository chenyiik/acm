#include<bits/stdc++.h>
using namespace std;
bool check(const string& s,int st,int l,int k)
{
    for (int i=1;i<k;i++)
        if (s.substr(st,l)!=s.substr(st+l*i,l)) return false;
    return true;
}
int main()
{
    int n;
    string s;
    static int f[750][750];
    memset(f,0x3f,sizeof(f));
    cin>>n;
    cin>>s;
    s='\0'+s;
    for (int i=1;i<=n;i++) f[i][i]=1;
    for (int l=2;l<=n;l++)
        for (int i=1;i+l-1<=n;i++)
        {
            for (int j=1;j<l;j++)
                if (l%j==0)
                    if (check(s,i,j,l/j))
                        f[i][i+l-1]=min(f[i][i+j-1],f[i][i+l-1]);
            for (int j=i;j<i+l-1;j++)
                f[i][i+l-1]=min(f[i][j]+f[j+1][i+l-1],f[i][i+l-1]);
        }
    cout<<f[1][n]<<endl;
}