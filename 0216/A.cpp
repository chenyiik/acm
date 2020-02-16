#include<bits/stdc++.h>
using namespace std;
#define a1 first
#define a2 second
int n,m;
using dtype=pair<pair<int,int>,int>;//x1,x2,y||y1,y2,x
using rdtype=pair<int,pair<int,int>>;
dtype u[100050],v[100050];
bool check(int len)
{
    vector<rdtype> ev;
    multiset<int> s;
    for (int i=1;i<=n;i++)
    {
        int x1=u[i].a1.a1,x2=u[i].a1.a2,y=u[i].a2;
        if (x2-x1>=2*len)
        {
            ev.push_back({x1+len,{0,y}});
            ev.push_back({x2-len,{2,y}});
        }
    }
    for (int i=1;i<=n;i++)
    {
        int y1=u[i].a1.a1,y2=u[i].a1.a2,x=u[i].a2;
        if (y2-y1>=2*len)
        {
            ev.push_back({x,{1,i}});
        };
    }
    sort(ev.begin(),ev.end());
    bool succ=false;
    for (auto d:ev)
    {
        if (succ) break;
        if (d.a2.a1==0) s.insert(d.a2.a2);
        if (d.a2.a1==2) s.erase(s.find(d.a2.a2));
        if (d.a2.a1==1)
        {
            int idx=d.a2.a2;
            auto it=s.lower_bound(v[idx].a1.a1+len);
            if (it!=s.end() && *it<=v[idx].a1.a2-len) succ=true;
        }
    }
    return succ;
}
int main()
{
    int t;
    scanf("%d",&t);
    while (t--)
    {
        scanf("%d%d",&n,&m);
        for (int i=1;i<=n;i++) cin>>u[i].a1.a1>>u[i].a1.a2>>u[i].a2;
        for (int i=1;i<=m;i++) cin>>v[i].a1.a1>>v[i].a1.a2>>v[i].a2;
        int l=0,r=100050;
        while (r>l+1)
        {
            int mid=(l+r)>>1;
            if (check(mid)) l=mid;
            else r=mid;
        }
        if (check(r)) cout<<r<<endl;else cout<<l<<endl;
    }
}