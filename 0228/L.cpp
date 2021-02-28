#include<bits/stdc++.h>
using namespace std;
constexpr bool dbg=false;
using ll=long long;
using ld=long double;
template<ll buffersz>
inline char igetchar()
{
    static char buf[buffersz],*p1=buf,*p2=buf;
    return p1==p2 && (p2=(p1=buf)+fread(buf,1,buffersz,stdin),p1==p2)?EOF:*p1++;
}
template<ll buffersz=(int)1e6,typename T>
void readint(T&x)
{
    x=0;ll f=0;
    char ch=igetchar<buffersz>();
    while(!isdigit(ch)) f|=(ch=='-'),ch=igetchar<buffersz>();
    while(isdigit(ch)) x=(x<<1)+(x<<3)+(ch^48),ch=igetchar<buffersz>();
    x=f?-x:x;
}
const int MAXN=(int)2e6;
int prime[MAXN+1];
void getp()
{
    for (int i=2;i<=MAXN;i++)
    {
        if (!prime[i]) prime[++prime[0]]=i;
        for (int j=1;j<=prime[0] && prime[j]<=MAXN/i;j++)
        {
            prime[prime[j]*i]=1;
            if (i%prime[j]==0) break;
        }
    }
}
int fcnt=0;
int cfac[10004][2];
int fac(int x)
{
    int tmp=x;
    for (int i=1;prime[i]<=tmp/prime[i];i++)
    {
        cfac[fcnt][1]=0;
        if (tmp%prime[i]==0)
        {
            cfac[fcnt][0]=prime[i];
            while (tmp%prime[i]==0) cfac[fcnt][1]++,tmp/=prime[i];
            ++fcnt;
        }
    }
    fcnt--;
    if (tmp!=1) {fcnt++;cfac[fcnt][0]=tmp,cfac[fcnt][1]=1;}
    return fcnt;
}
char sput[(int)1e7+7];
int cur=0;
#define putchar(x) (sput[cur++]=x)
void out(ll x)
{
    if (x>=10) out(x/10);
    putchar(x%10+'0');
}
ll fia[(int)2e6+1];
void proc()
{
    fcnt=0;
    int x;readint(x);
    fac(x);
    ll sm=1;
    if (fia[x]) sm=fia[x];
    else {for (int i=0;i<=fcnt;i++) sm*=cfac[i][1]+1;fia[x]=sm;}
    out(sm-(fcnt+1));putchar('\n');
}
int main()
{
    int q;readint(q);
    getp();
    while (q--) proc();
    sput[--cur]=0;
    puts(sput);
}
