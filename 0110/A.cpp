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
        double mid_right=r-(r-l)/3;
        double mid_left=l+(r-l)/3;
        if (longest(point(mid_right))>longest(point(mid_left)))
            r=mid_right;
        else l=mid_left;
    }
    return l;
}
int main()
{
    int n;
    while (~scanf("%d",&n) && n)
    {
        p.clear();
        double x,y;
        double ll=1e10,rr=-1e10;
        while (n--)
        {
            scanf("%lf%lf", &x, &y);
            p.emplace_back(point(x, y));
            ll=min(ll,x);
            rr=max(rr,x);
        }
        double t=find(ll,rr);
        printf("%.9lf %.9lf\n",t,longest(point(t)));
    }
}