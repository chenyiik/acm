#include<bits/stdc++.h>
using namespace std;
struct group
{
    int a,b;
    bool operator <(const group& _b) const
    {
        return a<_b.a||(a==_b.a && b<_b.b);
    }
};
struct nd
{
    int w;
    int cost;
    int id;
    bool operator <(const nd &b) const
    {
        return w<b.w;
    }
};
priority_queue<nd> pq;
bool used[100050];
group a[100050];
int main()
{
    int T;
    cin>>T;
    while (T--)
    {
        int n;
        cin>>n;
        pq=priority_queue<nd>();
        for (int i=1;i<=n;i++)
        {
            cin>>a[i].a>>a[i].b;
            pq.push(nd{a[i].a,1,i});
            pq.push(nd{a[i].a+a[i].b,2,i});
        }
        for (int x=1;x<=2*n;x++)
        {
            priority_queue<nd> pq2=pq;
            int ans=0;
            int k=x;
            memset(used,0,sizeof(used));
            while (k)
            {
                while (pq2.top().cost>k||used[pq2.top().id]) pq2.pop();
                k-=pq2.top().cost;
                ans+=pq2.top().w;
                used[pq2.top().id]=1;
                pq2.pop();
            }
            cout<<ans<<" ";
        }
        cout<<endl;
    }
}