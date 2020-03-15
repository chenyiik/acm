#include<bits/stdc++.h>
using namespace std;
int c[1000050<<1],a[100050];
inline int lowbit(int x)
{
    return x&(-x);
}
void add(int x,int d)
{
    for(;x<1000050<<1;x+=lowbit(x)) c[x]+=d;
}
int get(int x)
{
    int ans=0;
    for(;x;x-=lowbit(x)) ans+=c[x];
    return ans;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    memset(c,0,sizeof(c));
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        ++a[i];
        cout<<n-(i-get(a[i]-1))+1<<endl;
        add(a[i],1);
    }
}