#include<bits/stdc++.h>
using namespace std;
unordered_map<int,pair<int,int>> mp;
int mem[int(1e5)+50];
inline void scan(int &ret)
{
    char c;
    if (c=getchar(),c==EOF) return;
    while (!isdigit(c)) c=getchar();
    ret=c-'0';
    while (c=getchar(),isdigit(c)) ret=ret*10+(c-'0');
}
inline void outp(int x)
{
    if (x>=10) outp(x/10);
    putchar(char(x%10+'0'));
}
int main()
{
    int T;
    scan(T);
    while (T--)
    {
        mp.clear();
        int n,m,q;
        scan(n),scan(m),scan(q);
        memset(mem,0,sizeof(mem));
        for (int i=1;i<=n;i++)
        {
            int l,r;
            scan(l),scan(r);
            for (int x=l;x<=r;x++) mem[x]=1;
        }
        int maxblock=0;
        for (int i=m;i>=1;i--)
        {
            int tmp=0,last=0;
            if (mem[i]==0)
            {
                last=i;
                while (mem[i]==0 && i>=1)
                {
                    i--;tmp++;
                }
            }
            if (tmp>maxblock)
            {
                int needx=maxblock+1;
                for (int len=needx;len<=tmp;len++)
                {
                    int l=last-len+1,r=last;
                    mp[len]=make_pair(l,r);
                }
                maxblock=tmp;
            }
        }
        while (q--)
        {
            int len;
            scan(len);
            if (len>maxblock) {puts("-1 -1");continue;}
            outp(mp[len].first);putchar(' ');outp(mp[len].second);putchar('\n');
        }
    }
}