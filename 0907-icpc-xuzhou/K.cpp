#include<bits/stdc++.h>
using namespace std;
struct point
{
    int x,y;
    point(int _x=0,int _y=0):x(_x),y(_y){}
    bool operator< (const point& b) const
    {
        return ((x<b.x)||(x==b.x && y<b.y));
    }
};
point p[1050];
int n;
map<point,int> mp;
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        int x,y;
        cin>>x>>y;
        x<<=1,y<<=1;
        p[i]=point(x,y);
    }
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            {
                auto mid=point((p[i].x+p[j].x)>>1,(p[i].y+p[j].y)>>1);
                mp[mid]++;
            }
    int mx=0;
    for (auto p:mp) mx=max(mx,p.second);
    cout<<n-mx<<endl;
}