#include<bits/stdc++.h>
using namespace std;
#include<bits/stdc++.h>
using namespace std;
struct point
{
    long long x,y;
    bool operator <(const point& b) const {
        return (x<b.x)||(x==b.x && y<b.y);
    }
};
vector<point> p;
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    int T;
    cin>>T;
    while (T--)
    {
        int n;
        cin>>n;
        p.clear();
        for (int i=1;i<=n;i++) {
            long long x,y;
            cin>>x>>y;
            point tmp;
            tmp.x=x;tmp.y=y;
            p.push_back(tmp);
        }
        sort(p.begin(),p.end());
        point midl=p[p.size()/2-1],midr=p[p.size()/2];
        printf("%lld %lld %lld %lld\n",midl.x-1,midl.y+20001,midl.x+1,midl.y-20000);
    }
    return 0;
}