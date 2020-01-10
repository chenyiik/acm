#include<bits/stdc++.h>
using namespace std;
struct rect
{
    long long l,s;
    bool operator<(const rect&b) const
    {
        if(l<b.l) return true;
        if(l==b.l&&s<b.s) return true;
        return false;
    }
};
long long area(rect a,rect b)
{
    return min(a.l,b.l)*min(a.s,b.s);
}
bool contain(rect a,rect b)
{
    if(b.l<=a.l&&b.s<=a.s) return true;
    return false;
}
int main()
{
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    long long n;
    cin>>n;
    static rect a[100005];
    for(long long i=1;i<=n;i++)
    {
        cin>>a[i].l>>a[i].s;
        if(a[i].l<a[i].s) swap(a[i].l,a[i].s);
    }
    sort(a+1,a+n+1);
    static stack<rect> st;
    long long cur=n;
    st.push(a[cur--]);
    long long ans=0;
    while(!st.empty()&&cur>0)
    {
        auto t=st.top();
        auto y=a[cur--];
        if(contain(t,y))
        {
            ans=max(ans,area(t,y));
            st.push(y);
        }
        else
        {
            while(!contain(t,y)&&!st.empty())
            {
                ans=max(ans,area(t,y));
                st.pop();
                if (!st.empty()) t=st.top();
            }
            ans=max(ans,area(t,y));
            st.push(y);
        }
    }
    long long pans=ans*2;
    for(int i=1;i<=n;i++)
    {
        long long t=a[i].l*a[i].s;
        pans=max(t,pans);
    }
    cout<<pans/2ll<<'.'<<(pans%2ll?5ll:0ll)<<endl;
    //printf("%lld.%lld\n",pans/2,(pans%2?5ll:0ll));
}