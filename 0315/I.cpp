#include<bits/stdc++.h>
using namespace std;
struct point
{
    double x,y;
    point(double _x=0,double _y=0):x(_x),y(_y){};
};
double cross(point p1,point p2,point p0)
{
    return (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);
}
inline double calc(double x1,double y1,double x2,double y2)
{
    return acos((x1*x2+y1*y2)/(sqrt(x1*x1+y1*y1)*sqrt(x2*x2+y2*y2)));
}
struct pgon
{
    point p[1050];
    int sz;
    bool inside(point b)
    {
        double angle=0;
        for(int i=0;i<sz;i++)
        {
            double x1=p[i].x-b.x;
            double y1=p[i].y-b.y;
            double x2=p[(i+1)%sz].x-b.x;
            double y2=p[(i+1)%sz].y-b.y;
            angle+=calc(x1,y1,x2,y2);
        }
        return fabs(angle-2*acos(-1.0))<1e-8;
    }
};
pgon s,r,m;
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>s.sz>>r.sz>>m.sz;
    for (int i=0;i<s.sz;i++)
        cin>>s.p[i].x>>s.p[i].y;
    for (int i=0;i<r.sz;i++)
        cin>>r.p[i].x>>r.p[i].y;
    for (int i=0;i<m.sz;i++)
        cin>>m.p[i].x>>m.p[i].y;
    int q;
    cin>>q;
    while (q--)
    {
        double x,y;
        cin>>x>>y;
        if (s.inside(point(x,y))) {cout<<"Sheena"<<endl;continue;}
        if (r.inside(point(x,y))) {cout<<"Rose"<<endl;continue;}
        if (m.inside(point(x,y))) {cout<<"Maria"<<endl;continue;}
        cout<<"Outside"<<endl;
    }
}