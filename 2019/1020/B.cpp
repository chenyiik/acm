#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    static long long a[20005];
    for (int i=1;i<=n;i++) cin>>a[i];
    if (*max_element(a+1,a+n+1)==a[1]) cout<<"S"<<endl;else cout<<"N"<<endl;
    return 0;
}