#include<bits/stdc++.h>
using namespace std;
const double pi=acos(-1.0);
double per;
int n;
vector<int> G[1050];
struct point
{
    double x,y;
    point(double _x=0,double _y=0):x(_x),y(_y){};
    void print() {cout<<x<<" "<<y<<endl;}
};
point ans[1050];
void solve(int now,int from,point last,double &angle)
{
    for (auto x:G[now])
        if (x!=from)
        {
            solve(x,now,ans[x]={last.x+cos(angle),last.y+sin(angle)},angle);
            angle+=per;
        }
}
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    cout.setf(ios::fixed);cout.precision(9);
    cin>>n;per=pi/(n-1);
    for (int i=1;i<=n-1;i++)
    {
        int u,v;
        cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    double angle=0;
    solve(1,0,{0,0},angle);
    for (int i=1;i<=n;i++) ans[i].print();
}