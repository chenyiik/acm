#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int f(int n)
{
	if (n == 0) return 0;
	if (n == 10) return 1;
	if (n == 8) return 2;
	if (n == 26) return 3;
	if (n == 2) return 4;
	if (n == 14) return 5;
	if (n == 11) return 6;
	if (n == 31) return 7;
	return -1;
}

const int maxn = (1 << 16) + 5;
int ans[maxn], cnt[16];

int main()
{
	int n, x; scanf("%d", &n);
	puts("AND 1 2"); fflush(stdout); scanf("%d", &x);
	for (int i = 0; i < 16; i++) cnt[i] = cnt[i] << 1 | (x >> i & 1);
	puts("OR 1 2"); fflush(stdout); scanf("%d", &x);
	for (int i = 0; i < 16; i++) cnt[i] = cnt[i] << 1 | (x >> i & 1);
	puts("AND 1 3"); fflush(stdout); scanf("%d", &x);
	for (int i = 0; i < 16; i++) cnt[i] = cnt[i] << 1 | (x >> i & 1);
	puts("OR 1 3"); fflush(stdout); scanf("%d", &x);
	for (int i = 0; i < 16; i++) cnt[i] = cnt[i] << 1 | (x >> i & 1);
	puts("AND 2 3"); fflush(stdout); scanf("%d", &x);
	for (int i = 0; i < 16; i++) cnt[i] = cnt[i] << 1 | (x >> i & 1);
	return 0;
}
