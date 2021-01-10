#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    long long n,m;
    static long long a[100050],b[100050];
    cin>>n>>m;
    for (long long i=1;i<=n;i++) cin>>a[i];
    for (long long i=1;i<=n;i++) cin>>b[i];
    static long long fb[100050];
    for (long long i=1;i<=n;i++) fb[i]=fb[i-1]+b[i];
    static vector<long long> getballon;
    long long lastsol=0;
    for (long long i=1;i<=n;i++)
    {
        lastsol+=a[i];
        if (lastsol<=m) getballon.push_back(lastsol);
    }
    long long ts=getballon.size();
    priority_queue<tuple<long long,long long>> pq;
    for (long long i=1;i<=ts;i++) pq.push(make_tuple(b[i],-fb[i]));
    long long delay=0;
    static vector<long long> res;
    for (auto x:getballon)
    {
        while (pq.size() && -get<1>(pq.top())+delay<x) pq.pop();
        if (pq.empty()) break;
        if (-get<1>(pq.top())+delay<=m)
            res.push_back(-get<1>(pq.top())+delay);
        delay+=get<0>(pq.top());
    }
    if (pq.empty()||delay+fb[ts]<=m) {cout<<-1<<endl;return 0;}
    cout<<res.size()<<endl;
    for (auto x:res) cout<<x<<" ";cout<<endl;
}