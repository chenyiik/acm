#include<bits/stdc++.h>
using namespace std;
const double eps=1e-6;
int dcmp(double x)
{
    if (fabs(x)<eps) return 0;
    if (x>0) return 1;
    return -1;
}
const double pi=acos(-1.0);
inline double sqr(double x)
{
    return x*x;
}
struct point
{
    double x,y;
    point(){};
    point(double _x,double _y):x(_x),y(_y){}
    friend point operator -(const point& a,const point &b)
    {
        return point(a.x-b.x,a.y-b.y);
    }
    friend point operator /(const point& a,const double &b)
    {
        return point(a.x/b,a.y/b);
    }
    friend point operator+(const point& a,const point& b)
    {
        return point(a.x+b.x,a.y+b.y);
    }
    friend point operator*(const point &a,const double &b)
    {
        return point(a.x*b,a.y*b);
    }
    double norm()
    {
        return sqrt(sqr(x)+sqr(y));
    }
    void print()
    {
        printf("%.12f %.12f",x,y);
    }
};
point rotate(const point& p,double cost,double sint)
{
    double x=p.x,y=p.y;
    return point(x*cost-y*sint,x*sint+y*cost);
}
pair<point,point> crosspoint(point ap,double ar,point bp,double br)
{
    double d=(ap-bp).norm();
    double cost=(ar*ar+d*d-br*br)/(2*ar*d);
    double sint=sqrt(1.0-cost*cost);
    point v=(bp-ap)/(bp-ap).norm()*ar;
    return make_pair(ap+rotate(v,cost,-sint),ap+rotate(v,cost,sint));
}
void check(point x,point y,point z,double a,double b,double c,int w,int h)
{
    if (dcmp((x-y).norm()-a)) {cerr<<w<<" "<<h<<" "<<a<<" "<<b<<" "<<c<<" ";x.print();putchar(' ');y.print();putchar(' ');z.print();putchar('\n');system("read x");}
    if (dcmp((x-z).norm()-b)) {cerr<<w<<" "<<h<<" "<<a<<" "<<b<<" "<<c<<" ";x.print();putchar(' ');y.print();putchar(' ');z.print();putchar('\n');system("read x");}
    if (dcmp((y-z).norm()-c)) {cerr<<w<<" "<<h<<" "<<a<<" "<<b<<" "<<c<<" ";x.print();putchar(' ');y.print();putchar(' ');z.print();putchar('\n');system("read x");}
}
void printans(point x,point y,point z,double a,double b,double c,int w,int h)
{
    x.print();putchar(' ');y.print();putchar(' ');z.print();putchar('\n');
    //check(x,y,z,a,b,c,w,h);
}
int gen()
{
    return 1+rand()%50;
}
int main()
{
    int T;
    cin>>T;
    srand(time(0));
    while (T--)
    {
        double w,h,a,b,c;
        cin>>w>>h>>a>>b>>c;
        //w=gen(),h=gen(),a=gen(),b=gen(),c=gen();
        if (!((a+b>=c) && (b+c>=a) && (a+c>=b))) continue;
        if (dcmp(a+b-c)==0)
        {
            point p1(0,0);
            point p2(a/sqrt(sqr(w)+sqr(h))*w,a/sqrt(sqr(w)+sqr(h))*h);
            point p3(c/sqrt(sqr(w)+sqr(h))*w,c/sqrt(sqr(w)+sqr(h))*h);
            printans(p2,p1,p3,a,b,c,w,h);continue;
        }
        if (dcmp(a+c-b)==0)
        {
            point p1(0,0);
            point p2(a/sqrt(sqr(w)+sqr(h))*w,a/sqrt(sqr(w)+sqr(h))*h);
            point p3(b/sqrt(sqr(w)+sqr(h))*w,b/sqrt(sqr(w)+sqr(h))*h);
            printans(p1,p2,p3,a,b,c,w,h);continue;
        }
        if (dcmp(b+c-a)==0)
        {
            point p1(0,0);
            point p2(b/sqrt(sqr(w)+sqr(h))*w,b/sqrt(sqr(w)+sqr(h))*h);
            point p3(a/sqrt(sqr(w)+sqr(h))*w,a/sqrt(sqr(w)+sqr(h))*h);
            printans(p1,p3,p2,a,b,c,w,h);continue;
        }
        {
            point x(0, 0);
            point y;
            point z;
            if (a <= w) y = point(a, 0); else y = point(w, sqrt(sqr(a) - sqr(w)));
            auto tmp = crosspoint(x, b, y, c);
            point pl = tmp.first, pr = tmp.second;
            if (dcmp(pl.x)>=0&& dcmp(pl.y)>=0 && dcmp(w-pl.x)>=0 && dcmp(h-pl.y)>=0) {
                z=pl;
                printans(x,y,z,a,b,c,w,h);continue;
                continue;
            }
            if (dcmp(pr.x)>=0 && dcmp(pr.y)>=0 && dcmp(w-pr.x) >=0&& dcmp(h-pr.y)>=0) {
                z=pr;
                printans(x,y,z,a,b,c,w,h);continue;
                continue;
            }
            if (b <= w) z = point(b, 0); else z = point(w, sqrt(sqr(b) - sqr(w)));
            tmp = crosspoint(x, a, z, c);
            pl = tmp.first, pr = tmp.second;
            if (dcmp(pl.x)>=0&& dcmp(pl.y)>=0 && dcmp(w-pl.x)>=0 && dcmp(h-pl.y)>=0) {
                y=pl;
                printans(x,y,z,a,b,c,w,h);continue;
                continue;
            }
            if (dcmp(pr.x)>=0 && dcmp(pr.y)>=0 && dcmp(w-pr.x) >=0&& dcmp(h-pr.y)>=0) {
                y=pr;
                printans(x,y,z,a,b,c,w,h);continue;
                continue;
            }
        }
        {
            point y(0,0);
            point x;
            point z;
            if (a<=w) x=point(a,0);else x=point(w, sqrt(sqr(a) - sqr(w)));
            auto tmp = crosspoint(y, c, x, b);
            point pl = tmp.first, pr = tmp.second;
            if (dcmp(pl.x)>=0&& dcmp(pl.y)>=0 && dcmp(w-pl.x)>=0 && dcmp(h-pl.y)>=0) {
                z=pl;
                printans(x,y,z,a,b,c,w,h);continue;
                continue;
            }
            if (dcmp(pr.x)>=0 && dcmp(pr.y)>=0 && dcmp(w-pr.x) >=0&& dcmp(h-pr.y)>=0) {
                z=pr;
                printans(x,y,z,a,b,c,w,h);continue;
                continue;
            }
            if (c<= w) z = point(c, 0); else z = point(w, sqrt(sqr(c) - sqr(w)));
            tmp = crosspoint(y, a, z, b);
            pl = tmp.first, pr = tmp.second;
            if (dcmp(pl.x)>=0&& dcmp(pl.y)>=0 && dcmp(w-pl.x)>=0 && dcmp(h-pl.y)>=0) {
                x=pl;
                printans(x,y,z,a,b,c,w,h);continue;
                continue;
            }
            if (dcmp(pr.x)>=0 && dcmp(pr.y)>=0 && dcmp(w-pr.x) >=0&& dcmp(h-pr.y)>=0) {
                x=pr;
                printans(x,y,z,a,b,c,w,h);continue;
                continue;
            }
        }
        {
            point z(0,0);
            point x;
            point y;
            if (b<=w) x=point(b,0);else x=point(w, sqrt(sqr(b) - sqr(w)));
            auto tmp = crosspoint(z, c, x, a);
            point pl = tmp.first, pr = tmp.second;
            if (dcmp(pl.x)>=0&& dcmp(pl.y)>=0 && dcmp(w-pl.x)>=0 && dcmp(h-pl.y)>=0) {
                y=pl;
                printans(x,y,z,a,b,c,w,h);continue;
                continue;
            }
            if (dcmp(pr.x)>=0 && dcmp(pr.y)>=0 && dcmp(w-pr.x) >=0&& dcmp(h-pr.y)>=0) {
                y=pr;
                printans(x,y,z,a,b,c,w,h);continue;
                continue;
            }
            if (c<= w) y = point(c, 0); else y = point(w, sqrt(sqr(c) - sqr(w)));
            tmp = crosspoint(z, b, y, a);
            pl = tmp.first, pr = tmp.second;
            if (dcmp(pl.x)>=0&& dcmp(pl.y)>=0 && dcmp(w-pl.x)>=0 && dcmp(h-pl.y)>=0) {
                x=pl;
                printans(x,y,z,a,b,c,w,h);continue;
                continue;
            }
            if (dcmp(pr.x)>=0 && dcmp(pr.y)>=0 && dcmp(w-pr.x) >=0&& dcmp(h-pr.y)>=0) {
                x=pr;
                printans(x,y,z,a,b,c,w,h);continue;
                continue;
            }
        }

    }
    return 0;

}