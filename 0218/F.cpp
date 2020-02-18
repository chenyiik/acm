#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long T,res=0;
    static long long x[1050],y[1050];
    cin>>T;
    while (T--)
    {
        long long n;
        cin>>n;
        for (long long i=1;i<=n;i++) cin>>x[i]>>y[i];
        x[0]=x[n],y[0]=y[n];
        long long ans=0;
        for (long long i=0;i<n;i++) ans+=x[i]*y[i+1]-x[i+1]*y[i];
        res+=abs(ans);
    }
    cout<<(res>>1LL)<<endl;
}