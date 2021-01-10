#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    long long t,k;
    cin>>t>>k;
    cout<<t+t/k+(t%k>0)<<endl;
}