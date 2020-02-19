#include<bits/stdc++.h>
using namespace std;
struct point
{
    int x;double y;
    bool operator<(const point& b)
    {
        if (y!=b.y) return y<b.y;
        return x<b.x;
    }
};
int main()
{
    int n,k;
    static point h[100050],deltah[100050];
    ios::sync_with_stdio(0);cin.tie(0);
    cout.setf(ios::fixed);cout.precision(9);
    cin>>n>>k;
    for (int i=0;i<=n;i++) cin>>h[i].y,h[i].x=i;
    while (k--)
    {
        double g;cin>>g;g*=10;
        for (int i=0;i<=n;i++)
        {
            deltah[i]=h[i];
            deltah[i].y-=i*g;
        }
        sort(deltah,deltah+n+1);
        double ans=-1;
        /*for (int l=0;l<=n;l++)
            for (int r=l+1;r<=n;r++)
            {
                static bool vis[100050];
                memset(vis,0,sizeof(vis));
                int minm,maxm;
                double sumt;
                minm=0x3f3f3f3f,maxm=0,sumt=0;
                for (int i=l;i<=r;i++)
                {
                    minm=min(deltah[i].x,minm);
                    maxm=max(deltah[i].x,maxm);
                    sumt+=deltah[i].y;
                    vis[deltah[i].x]=true;
                }
                if (sumt>=0)
                {
                    for (int i=minm;i<=maxm;i++)
                        if (!vis[i]) continue;
                    double ex=0;
                    if (sumt>=0)
                    {
                        double delta=deltah[r].y-deltah[l].y;
                        if (r<n) ex=max(ex,delta/fabs(deltah[r+1].y-deltah[r].y));
                        if (l>=1) ex=max(ex,delta/fabs(deltah[l].y-deltah[l-1].y));
                    }
                    ex=min(0.0,max(1.0,ex));
                    ans=max(ans,double(r-l)+ex);
                }
            }*/
        int l=n;
        for (auto r:deltah)
        {
            auto xr=r.x;
            if (l<xr)
            {
                double ex=0;
                if (l>=1) ex=max(ex,double(r.y-(h[l].y-g*(l)))/fabs((h[l].y-g*(l))-(h[l-1].y-g*(l-1))));
                if (xr<n) ex=max(ex,double(r.y-(h[l].y-g*(l)))/fabs((h[xr+1].y-g*(xr+1))-r.y));
                ex=max(0.0,min(1.0,ex));
                ans=max(ans,double(xr-l)+ex);
            }
            l=min(l,xr);
        }
        if (ans<0) cout<<"-1"<<endl;else cout<<ans<<endl;
    }

}