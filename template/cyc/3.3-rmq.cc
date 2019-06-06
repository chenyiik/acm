#include "cyc.h"

const int maxn = 100000 + 10, maxlogn = 17 + 3;
int d[maxn][maxlogn];

void RMQ_init(const vector<int> &A)
{
	int n = A.size();
	for (int i = 0; i < n; i++)
		d[i][0] = A[i];
	for (int j = 1; (1 << j) <= n; j++)
		for (int i = 0; i + (1 << j) - 1 < n; i++)
			d[i][j] = min(d[i][j - 1], d[i + (1 << (j - 1))][j - 1]);
}

int RMQ(int L, int R) // find min in [L, R]
{
	int k = 0;
	while ((1 << (k + 1)) <= R - L + 1)
		k++;
	return min(d[L][k], d[R - (1 << k) + 1][k]);
}
