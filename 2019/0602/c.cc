#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

const int maxn = (int)1e5 + 10;

typedef double LD;

struct Double {
	static const LD eps;
	LD x;
	Double(LD y) : x(y) {}
	bool operator<(Double o) const { return x < o.x - eps; }
};

const LD Double::eps = 1e-10;

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int n, m = 1;
		long long ans = 0;
		scanf("%d", &n);
		map<Double, int> H;
		static map<Double, int> M[maxn];
		for (int i = 0; i <= n; i++)
			M[i].clear();
		for (int i = 0; i < n; i++)
		{
			int x1, x2, y1, y2;
			scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
			if (x2 == x1)
			{
				if (M[0].find(x1) == M[0].end())
					M[0][x1] = 0;
				ans += M[0][x1]++;
				continue;
			}
			Double k(LD(y2 - y1) * 1e9 / (x2 - x1));
			Double b(LD(y1 - y2) * x1 / (x2 - x1) + y1);
			//printf("%.15f %.15f\n", k.x, b.x);
			if (H.find(k) == H.end())
				H[k] = m++;
			int j = H[k];
			if (M[j].find(b) == M[j].end())
				M[j][b] = 0;
			ans += M[j][b]++;
		}
		long long bns = 0;
		for (int i = 0; i < m; i++)
		{
			long long cns = 0;
			for (auto j : M[i])
				cns += j.second;
			bns += cns * (n - cns);
			//cout << M[i].size() << endl;
		}
		//cout << ans << ' ' << bns << endl;
		printf("%lld\n", ans + bns / 2);
	}
	return 0;
}
