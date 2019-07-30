#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = int(1e6) + 7;
int L[maxn], R[maxn];

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d", &L[i], &R[i]);
		R[i]++;
	}
	return 0;
}
