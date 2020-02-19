#include<bits/stdc++.h>
using namespace std;
struct cvs
{
    int l,r;
    bool operator<(const cvs& b) const
    {
        return (make_pair(l,r))<(make_pair(b.l,b.r));
    }
};
cvs canvas[1050];
int main()
{
    int n;
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    for (int i=1;i<=n;i++) cin>>canvas[i].l>>canvas[i].r;
    sort(canvas+1,canvas+n+1);
    int q;
    cin>>q;
    static int pre[2050];
    for (int i=1;i<=q;i++) cin>>pre[i];
    static int cnt[1050];
    static vector<int> belong[1050];
    for (int i=1;i<=q;i++)
        for (int j=1;j<=n;j++)
        if (pre[i]>=canvas[j].l && pre[i]<=canvas[j].r)
        {
            ++cnt[j];
            belong[j].push_back(pre[i]);
            if (cnt[j]>2) {cout<<"impossible"<<endl;return 0;}
        } 
    //for (int i=1;i<=n;i++) cout<<cnt[i]<<" ";cout<<endl;    
    vector<int> res;
    for (int i=1;i<n;i++)
        if (cnt[i]<2)
        {
            if (cnt[i+1]<2 && canvas[i+1].l==canvas[i].r)
            {
                if (cnt[i+1]==1)
                {
                    if (belong[i+1][0]!=canvas[i+1].l)
                        res.push_back(canvas[i].r),++cnt[i],++cnt[i+1];
                }
                else
                {
                    res.push_back(canvas[i].r),++cnt[i],++cnt[i+1];
                }
            }
        }
    for (int i=1;i<=n;i++)
        if (cnt[i]<2)
            for (int j=canvas[i].l+1;j<canvas[i].r;j++)    
            {
                if (!belong[i].empty() && belong[i][0]==j) continue;
                res.push_back(j);
                ++cnt[i];
                if (cnt[i]==2) break;
            }
    sort(res.begin(),res.end());
    cout<<res.size()<<endl;
    for (auto x:res) cout<<x<<" ";cout<<endl;
}