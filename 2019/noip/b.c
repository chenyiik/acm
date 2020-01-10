#include <stdio.h>
#include <ctype.h>
#define maxn 500005
#define bn buf + maxn

long long f[maxn], ans;
int g[maxn], h[maxn], v[maxn], t[maxn], m;
char s[maxn], buf[maxn], *pc = bn - 1;

inline void rc() { if (++pc == bn) fread(buf, maxn, 1, stdin), pc = buf; }
inline void read(int *x) 
{
	while (!isdigit(*pc)) rc();
	while (isdigit(*pc)) { *x = *x * 10 + (*pc ^ 48); rc(); }
}


void dfs(int u, int fa)
{
	if ((s[u] & 1) == 0)
	{
		t[m++] = fa;
		ans ^= u * (f[u] = f[fa]);
		for (int i = h[u]; i; i = v[i])
			dfs(i, u);
		--m;
	}
	else if (m)
	{
		int tmp = t[--m];
		ans ^= u * (f[u] = f[fa] + (g[u] = g[tmp] + 1));
		for (int i = h[u]; i; i = v[i])
			dfs(i, u);
		t[m++] = tmp;
	}
	else
	{
		ans ^= u * (f[u] = f[fa]);
		for (int i = h[u]; i; i = v[i])
			dfs(i, u);
	}
}

int main()
{
	int n; scanf("%d%s", &n, s + 1);
	for (int i = 2; i <= n; i++)
	{
		int x = 0; read(&x);
		v[i] = h[x], h[x] = i;
	}
	dfs(1, 0);
	printf("%lld\n", ans);
	return 0;
}
