#include<bits/stdc++.h>
#define sqr(x) ((x)*(x))
using namespace std;
struct point
{
    double x,y;
};
struct Vector
{
    double x,y;
    Vector(){};
    Vector(point a,point b) {x=b.x-a.x;y=b.y-a.y;}
};
double dot(Vector a,Vector b) {return a.x*b.x+a.y*b.y;}
double angle(Vector a,Vector b) {return acos(dot(a,b)/(sqrt(dot(a,a)))/(sqrt(dot(b,b))));}
point p[501];
void solve()
{
    int n;
    cin>>n;
    for (int i=1;i<=n;i++) cin>>p[i].x>>p[i].y;
    p[n+1]=p[1];p[0]=p[n];
    point zx;
    cin>>zx.x>>zx.y;
    double ans=0;
    for (int i=1;i<=n;i++)
    {
        Vector p1(p[i-1],p[i]),p2(p[i+1],p[i]);
        double l=angle(p1,p2);
        if (l<0) l+=acos(-1.0);
        l=acos(-1.0)-l;
        ans+=l*sqrt(sqr(zx.x-p[i].x)+sqr(zx.y-p[i].y));
    }
    printf("%.3f\n",ans);
}
int main()
{
    int T;
    cin>>T;
    for (int cas=1;cas<=T;cas++)
    {
        cout<<"Case #"<<cas<<": ";
        solve();
    }
}