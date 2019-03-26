#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Edge
{
	long long u, v, dist;
	Edge(long long U, long long V, long long D) : u(U), v(V), dist(D) {}
};

const int maxN = static_cast<int>(1e5) + 50;
const long long mod = static_cast<long long>(1e9) + 7;
vector<long long> G[maxN];
vector<Edge> edges;
long long fa[maxN], chid[maxN], value[maxN], Nl, ans;

long long dfs(long long f, long long u)
{
	fa[u] = f;
	for (long long i = 0; i < G[u].size(); i++)
	{
		Edge &e = edges[G[u][i]];
		if (e.v == f)
			continue;
		value[u] += dfs(u, e.v) + e.dist * (chid[e.v] + 1);
		value[u] %= mod;
		chid[u] += chid[e.v] + 1;
	}
	return value[u];
}

void dfs1(long long u, long long now_v, long long n)
{
	//cout << "            " << now_v << endl;
	for (long long i = 0; i < G[u].size(); i++)
	{
		Edge &e = edges[G[u][i]];
		if (e.v == fa[u])
			continue;
		long long next_v = (now_v - (value[e.v] + e.dist * (chid[e.v] + 1)));
		while (next_v < 0)
			next_v += mod;
		next_v += value[e.v] + e.dist * (n - 1 - chid[e.v]);
		next_v %= mod;
		ans += next_v * Nl;
		ans %= mod;
		dfs1(e.v, next_v, n);
	}
}

void solve(long long n)
{
	for (long long i = 0; i < n; i++)
		G[i] = vector<long long>();
	edges = vector<Edge>();
	memset(fa, 0, sizeof(fa));
	memset(value, 0, sizeof(value));
	memset(chid, 0, sizeof(chid));
	for (long long i = 0; i < n - 1; i++)
	{
		long long u_, v_, d_;
		scanf("%lld%lld%lld", &u_, &v_, &d_);
		--u_, --v_;
		G[u_].push_back(i * 2);
		edges.push_back(Edge(u_, v_, d_));
		G[v_].push_back(i * 2 + 1);
		edges.push_back(Edge(v_, u_, d_));
	}
	dfs(-1, 0);
	Nl = 1;
	for (long long i = 1; i < n; i++)
	{
		Nl *= i;
		Nl %= mod;
	}
	//cout << Nl << endl;
	//for (long long i = 0; i < n; i++)
		//cout << value[i] << ' ' << chid[i] << endl;
	ans = value[0] * Nl % mod;
	dfs1(0, value[0], n);
	printf("%lld\n", ans);
}

int main()
{
	long long n = 0;
	while (~scanf("%lld", &n))
		solve(n);
	return 0;
}
