#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

void func(map<int, int> &M, int &k, int d)
{
	k -= d;
	int v = M.begin()->first, s = M.begin()->second;
	M.erase(M.begin());
	if (s - d % s) M[v + d / s] = M[v + d / s] + (s - d % s);
	if (d % s) M[v + d / s + 1] = M[v + d / s + 1] + d % s;
	v = M.rbegin()->first, s = M.rbegin()->second;
	M.erase(--M.end());
	if (s - d % s) M[v - d / s] = M[v - d / s] + (s - d % s);
	if (d % s) M[v - d / s - 1] = M[v - d / s - 1] + d % s;
}

int main()
{
	for (int n, k; ~scanf("%d%d", &n, &k); )
	{
		map<int, int> M;
		for (int i = 0; i < n; i++)
		{
			int x; scanf("%d", &x);
			if (M.find(x) == M.end())
				M[x] = 1;
			else
				M[x]++;
		}
		while (k > 0 && M.size() > 2)
		{
			auto L1 = M.begin(), L0 = L1++; auto R1 = M.rbegin(), R0 = R1++;
			int ld = L1->first - L0->first, rd = R0->first - R1->first;
			int d = min(k, min(ld * L0->second, rd * R0->second));
			func(M, k, d);
		}
		if (k > 0 && M.size() > 1 && M.begin()->first + 1 < M.rbegin()->first)
		{
			int v = M.begin()->first * M.begin()->second 
				+ M.rbegin()->first * M.rbegin()->second;
			int d = M.begin()->second + M.rbegin()->second;
			int u = v / d, a = d - v % d;
			if (M.begin()->second <= a)
				d = M.begin()->second * (u - M.begin()->first);
			else
				d = a * (u - M.begin()->first) 
					+ (M.begin()->second - a) * (u + 1 - M.begin()->first);
			d = min(k, d);
			func(M, k, d);
		}
		printf("%d\n", M.rbegin()->first - M.begin()->first);
	}
	return 0;
}
