#include<bits/stdc++.h>
using namespace std;
struct clique
{
    long long w;
    bitset<110> edge;
    clique() {w=0;}
    clique(long long _w,bitset<110> bit)
    {
        w=_w;edge=bit;
    }
    bool operator <(const clique& b) const
    {
        return w>b.w;
    }
};
bitset<110> e[110];
int n,k,a[110];
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n>>k;
    for (int i=1;i<=n;i++) cin>>a[i];
    cin.get(*new char());
    for (int i=1;i<=n;i++)
    {
        string s;
        getline(cin,s);
        for (int j=0;j<n;j++)
        if (s[j]=='1') e[i].set(j+1);
    }
    priority_queue<clique> pq;
    bitset<110> bit;
    bit.reset();
    long long val=0;
    pq.push(clique(val,bit));
    while (k--)
    {
        if (pq.empty()) {cout<<-1<<endl;return 0;}
        if (!k) {cout<<pq.top().w<<endl;return 0;}
        bit=pq.top().edge,val=pq.top().w;
        //cout<<bit<<" "<<val<<endl;
        pq.pop();
        int nxt=1;
        for (int i=1;i<=n;i++) if (bit[i]) nxt=i+1;
        for (int j=nxt;j<=n;j++) {
            //cout << bit << " " << e[j] << endl;
            if (!bit[j] && ((bit & e[j]) == bit)) {
                bitset<110> t;
                t = bit;
                t.set(j);
                pq.push(clique(val + a[j], t));
                //cout << val + a[j] << endl;
            }
            //cout << endl;
        }
    }
    return 0;
}