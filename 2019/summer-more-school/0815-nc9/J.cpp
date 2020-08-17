#include<bits/stdc++.h>
using namespace std;
vector<pair<long long,long long> > midl;
int main()
{
    long long n;
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    for (long long i=1;i<=n;i++)
    {
        long long yl,yt;
        cin>>yl>>yt;
        yl*=2;yt*=2;
        midl.emplace_back(make_pair(yl,1));
        midl.emplace_back(make_pair((yl+yt)>>1,-2));
        midl.emplace_back(make_pair(yt,1));
    }
    sort(midl.begin(),midl.end());
    long long ans=0,cnt=0;
    long long now=0,area=0;
    for (long long i=0;i<midl.size()-1;i++)
    {
        cnt+=midl[i].second;
        now=midl[i+1].first-midl[i].first;
        area+=cnt*now;
        ans=max(ans,area);
    }
    cout<<ans<<endl;
}