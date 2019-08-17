#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n,m;
    cin>>n>>m;
    static long long a[105],md[105];
    for (long long i=1;i<=n;i++) cin>>md[i]>>a[i];
    for (long long i=a[1];i<=m;i+=md[1])
    {
        bool bj=true;
        for (long long j=2;j<=n;j++)
            if (i%md[j]!=a[j]) {bj=false;break;}
        if (bj) {cout<<i<<endl;return 0;}
    }
    cout<<"no"<<endl;
}