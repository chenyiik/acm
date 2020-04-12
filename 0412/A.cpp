#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    int n;
    static int a[1050],b[1050];
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=n;i++) cin>>b[i];
    queue<tuple<int,int>> q1,q2;
    for (int i=1;i<=n;i++)
        if (a[i]-b[i]>0) q1.push(make_tuple(i,a[i]-b[i]));else q2.push(make_tuple(i,a[i]-b[i]));
    while (q1.size())
    {
        auto u=q1.front();q1.pop();
        int p=get<0>(u),q=get<1>(u);
        while (q)
        {
            auto x=q2.front();
            int qx=-1*get<1>(x);
            int tt=min(qx,q);
            if (tt) cout<<p<<" "<<get<0>(x)<<" "<<tt<<endl;
            q-=tt;
            get<1>(q2.front())+=tt;
            if (get<1>(q2.front())==0) q2.pop();
        }
    }
}