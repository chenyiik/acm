#include<bits/stdc++.h>
using namespace std;
int n;
void read(int& p)
{
    char ch=getchar();int res=0;
    while (!isdigit(ch)) ch=getchar();
    while (isdigit(ch)) {res=res*10+ch-'0';ch=getchar();}
    p=res;
}
struct bintree
{
    int tree[3000050][2],cnt[3000050][2],val[3000050];
    int tot;
    void add(int x)
    {
        int cur=0;
        for(int i=29;i>=0;i--)
        {
            int y=(x>>i)&1;
            if(!tree[cur][y]) {tree[cur][y]=++tot;memset(tree[tot],0,sizeof(tree[tot]));cnt[cur][y]=0;}
            cnt[cur][y]++;
            cur=tree[cur][y];
        }
        val[cur]=x;
    }
    int query(int x)
    {
        int cur=0;
        for(int i=29;i>=0;i--)
        {
            int y=(x>>i)&1;
            if (cnt[cur][y]==0) y^=1;
            cur=tree[cur][y];
        }
        return val[cur];
    }
    void del(int x)
    {
        int cur=0;
        for(int i=29;i>=0;i--)
        {
            int y=(x>>i)&1;
            if (cnt[cur][y]==0) y^=1;
            cnt[cur][y]--;
            cur=tree[cur][y];
        }
    }
    void clear()
    {
        memset(tree[0],0,sizeof(tree[0]));
    }
};
bintree a,b;
multiset<int> a_raw;
int main()
{
    int T;
    read(T);
    while (T--)
    {
        read(n);
        a.tot=0,b.tot=0;
        a_raw.clear();
        a.clear(),b.clear();
        for (int i=1;i<=n;i++)
        {
            int x;
            read(x);
            a.add(x);
            a_raw.insert(x);
        }
        for (int i=1;i<=n;i++) {int x;read(x);b.add(x);}
        int u=*a_raw.begin(),v=b.query(u);
        vector<int> ans;
        while (ans.size()<n)
        {
            int v1=a.query(v);
            if (u==v1)
            {
                ans.push_back(u^v);
                a_raw.erase(a_raw.find(u));
                a.del(u);b.del(v);
                u=*a_raw.begin();
                v=b.query(u);
                continue;
            }
            u=v1;
            v=b.query(u);
        }
        sort(ans.begin(),ans.end());
        for (int i=0;i<n;i++) printf("%d%c",ans[i]," \n"[i==n-1]);
    }
}