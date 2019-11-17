#include<bits/stdc++.h>
using namespace std;
int a[1025][1025];
int main()
{
    int n;
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        string s;
        cin>>s;
        for (int j=1;j<=n;j++)
        {
            a[i][j]=s[j-1]-'0';
            if (a[i][j]==0) a[i][j]=-1;
        }
    }
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            if (i!=j)
            {
                int ans=0;
                for (int k=1;k<=n;k++)
                    ans+=a[i][k]*a[j][k];
                if (ans!=0) {cout<<i<<" "<<j<<" "<<"GG"<<endl;return 0;}
            }
    cout<<"ok"<<endl;
}