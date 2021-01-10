#include<bits/stdc++.h>
using namespace std;
int c[400050];
int lowbit(int x)
{
    return x&(-x);
}
void add(int x,int d)
{
    if (x==0) return;
    for (int i=x;i<=400050;i+=lowbit(i)) c[i]+=d;
}
int sum(int p)
{
    if (p==0) return 0;
    int s=0;
    for (int i=p;i;i-=lowbit(i)) s+=c[i];
    return s;
}
int main()
{
    int n,m,q;
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m>>q;
    static string drink[200050];
    for (int i=1;i<=n;i++) cin>>drink[i];
    static map<string,int> alc;
    for (int i=1;i<=m;i++)
    {
        string s;int a;
        cin>>s>>a;
        alc[s]=a;
    }
    for (int i=1;i<=n;i++) add(i,alc[drink[i]]);
    while (q--)
    {
        int op;
        cin>>op;
        if (op==1)
        {
            int x;string n;
            cin>>x>>n;
            int r=sum(x)-sum(x-1);
            add(x,alc[n]-r);
        } else
        {
            int l,r;
            cin>>l>>r;
            int xp=(r-l+1)*30;
            if (sum(r)-sum(l-1)>xp)
                cout<<"YES"<<endl;
            else
                cout<<"NO"<<endl;
        }
    }
}