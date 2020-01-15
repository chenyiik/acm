#include<bits/stdc++.h>
using namespace std;
int main()
{
    map<char,long long> cnt;
    string s;
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>s;
    for (auto ch:s) cnt[ch]++;
    long long ans=1;
    for (auto x:cnt)
    {
        ans*=(x.second+1);
        ans%=11092019LL;
    }
    cout<<ans<<endl;
}