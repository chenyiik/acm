#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;cin>>n;
    int a[1005],b[1005],c[1005];
    for (int i=1;i<=n;i++) cin>>a[i],c[i]=0x3f3f3f3f;
    for (int i=1;i<=n;i++) cin>>b[i];
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++) c[i]=min(c[i],abs(a[i]-b[j]));
    cout<<*(max_element(c+1,c+n+1))<<endl;
}