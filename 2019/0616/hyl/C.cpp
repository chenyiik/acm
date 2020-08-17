#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>T;
    while (T--)
    {
        int n,m;
        cin>>n>>m;
        cout<<(((n+m)&1)?2:12)<<endl;
    }
}