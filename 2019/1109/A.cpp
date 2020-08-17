#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a[4];
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>a[1]>>a[2]>>a[3];
    sort(a+1,a+4);
    int ans=0;
    ans+=a[2]-a[1];
    a[3]+=a[2]-a[1];
    ans+=a[3]-a[2];
    cout<<ans<<endl;
}