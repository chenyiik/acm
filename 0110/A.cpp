#include<bits/stdc++.h>
using namespace std;
struct point
{
    double x,y;
    point(double _x=0,double _y=0):x(_x),y(_y){};
};
vector<point> p;
double dist(point a,point b)
{
    return ((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
double longest(point aim)
{
    double ans=-1e10;
    for (auto x:p)
    {
        ans=max(ans,dist(x,aim));
    }
    return sqrt(ans);
}
double find(double l,double r)
{
    while (r-l>1e-10)
    {
        double mid=0.5*(l+r);
        double mid_left=0.5*(mid+l);
        if (longest(point(mid))>longest(point(mid_left)))
            r=mid;
        else l=mid_left;
    }
    return 0.5*(l+r);
}
int main()
{
    int n;
    freopen("balance.in","r",stdin);
    freopen("test.out","w",stdout);
    while (~scanf("%d",&n) && n)
    {
        p.clear();
        double x,y;
        while (n--)
        {
            scanf("%lf%lf",&x,&y);
            p.emplace_back(point(x,y));
        }
        double t=find(-2e5,+2e5);
        printf("%.9lf %.9lf\n",t,longest(point(t)));
    }
}