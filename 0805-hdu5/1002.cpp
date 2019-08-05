#include<bits/stdc++.h>
using namespace std;
int a[100050],tree[3000050][2],cnt[3000050][2],val[3000050];
int vis[3000050];
int tot,n;
int cas=0;
struct xors
{
    int val;
    int xs;
    int raw;
    bool operator <(const xors& b) const
    {
        return xs<b.xs;
    }
};
xors c[100050];
void read(int& p)
{
    char ch=getchar();int res=0;
    while (!isdigit(ch)) ch=getchar();
    while (isdigit(ch)) {res=res*10+ch-'0';ch=getchar();}
    p=res;
}
void add(int x)
{
    int cur=0;
    for (int i=29;i>=0;i--)
    {
        if (vis[cur]!=cas) {cnt[cur][0]=cnt[cur][1]=0;vis[cur]=cas;}
        int y=(x>>i)&1;
        if (!tree[cur][y]) tree[cur][y]=++tot;
        cnt[cur][y]++;
        cur=tree[cur][y];
    }
    val[cur]=x;
}
int query(int x)
{
    int cur=0;
    for (int i=29;i>=0;i--)
    {
        int y=(x>>i)&1;
        //cout<<cur<<" "<<y<<endl;
        if (cnt[cur][y])
        {
            cnt[cur][y]--;
            cur=tree[cur][y];
        }
        else
        {
            cnt[cur][y^1]--;
            cur=tree[cur][y^1];
        }
    }
    return val[cur];
}
int query_nodel(int x)
{
    int cur=0;
    for (int i=29;i>=0;i--)
    {
        int y=(x>>i)&1;
        //cout<<cur<<" "<<y<<endl;
        if (cnt[cur][y])
        {
            //cnt[cur][y]--;
            cur=tree[cur][y];
        }
        else
        {
            //cnt[cur][y^1]--;
            cur=tree[cur][y^1];
        }
    }
    return val[cur];
}
struct tn
{
    int x,y,val;
    bool operator<(const tn& b) const
    {
        return val>b.val;
    }
};
void spec()
{
    priority_queue<tn> pq;
    int b[111];
    bool used[111];
    bool used2[111];
    memset(used,0,sizeof(used));
    memset(used2,0,sizeof(used2));
    for (int i=1;i<=n;i++) read(b[i]);
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++) {int val=a[i]^b[j];tn nn;nn.x=i;nn.y=j;nn.val=val;pq.push(nn);}
    int cx=0;
    while (!pq.empty())
    {
        auto x=pq.top();pq.pop();
        if (used[x.x]||used2[x.y]) continue;
        printf("%d ",x.val);
        cx++;
        used[x.x]=used2[x.y]=1;
        if (cx==n) break;
    }
    puts("");
}
int main()
{
    int T;
    read(T);
    while (T--)
    {
        ++cas;
        read(n);
        for (int i=1;i<=n;i++) read(a[i]);
        //if (n<=100) {spec();continue;}
        tot=0;
        for (int i=1;i<=n;i++)
        {
            int b;
            read(b);
            add(b);
        }
        for (int i=1;i<=n;i++) {c[i].raw=a[i];c[i].val=query_nodel(a[i]);c[i].xs=a[i]^c[i].val;}
        sort(c+1,c+n+1);
        for (int i=1;i<=n;i++)
        {
            printf("%d ",(c[i].raw^query(c[i].raw)));
        }
        puts("");
    }
}
