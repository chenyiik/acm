#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b;
    cin>>a>>b;
    if (a<=b) cout<<b-a<<endl;
    else
    {
        int ans=0;
        while (a!=b)
        {
            if (a<=b)
            {
                ans+=b-a;
                a=b;
                break;
            }
            if (a&1) a++;
            else a>>=1;
            ans++;
        }
        cout<<ans<<endl;
    }
}