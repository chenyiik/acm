#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

//const int W = 0, R = 1, B = 2;
const int maxN = static_cast<int>(1e5 + 7);
int nxt[maxN], value[maxN]; //, color[maxN];
bool label = false;
enum { W, R, B } color[maxN];

int dfs(int u, int cnt)
{
	if (color[u] == B)
		return value[u];
	if (color[u] == R)
	{
		color[u] = B;
		label = true;
		return value[u] = cnt - value[u];
	}
	color[u] = R;
	value[u] = cnt;
	value[u] = dfs(nxt[u], cnt + 1);
	if (!label)
		value[u]++;
	if (color[u] == B)
		label = false;
	else
		color[u] = B;
	return value[u];
}

int main()
{
	int n = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &nxt[i]);
	memset(color, W, sizeof(color));
	for (int i = 1; i <= n; i++)
		printf("%d\n", dfs(i, 0));
	return 0;
}
