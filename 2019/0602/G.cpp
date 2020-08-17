#include<bits/stdc++.h>
using namespace std;
static vector<long long> tx,ty;
struct p
{
    long long x1,x2,y1,y2;
};
p a[100050];
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    int T;
    cin>>T;
    while (T--)
    {
        int n;
        cin>>n;
        tx.clear(),ty.clear();
        for (int i=1;i<=n;i++)
        {
            cin>>a[i].x1>>a[i].y1>>a[i].x2>>a[i].y2;
            tx.push_back(a[i].x1);tx.push_back(a[i].x2);
            ty.push_back(a[i].y1);ty.push_back(a[i].y2);
        }
        sort(tx.begin(),tx.end());
        sort(ty.begin(),ty.end());
        int mx=(tx[tx.size()/2]+tx[tx.size()/2-1])/2;
        int my=(ty[ty.size()/2]+ty[ty.size()/2-1])/2;
        long long ans=0;
        for (int i=1;i<=n;i++)
        {
            ans+=(abs(mx-a[i].x1)+abs(mx-a[i].x2)-a[i].x2+a[i].x1)/2;
            ans+=(abs(my-a[i].y1)+abs(my-a[i].y2)-a[i].y2+a[i].y1)/2;
        }
        cout<<ans<<endl;
    }
}