#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    int n;
    cin>>n;
    static int a[1000005],b[1000005];
    for (int i=1;i<=n;i++) cin>>a[i],b[i]=a[i];
    sort(b+1,b+n+1);
    int l=1,r=n;
    bool diff[1000005];
    for (int i=1;i<=n;i++) diff[i]=(a[i]!=b[i]);
    while (!diff[l] && l<=n) l++;
    while (!diff[r] && r>=1) r--;
    //for (int i=1;i<=n;i++) cout<<a[i]<<" ";cout<<endl;
    //cout<<l<<" "<<r<<endl;
    for (int i=1;i<=((r-l+1)>>1);i++)  
        swap(a[l+i-1],a[r-i+1]);
    //for (int i=1;i<=n;i++) cout<<a[i]<<" ";cout<<endl;
    bool ok=true;
    for (int i=1;i<=n;i++) ok=ok && (a[i]==b[i]);
    if (l==n+1 && r==0) cout<<"1 1"<<endl;else
    if (ok) cout<<l<<" "<<r<<endl;else cout<<"impossible"<<endl;
}