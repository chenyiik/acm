#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int maxN = static_cast<int>(3e5) + 7;
struct P { int v, l, r, p; } a[maxN];
int L[maxN], R[maxN];
bool vis[maxN];

void show(int n);

int main()
{
	int n = 0;
	scanf("%d", &n);
	memset(L, -1, sizeof(L));
	memset(R, -1, sizeof(R));
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i].v);
		if (L[a[i].v] == -1)
		{
			L[a[i].v] = i;
			a[i].l = -1;
		}
		else
		{
			a[i].l = R[a[i].v];
			a[a[i].l].r = i;
		}
		R[a[i].v] = i;
		a[i].r = n;
		a[i].p = i + 1;
	}
	int m = 0;
	scanf("%d", &m);
	while (m--)
	{
		int x = 0;
		scanf("%d", &x);
		if (vis[x])
			continue;
		vis[x] = true;
		if (L[x] == R[x])
			continue;
		for (int i = L[x] + 1; i < R[x]; )
		{
			int y = a[i].v;
			if (L[y] == R[y])
				L[y] = R[y] = -1;
			else if (i == L[y])
			{
				L[y] = a[i].r;
				a[L[y]].l = -1;
			}
			else if (i == R[y])
			{
				R[y] = a[i].l;
				a[R[y]].r = n;
			}
			else
			{
				a[a[i].l].r = a[i].r;
				a[a[i].r].l = a[i].l;
			}
			i = a[i].p;
		}
		a[L[x]].p = R[x] + 1;
		a[L[x]].r = n;
		R[x] = L[x];
	}
	for (int i = 0; i < n; )
		for (int c = a[i].v, d = a[i].p; i < d; i++)
			printf("%d%c", c, " \n"[i + 1 == n]);
	return 0;
}
