#include<bits/stdc++.h>
using namespace std;
int n,k;
struct ddq
{
    deque<tuple<int,int>> q;
    void update(int pos,int val)
    {
        while (q.size() && get<1>(q.back())>val) q.pop_back();
        q.push_back(make_tuple(pos,val));
        while (q.size() && (get<0>(q.back())-get<0>(q.front()))>=k) q.pop_front();
    }
    int getval()
    {
        if (q.size()) return get<1>(q.front());
        return 0x3f3f3f3f;
    }
};
ddq dq;
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    static int f[500050];
    string s,t;
    cin>>n>>k;
    cin>>s>>t;
    s='0'+s;t='0'+t;
    static int sum[500050];
    for (int i=1;i<=n;i++) f[i]=0x3f3f3f3f,sum[i]=sum[i-1]+(t[i]!=t[i-1]);
    f[0]=0;
    dq.update(0,(f[0]<<1)-sum[1]);
    for (int i=1;i<=n;i++)
    {
        if(s[i]==t[i]) f[i]=f[i-1];
        else
            f[i]=min(f[i],(dq.getval()+sum[i]+1)/2+1);
        dq.update(i,(f[i]<<1)-sum[i+1]);
    }
    cout<<f[n]<<endl;
}