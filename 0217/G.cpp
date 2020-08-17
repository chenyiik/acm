#include<bits/stdc++.h>
using namespace std;
struct point
{
    double x,y;
    point(double _x=0,double _y=0):x(_x),y(_y){}
    void get()
    {
        cin>>x>>y;
    }
    double angle()
    {
        return atan2(y,x);
    }
    double len2()
    {
        return x*x+y*y;
    }
};
point p[100050];
int n;
double x,a,T,d;
double calc(point p,double a,double all,double lighttime)
{
    double st=p.angle()-a/2;
    if (st>0)
    {
        if (st+a<all) return lighttime;
        if (st>all) return 0;
        return lighttime*(all-st)/a;
    } else
    {
        if (st+a>all) return lighttime*all/a;
        double ans=lighttime*(st+a)/a;
        double rest=2*acos(-1.0)-all;
        if (rest<-st) ans+=lighttime*(-st-rest)/a;
        return ans;
    }
}
int main()
{
    cin>>n>>x>>a>>T>>d;
    for (int i=1;i<=n;i++)
        p[i].get();
    double lighttime=a/360*T;
    double ct=x/T;
    double left=ct-floor(ct);ct=floor(ct);
    double current=lighttime*ct;
    for (int i=1;i<=n;i++)
        if (p[i].len2()<d*d+1e-8)
        {
            printf("%.11f\n", current + calc(p[i], a * acos(-1.0) / 180, acos(-1.0) * 2 * left, lighttime));
        }
        else puts("0.00000000000");
}