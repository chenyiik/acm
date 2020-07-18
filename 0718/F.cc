#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long LL;

const int maxn = int(2e6);
int prime[maxn + 1];

void init()
{	
	int m = int(sqrt(maxn + 0.5));
	for (int i = 2; i <= m; i++) if (prime[i] == 0)
		for (int j = i * i; j <= maxn; j += i) if (prime[j] == 0)
			prime[j] = i;
}

long long exgcd(long long a,long long b,long long &x,long long &y);
void calc(long long a,long long b,long long c,long long &x,long long &y);
int gcd(int a, int b) { return !b ? a : gcd(b, a % b); }

int main()
{
	init();
	int _; scanf("%d", &_);
	while (_--)
	{
		int a, b; scanf("%d%d", &a, &b);
		int ag = a / gcd(a, b), bg = b / gcd(a, b);
		if (b > 1 && bg == 1)
		{
			printf("%d %d %d %d\n", ag + 1, 1, 1, 1);
			continue;
		}
		if (prime[b] == 0)
		{
			puts("-1 -1 -1 -1");
			continue;
		}
		int d = 1, f = bg;
		while (prime[bg] && f % prime[bg] == 0)
			d *= prime[bg], f /= prime[bg];
		if (d == b)
		{
			puts("-1 -1 -1 -1");
			continue;
		}
		long long c, e;
		calc(f, d, ag, c, e);
		if (f == 1)
			e++, c += d;
		printf("%lld %d %lld %d\n", c, d, e, f);
	}
	return 0;
}

long long exgcd(long long a,long long b,long long &x,long long &y)
{
    if (b==0)
    {
        x=1,y=0;return a;
    }
    long long r=exgcd(b,a%b,x,y);
    long long tmp=x;x=y;y=tmp-(a/b)*y;
    return r;
}
void calc(long long a,long long b,long long c,long long &x,long long &y)
{
    long long g=exgcd(a,b,x,y);
    while (y>0)
    {
        x+=b/g;
        y-=a/g;
    }
    long long t=c/g;
    x=x*t,y=y*t;
    y=-y;
}
