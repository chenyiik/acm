#include<bits/stdc++.h>
using namespace std;
int f[500050][32],pos[500050][32];
void read(int& res)
{
    res=0;char ch=getchar();
    while (!isdigit(ch)) ch=getchar();
    while (isdigit(ch)) res=res*10+ch-48,ch=getchar();
}
void add(int id,int x)
{
    int k=id;
    for (int i=30;i>=0;i--) f[id][i]=f[id-1][i],pos[id][i]=pos[id-1][i];
    for (int i=30;i>=0;i--)
        if ((x>>i)&1)
        {
            if (!f[id][i])
            {
                f[id][i]=x;
                pos[id][i]=k;
                return;
            }
            else
            {
                if (k>pos[id][i])
                {
                    swap(x,f[id][i]);
                    swap(k,pos[id][i]);
                }
                x^=f[id][i];
            }
        }
}
int calc(int l,int r)
{
    int ans=0;
    for (int i=30;i>=0;i--)
        if (pos[r][i]>=l && (ans^f[r][i])>ans) ans=ans^f[r][i];
    return ans;
}
int main()
{
    int T;
    read(T);
    while (T--)
    {
        memset(f,0,sizeof(f));memset(pos,0,sizeof(pos));
        int n,m;
        read(n),read(m);
        for (int i=1;i<=n;i++)
        {
            int x;
            read(x);
            add(i,x);
        }
        int lastans=0;
        while (m--)
        {
            int op;
            read(op);
            if (op==0)
            {
                int l,r;
                read(l),read(r);
                l=(l^lastans)%n+1;
                r=(r^lastans)%n+1;
                if (l>r) swap(l,r);
                printf("%d\n",lastans=calc(l,r));
            }
            else
            {
                int x;
                read(x);
                x=(x^lastans);
                add(++n,x);
            }
        }
    }
}