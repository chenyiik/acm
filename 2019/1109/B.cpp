#include<bits/stdc++.h>
using namespace std;
struct transacation
{
    int c,d;
    bool operator<(const transacation&b) const
    {
        if (d<b.d) return true;
        if (d==b.d && c<b.c) return true;
        return false;
    }
};
int main()
{
    int n,m,s;
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m>>s;
    static transacation mn[1050];
    for(int i=1;i<=n;i++)
    {
        int t1,t2;
        cin>>mn[i].c>>t1>>t2;
        if(mn[i].c<0) mn[i].d=t1;else mn[i].d=t2;
    }
    sort(mn+1,mn+n+1);
    for (int i=1;i<=n;i++)
    {
        s+=mn[i].c;
        if (s<0) {cout<<"YES"<<endl;return 0;}
    }
    cout<<"NO"<<endl;
}