#include<bits/stdc++.h>
using namespace std;
__int128 m[505];
__int128 a[505];
__int128 n,mn;
void read(__int128 &x)
{
    char ch;x=0;
    while (ch=getchar(),!isdigit(ch));
    do {x=x*10+ch-'0';ch=getchar();}while (isdigit(ch));
}
void out(__int128 x)
{
    if (x<10) {putchar(x+'0');return;}
    out(x/10);
    putchar(x%10+'0');
}
__int128 gcd(__int128 x,__int128 y)
{
    return (y==0)?x:gcd(y,x%y);
}
__int128 exgcd(__int128 a,__int128 b,__int128 &x,__int128 &y)
{
    if (b==0) {x=1;y=0;return a;}
    __int128 r=exgcd(b,a%b,x,y);
    int t=x;x=y,y=t-y*(a/b);
    return r;
}

__int128 CRT(__int128 a[],__int128 m[],__int128 n)
{
    __int128 aa=a[0],mm=m[0];
    __int128 x,y;
    for (int i=1;i<n;i++)
    {
        __int128 d=exgcd(mm,m[i],x,y);
        __int128 c=a[i]-aa;
        if (c%d) return -1;
        __int128 mul=m[i]/d;
        x=(c/d*x%mul+mul)%mul;
        aa=aa+mm*x;
        mm=mm*mul;
        aa%=mm;
    }
    return (aa%mm+mm)%mm;
}
int main()
{
    read(n);read(mn);
    for (int i=0;i<n;i++) read(m[i]),read(a[i]);
    __int128 ans=CRT(a,m,n);
    if (ans<0) cout<<"he was definitely lying"<<endl;
    else if (ans>mn) cout<<"he was probably lying"<<endl;
    else {out(ans);puts("");}
}