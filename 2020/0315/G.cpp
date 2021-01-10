#include<bits/stdc++.h>
using namespace std;
vector<long long> frac[500050],prifrac[500050];
bool vis[500050];
long long cnt[500050],n,t;
long long val[200050];
bool inq[200050];
long long ans,snt;
long long get(vector<long long>&v)
{
    long long res=0;
    for(long long msk=(1LL<<v.size())-1LL;msk;--msk)
    {
        long long fac=1LL,one=0;
        for(long long i=1LL,j=v.size()-1LL;i<(1LL<<v.size());i<<=1LL,j--)
            if(msk&i)
            {
                fac*=v[j];
                ++one;
            }
        res+=(one&1LL?1LL:-1LL)*cnt[fac];
    }
    return res;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    for(long long i=2;i<500050;i++)
        for(long long j=i;j<500050;j+=i)
            frac[j].push_back(i);
    for(long long i=2;i<500050;i++)
        if(!vis[i])
            for(long long j=i;j<500050;j+=i) prifrac[j].push_back(i),vis[j]=true;
    cin>>n>>t;
    for(long long i=1LL;i<=n;i++) cin>>val[i];
    ans=snt=0;
    while(t--)
    {
        long long x;
        cin>>x;
        if(inq[x])
        {
            inq[x]=false;
            x=val[x];
            --snt;
            if(x==1LL) ans-=snt;
            else
            {
                for(auto dx:frac[x]) --cnt[dx];
                ans-=snt-get(prifrac[x]);
            }
        }else
        {
            inq[x]=true;
            x=val[x];
            if(x==1LL) ans+=snt;
            else
            {
                ans+=snt-get(prifrac[x]);
                for(auto dx:frac[x]) ++cnt[dx];
            }
            ++snt;
        }
        cout<<ans<<endl;
    }
}