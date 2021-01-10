#include<bits/stdc++.h>
using namespace std;
struct line
{
    int ep1,ep2,h;
    bool operator<(const line& b) const
    {
        if (ep1!=b.ep1) return ep1<b.ep1;
        if (ep2!=b.ep2) return ep2<b.ep2;
        if (h!=b.h) return h<b.h;
        return false;
    }
    void get()
    {
        cin>>ep1>>ep2>>h;
    }
};
line h[100050],v[100050];
int n,m;
struct rec
{
    int p,type,height;
    bool operator<(const rec& b) const
    {
        if (p!=b.p) return p<b.p;
        if (type!=b.type) return type<b.type;
        if (height!=b.height) return height<b.height;
        return false;
    }
};
bool check(int len)
{
    vector<rec> ev;
    multiset<int> s;
    for (int i=1;i<=n;i++)
    {
        int x1,x2,y;
        x1=h[i].ep1,x2=h[i].ep2,y=h[i].h;
        if (x2-x1>=2*len)
        {
            ev.push_back({x1+len,0,y});
            ev.push_back({x2-len,2,y});
        }
    }
    for (int i=1;i<=m;i++)
    {
        int y1,y2,x;
        y1=v[i].ep1,y2=v[i].ep2,x=v[i].h;
        if (y2-y1>=2*len) ev.push_back({x,1,i});
    }
    sort(ev.begin(),ev.end());
    bool succ=false;
    for (auto x:ev)
    {
        if (succ) break;
        if (x.type==0) s.insert(x.height);
        if (x.type==2) s.erase(s.find(x.height));
        if (x.type==1)
        {
            int idx=x.height;
            auto it=s.lower_bound(v[idx].ep1+len);
            if (it!=s.end() && *it<=v[idx].ep2-len) succ=true;
        }
    }
    return succ;
}
int main()
{
    int t;
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>t;
    while (t--)
    {
        cin>>n>>m;
        for (int i=1;i<=n;i++)
            h[i].get();
        for (int i=1;i<=m;i++)
            v[i].get();
        int l=0,r=100050;
        while (l<r-1)
        {
            int mid=(l+r)>>1;
            if (check(mid)) l=mid;
            else r=mid;
        }
        cout<<l<<endl;
    }
}