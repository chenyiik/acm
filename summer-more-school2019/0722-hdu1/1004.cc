#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = int(1e5) + 5;
double L[maxn], S[maxn], V[maxn], A[maxn], T[maxn];

int main()
{
	int n;
	while (~scanf("%d", &n))
	{
		for (int i = 0; i <= n; i++)
			scanf("%lf", &L[i]);
		for (int i = 0; i <= n; i++)
			scanf("%lf", &S[i]);
		for (int i = 0; i <= n; i++)
			scanf("%lf", &V[i]);
		A[0] = 0.0;
		for (int i = 1; i <= n; i++)
			A[i] = A[i - 1] + L[i];
		T[n] = (S[n] + A[n]) / V[n];
		for (int i = n - 1; i >= 0; i--)
			T[i] = max(T[i + 1], (S[i] + A[i]) / V[i]);
		printf("%.10f\n", T[0]);
	}
	return 0;
}
