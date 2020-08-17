#include<bits/stdc++.h>
using namespace std;
int main()
{
    static int r[100050],c[100050];
    int n,q;
    scanf("%d%d",&n,&q);
    for (int i=1;i<=n;i++)
    {
        int tmp;
        scanf("%d",&tmp);
        r[i]=tmp&1;
        r[i]+=r[i-1];
    }
    for (int i=1;i<=n;i++)
    {
        int tmp;
        scanf("%d",&tmp);
        c[i]=tmp&1;
        c[i]+=c[i-1];
    }
    while (q--)
    {
        int r1,c1,r2,c2;
        scanf("%d%d%d%d",&r1,&c1,&r2,&c2);
        if (r1>r2) swap(r1,r2);
        if (c1>c2) swap(c1,c2);
        auto s1=r[r2]-r[r1-1],s2=c[c2]-c[c1-1];
        bool flag=true;
        flag=flag && ((s1==0)||(s1==r2-r1+1));
        flag=flag && ((s2==0)||(s2==c2-c1+1));
        puts(flag?"YES":"NO");
    }
}