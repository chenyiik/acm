#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    int x,a,b;cin>>x>>a>>b;
    x*=60;
    int ans=0,f1=0,f2=0;
    while (x--)
    {
        if (f1<a) ++f1;
        if (f2)
        {
            --f2;
            if (!f2) ++ans;
        }
        if (f1==a)
            if (!f2) f2=b,f1=0;
    }
    cout<<ans<<endl;
}