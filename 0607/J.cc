#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

int g(int n) { return n * (n + 1) / 2; }

int f(int n)
{
	int m = sqrt(n * 2 + 1e-3);
	return n == g(m) ? m : -1;
}

const int maxn = int(1e6);
char s[maxn], *p = s;

int main()
{
	int a, b, c, d; scanf("%d%d%d%d", &a, &b, &c, &d);
	int zero = f(a), one = f(d);
	if (zero++ == -1 || one++ == -1) return puts("impossible"), 0;
	if (zero * one == b + c) ;
	else if (zero == 1 && (zero - 1) * one == b + c) zero--;
	else if (one == 1 && zero * (one - 1) == b + c) one--;
	else return puts("impossible"), 0;
	while (zero && one)
		if (c >= zero) *(p++) = '1', one--, c -= zero;
		else *(p++) = '0', zero--;
	while (zero--) *(p++) = '0';
	while (one--) *(p++) = '1';
	puts(s);
	return 0;
}
