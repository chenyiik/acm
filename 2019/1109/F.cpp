#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main()
{
    ll x,y,z,a,b,c,t1,t2,t3,d,k,i,l,j;
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>x>>y>>z>>a>>b>>c>>t1>>t2>>t3>>d>>k>>i>>l>>j;
    ll len[3]={x,y,z};
    ll t[3]={t1,t2,t3};
    ll point[3][3][2]={{{-1,-1},{a,b+1},{a+1,c}},
                                {{b+1,a},{-1,-1},{b,c+1}},
                                {{c, a+1},{c+1,b},{-1,-1}}};
    ll ans=0x3f3f3f3f;
    if(k==l)
    {
        ans=abs(i-j)*t[k-1];
        ll others[3][2]={{2,3},{1,3},{1,2}};
        ll next1=others[k-1][0];
        ll next2=others[k-1][1];
        ll from1=point[k-1][next1-1][0];
        ll to3=point[next2-1][l-1][1];
        ll ans1=3ll*d+t[next1-1]+t[next2-1]+abs(i-from1)*t[k-1]+abs(j-to3)*t[l-1];
        swap(next1,next2);
        from1=point[k-1][next1-1][0];
        to3=point[next2-1][l-1][1];
        ll ans2=3ll*d+t[next1-1]+t[next2-1]+abs(i-from1)*t[k-1]+abs(j-to3)*t[l-1];
        ans=min(ans,min(ans1,ans2));
    }
    else
    {
        ll from=point[k-1][l-1][0];
        ll to=point[k-1][l-1][1];
        ll ans1=abs(i-from)*t[k-1]+abs(j-to)*t[l-1]+d;
        ll other=k^l;
        ll from1=point[k-1][other-1][0];
        ll to1=point[k-1][other-1][1];
        ll from2=point[other-1][l-1][0];
        ll to2=point[other-1][l-1][1];
        ll ans2=abs(i-from1)*t[k-1]+abs(j-to2)*t[l-1]+2ll*d+t[other-1];
        ans=min(ans1,ans2);
    }
    cout<<ans<<endl;
}