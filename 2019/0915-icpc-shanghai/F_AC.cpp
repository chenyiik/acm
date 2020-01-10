#include<bits/stdc++.h>
using namespace std;
inline void read(__int128& x)
{
    int w=0;x=0;
    char ch=getchar();
    while (!isdigit(ch)) {w|=(ch=='-');ch=getchar();}
    while (isdigit(ch)) x=x*10+ch-'0',ch=getchar();
    if (w) x=-x;
}
void out(__int128 x)
{
    if (!x) return;
    if (x<0) putchar('-'),x=-x;
    out(x/10);
    putchar(x%10+'0');
}
using ll=__int128;
ll f[105][105];
inline int toint(char ch)
{
    return (ch-'A'+1);
}
int main()
{
    ll T;
    for (char ch='A';ch<='Z';ch++) f[toint(ch)][0]=1;
    f[toint('Z')][1]=26;
    for (char ch='Y';ch>='A';ch--) f[toint(ch)][1]=toint(ch)+1;
    for (int dep=2;dep<=26;dep++)
        for (char ch='Y';ch>='A';ch--)
            f[toint(ch)][dep]=__int128(toint(ch))*f[toint(ch)][dep-1]+f[toint(ch)+1][dep-1];
    read(T);
    int cas=0;
    while (T--)
    {
        __int128 n,k;
        read(n);read(k);
        printf("Case #%d: ",++cas);
        char mxn='A';
        static char s[105];
        for (int i=1;i<=n;i++)
        {
            s[i]='A';
            for (char ch='A';ch<='Z';ch++)
            {
                mxn=max(mxn,ch);
                if (k<=f[toint(mxn)][n-i])
                {
                    s[i]=ch;
                    break;
                }
                k-=f[toint(mxn)][n-i];
            }
        }
        s[n+1]='\0';
        puts(s+1);
    }
}
