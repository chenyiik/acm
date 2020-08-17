#include<bits/stdc++.h>
using namespace std;
using ull=unsigned long long;
inline ull read(ull &x)
{
    char ch;
    x=0;
    while(ch=getchar(),!isdigit(ch));
    do{x=x*10+ch-'0';}while(ch=getchar(),isdigit(ch));
}
ull a[100050],b[100050];
ull sum[3];
ull k1,k2,mod;
ull rng()
{
    ull k3=k1,k4=k2;
    k1=k4;
    k3^=k3<<23;
    k2=k3^k4^(k3>>17)^(k4>>26);
    return k2+k4;
}
ull id=0;
unordered_map<ull,ull> mp;
ull gain(ull raw)
{
    if (!mp.count(raw)) mp[raw]=++id;
    return mp[raw];
}
ull pock[3][200050];
vector<ull> conf[200050];
inline ull next(ull now)
{
    if (now&1) return now+1;
    return now-1;
}
int main()
{
    ull t;
    read(t);
    while(t--)
    {
        for (int i=1;i<=id;i++) pock[1][i]=pock[2][i]=0;
        id=0;mp.clear();
        ull n,m,way;
        read(n);sum[1]=n;
        read(m);sum[2]=m;
        read(way);
        if(way==1)
        {
            for(ull i=1;i<=n;i++) {read(a[i]);pock[1][gain(a[i])]++;}
            for(ull i=1;i<=m;i++) {read(b[i]);pock[2][gain(b[i])]++;}
        }
        else
        {
            read(k1);
            read(k2);
            read(mod);
            for(ull i=1;i<=n;i++)
            {
                a[i]=rng()%mod;
                pock[1][gain(a[i])]++;
            }
            read(k1);
            read(k2);
            read(mod);
            for(ull i=1;i<=m;i++)
            {
                b[i]=rng()%mod;
                pock[2][gain(b[i])]++;
            }
        }
        ull maxn=0;
        for (ull i=1;i<=id;i++)
        if (pock[1][i]&&pock[2][i])
        {
            sum[1]-=pock[1][i];
            sum[2]-=pock[2][i];
            ull cl=pock[1][i]+pock[2][i];
            conf[cl].push_back(pock[1][i]);
            maxn=max(cl,maxn);
        }
        ull now=1;
        for (ull i=maxn;i>=1;i--)
        {
            for (auto v:conf[i])
            {
                if (now==1) sum[1]+=v;else sum[2]+=i-v;
                now=next(now);
            }
            conf[i].clear();
        }
        if (sum[1]>sum[2]) puts("Cuber QQ");else puts("Quber CC");
    }
}