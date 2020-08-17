#include<bits/stdc++.h>
using namespace std;
struct task
{
    long long x,y,t,r;
    void get() {cin>>x>>t>>y>>r;}
    bool operator<(const task& b) const
    {
        return make_pair(x,y)<make_pair(b.x,b.y);
    }
};
vector<task> tasks;
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    long long n,s1,s2;
    cin>>n>>s1>>s2;
    tasks.resize(n);
    long long l1=0;
    for (long long i=0;i<n;i++)
    {
        tasks[i].get();
        l1=max(l1,tasks[i].x);
    }
    sort(tasks.begin(),tasks.end());
    static long long f[1050][1050];
    memset(f,0x3f,sizeof(f));
    f[0][0]=0;
    for (long long i=0;i<n;i++)
        for (long long j=s1+s2;j>=0;j--)
            for (long long k=s1+l1;k>=0;k--)
                if (f[j][k]!=0x3f3f3f3f3f3f3f3fLL)
                {
                    long long t1=j+tasks[i].x,t2=j+tasks[i].y,t3=k+tasks[i].x;
                    t1=min(t1,s1+s2);
                    t2=min(t2,s1+s2);
                    if (k<s1 && t3<1050)
                        f[t1][t3]=min(f[t1][t3],f[j][k]+tasks[i].t);
                    f[t2][k]=min(f[t2][k],f[j][k]+tasks[i].r);
                }
    long long ans=0x3f3f3f3f3f3f3f3fLL;
    for (long long i=s1;i<=s1+l1;i++) ans=min(ans,f[s1+s2][i]);
    if (ans<0x3f3f3f3f3f3f3f3fLL) cout<<ans<<endl;else cout<<-1<<endl;
}