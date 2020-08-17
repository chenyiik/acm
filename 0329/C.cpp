#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    long long n,t;
    long long maxt=0;
    cin>>n>>t;
    long long sumt=0;
    for (long long i=1;i<=n;i++)
    {
        long long h;cin>>h;
        maxt=max(maxt,h);
        sumt+=h;
        if (i==1) cout<<t/h+1<<endl;
        else
        {
            if (t>=sumt) cout<<(t-sumt)/maxt+2<<endl;
            else cout<<1<<endl;
        }   
    }
}