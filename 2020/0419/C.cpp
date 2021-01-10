#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    static bitset<1000050> ispri;
    static vector<long long> pri;
    ispri.set();ispri[1]=false;
    for (long long i=2;i<1000050;i++)
        if (ispri[i])
            for (long long j=2;i*j<1000050;j++) ispri[i*j]=false;
    for (long long i=2;i<1000050;i++) if (ispri[i]) pri.push_back(i);
    long long n;
    while (cin>>n && n)
    {
        long long ans=1;
        for (auto x:pri)
        {
            if (x>n) break;
            long long cnt=0;
            for (long long t=n;t;t/=x) cnt+=t/x;
            ans*=((cnt+2)*(cnt+1)/2)%10000007;
            ans%=10000007;
        }
        cout<<ans<<endl;
    }
}
