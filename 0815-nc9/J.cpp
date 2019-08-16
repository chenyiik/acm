#include<bits/stdc++.h>
using namespace std;
struct tt
{
    double up,fl,midx;
    bool operator <(const tt& b) {return midx<b.midx;}
}midx[300050];
int main()
{
    int n;
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    for (int i=1;i<=n;i++) {cin>>midx[i].up>>midx[i].fl;midx[i].midx=0.5*(midx[i].up+midx[i].fl);}
    sort(midx+1,midx+1+n);
    double m_line;
    if (n&1) m_line=midx[n>>1+1].midx;
    else m_line=0.5*(midx[n>>1].midx+midx[n>>1+1].midx);
    double area=0;
    for (int i=1;i<=n;i++)
    {
        double dh,df;
        dh=midx[i].up;
        df=midx[i].fl;
        if (m_line>dh) dh=0;
        if (m_line<df) df=0;
        dh=fabs(dh-m_line);
        df=fabs(m_line-df);
        dh=min(dh,df);
        area+=2*dh;
    }
    cout<<area<<endl;
}