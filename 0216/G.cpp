#include<bits/stdc++.h>
using namespace std;
const long double eps=1e-8;
long double jiao(long double a, long double b, long double l, long double r)
{
    if (b < l || a > r) return 0.0;
    if (a < l) a = l;
    if (b > r) b = r;
    return (b - a) / (r - l);
}

int main()
{
    int t; scanf("%d", &t);
    while (t--)
    {
        int n, v, l, r; scanf("%d%d%d%d", &n, &v, &l, &r);
        long double range=1.0*v*v/10.0,l1=l*acos(-1.0)/180.0,r1=r*acos(-1.0)/180.0;
        while (n--)
        {
            long double x, y; scanf("%Lf%Lf", &x, &y);
            x=min(x,range),y=min(y,range);
            long double a = asin(10.0*x/(v*v))/2;
            long double b = asin(10.0*y/(v*v))/2;
            long double ans=0.0;
            if (l==r)
            {
                if (l1+eps>a && r1-eps<b) ans=1.0;
            } else
            {
                a=max(a,l1),b=min(b,r1);b=max(a,b);
                ans+=(b-a)/(r1-l1);
            }
            a=acos(-1.0)/2-asin(10.0*y/(v*v))/2;
            b=acos(-1.0)/2-asin(10.0*x/(v*v))/2;
            if (l==r)
            {
                if (l1+eps>a && r1-eps<b) ans=1.0;
            } else
            {
                a=max(a,l1),b=min(b,r1);b=max(a,b);
                ans+=(b-a)/(r1-l1);
            }
            printf("%.4Lf\n", ans);
        }
    }
    return 0;
}
