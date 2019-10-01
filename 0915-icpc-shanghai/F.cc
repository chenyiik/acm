#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

typedef unsigned long long LL;
void read(__int128& x);
void out(__int128 x);

__int128 f[200][30];
void init()
{
	for (char c = 'A'; c <= 'Z'; c++)
		f[c][1] = 1;
	for (int i = 2; i <= 26; i++)
		for (char c = 'A'; c <= 'Z' - i + 1; c++)
		//{
			f[c][i] = f[c][i - 1] * (c - 'A' + 1) + f[c + 1][i - 1];
			//out(f[c][i]), puts("");
		//}
}

LL solve(LL n, LL k)
{
}

int main()
{
	init();
	int __; scanf("%d", &__);
	for (int _ = 1; _ <= __; _++)
	{
		LL n; scanf("%lld", &n);
		__int128 k; read(k);
		printf("Case %d: %lld\n", _, solve(n, k));
	}
	return 0;
}

void read(__int128& x)
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
