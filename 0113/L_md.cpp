#include <bits/stdc++.h>
#define pb push_back
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef pair<long long,long long> pll;

ll area2(pll a,pll b,pll c){
    return (b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x);
}

bool f(pll a,pll b,pll c){
    return area2(a,b,c)>0;
}

int main()
{
    static pll a[100050];
    int T,n;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            scanf("%d%d",&a[i].x,&a[i].y);
        sort(a,a+n);
        vector<pll> v;
        v.pb(a[0]);
        for(int i=1;i<n;i++){
            while(v.size()>1&&f(v[v.size()-2],v[v.size()-1],a[i])){
                v.pop_back();
            }
            v.pb(a[i]);
        }
        int l=v.size();
        for(int i=n-2;i>-1;i--){
            while(v.size()-l>=1&&f(v[v.size()-2],v[v.size()-1],a[i])){
                v.pop_back();
            }
            v.pb(a[i]);
        }
        reverse(v.begin(),v.end());v.pop_back();
        const int sz=v.size();
        ll ans=0;
        if(sz==3){
            pll A=v[0],B=v[1],C=v[2];
            ll area=area2(A,B,C);
            for(int i=0;i<n;i++){
                pll D=a[i];
                if(D!=A&&D!=B&&D!=C){
                    ans=max(ans,area-area2(A,B,D));
                    ans=max(ans,area-area2(B,C,D));
                    ans=max(ans,area-area2(C,A,D));
                }
            }
        } else {
            auto next = [&](int i) { return (i + 1) % sz; };
            for (int i = 0; i < sz; i++) {
                int now = next(next(i)), l = next(i), r = next(now);
                for (int j = 0; j < sz - 3; j++, now = next(now)) {
                    while(area2(v[i],v[l],v[now])<area2(v[i],v[next(l)],v[now]))
                        l=next(l);
                    while(area2(v[i],v[now],v[r])<area2(v[i],v[now],v[next(r)]))
                        r=next(r);
                    ans=max(ans,area2(v[i],v[now],v[r])+area2(v[i],v[l],v[now]));
                }
            }
        }
        printf("%lld",ans>>1);
        puts(ans&1?".5":"");
    }
}