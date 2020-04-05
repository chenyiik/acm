#include<bits/stdc++.h>
using namespace std;
unsigned long long n,m,k;
unsigned long long num[15];
unsigned long long len;
unsigned long long res[100050<<1];
unordered_set<unsigned long long> vis;
const unsigned long long pr=402653189;
unsigned long long p[100050];
void dfs(unsigned long long x,unsigned long long val)
{
    if (vis.count(val)) return;
    if (x>=n) vis.insert(val);
    if (x==len)
    {
        for (unsigned long long i=0;i<len;i++) cout<<res[i];cout<<endl;
        exit(0);
    }
    for (unsigned long long i=1;i<=m;i++)
    {
        unsigned long long nval=val*pr+num[i]-(x>=n?res[x-n]*p[n]:0);
        res[x]=num[i];
        dfs(x+1,nval);
    }
    if (x>=n) vis.erase(val);
}
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m>>k;len=n+k-1;
    for (unsigned long long i=1;i<=m;i++) cin>>num[i];
    p[0]=1;
    for (unsigned long long i=1;i<=n;i++) p[i]=p[i-1]*pr;
    dfs(0,0);
}