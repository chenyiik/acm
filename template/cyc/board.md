#ACM Board

#####CHEN Yiik

#####v1.1

***



## vim .vimrc

####nm \<f5> :w\<cr>:!g++ % -o %< -Wall -std=c++11 && ./%<\<cr>

####nm \<f6> :w\<cr>:!python3 %\<cr>

####se ai cin ts=4 sw=4 nu cul

#### nm 0 ^

####colo t*

####nm \<f3> ggVG”+y

------



## gvim _vimrc

####nm \<f5> :w\<cr>:!g++ % -o %< -Wall -std=c++11 && %<\<cr>

####nm \<f6> :w\<cr>:!python3 %\<cr>

####se nocp bs=indent,eol,start ai cin ts=4 sw=4 nu ru cul

#### nm 0 ^

####syntax on

####colo t*

####nm \<f3> ggVG”+y

------







### 1.1 - prime

```c++
const int maxn = 10000000 + 10, maxp = 700000;
bool is_p[maxn]; //is_p[i] == true when i is 1 or a prime
int prime[maxp], pn = 0;

void prime_table(int n)
{
	for (int i = 2; i <= n; i++)
	{
		if (!is_p[i])
			prime[pn++] = i;
		for (int j = 0; j < pn && i * prime[j] <= n; j++)
		{
			is_p[i * prime[j]] = true;
			if (i % prime[j] == 0)
				break;
		}
	}
}
```



### 1.2 - gcd - inv

```c++
LL gcd(LL a, LL b) { return !b ? a : gcd(b, a % b); }

void gcd(LL a, LL b, LL &d, LL &x, LL &y)
{
	if (!b)
		d = a, x = 1, y = 0;
	else
	{
		gcd(b, a % b, d, y, x);
		y -= x * (a / b);
	}
}

LL inv(LL a, LL n) // inv don't exist when it return -1
{
	LL d, x, y;
	gcd(a, n, d, x, y);
	return d == 1 ? (x + n) % n : -1;
}
```



###1.3 - pow - inv

```c++
LL pow_mod(LL a, LL p, LL n)
{
	if (p == 0)
		return 1;
	LL ans = pow_mod(a, p / 2, n);
	ans = ans * ans % n;
	if (p % 2 == 1)
		ans = ans * a % n;
	return ans;
}

LL inv(LL a, LL n) { return pow_mod(a, n - 2, n); } // when n is a prime
```



### 1.4 - eulerphi

```c++
int euler_phi(int n)
{
	int m = (int)sqrt(n + 0.5);
	int ans = n;
	for (int i = 2; i <= m; i++)
		if (n % i == 0)
		{
			ans = ans / i * (i - 1);
			while (n % i == 0)
				n /= i;
		}
	if (n > 1)
		ans = ans / n * (n - 1);
	return ans;
}

const int maxn = 10000000 + 10, maxp = int(7e5);
int phi[maxn], prime[maxp], pn = 0;
bool is_p[maxn + 5];

void phi_table(int n)
{
	phi[1] = 1;
	for (int i = 2; i <= n; i++)
		phi[i] = 0;
	for (int i = 2; i <= n; i++)
	{
		if (!is_p[i])
		{
			prime[pn++] = i;
			phi[i] = i - 1;
		}
		for (int j = 0; j < pn && i * prime[j] <= n; j++)
		{
			is_p[i * prime[j]] = true;
			if (i % prime[j] == 0)
				phi[i * prime[j]] = phi[i] * prime[j], j = pn;
			else
				phi[i * prime[j]] = phi[i] * (prime[j] - 1);
		}
	}
}
```



### 1.5 - mo

```c++
const int maxn = 10000000 + 10, maxp = 700000;
bool is_p[maxn]; //is_p[i] == true when i is 1 or a prime
int mo[maxn], prime[maxp], pn = 0;

void prime_table(int n)
{
	mo[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		if (!is_p[i])
		{
			prime[pn++] = i;
			mo[i] = -1;
		}
		for (int j = 0; j < pn && i * prime[j] <= n; j++)
		{
			is_p[i * prime[j]] = true;
			if (i % prime[j] == 0)
				break;
			else
				mo[i * prime[j]] = -mo[i];
		}
	}
}
```



### 2.1 - sssp

```c++
const int maxn = 100000 + 10;

struct Edge { int from, to, dist; };

struct HeapNode
{
	int d, u;
	bool operator<(const HeapNode &rhs) const { return d > rhs.d; }
};

struct Dijkstra
{
	int n, m;
	vector<Edge> edges;
	vector<int> G[maxn];
	bool done[maxn];
	int d[maxn];
	int p[maxn];

	void init(int n)
	{
		this->n = n;
		for (int i = 0; i < n; i++)
			G[i].clear();
		edges.clear();
	}

	void AddEdge(int from, int to, int dist)
	{
		edges.push_back((Edge){from , to, dist});
		m = edges.size();
		G[from].push_back(m - 1);
	}

	void dijkstra(int s)
	{
		priority_queue<HeapNode> Q;
		for (int i = 0; i < n; i++)
			d[i] = oo;
		d[s] = 0;
		memset(done, 0, sizeof(done));
		Q.push((HeapNode){0, s});
		while (!Q.empty())
		{
			HeapNode x = Q.top();
			Q.pop();
			int u = x.u;
			if (done[u])
				continue;
			done[u] = true;
			for (int i = 0; i < G[u].size(); i++)
			{
				Edge &e = edges[G[u][i]];
				if (d[e.to] > d[u] + e.dist)
				{
					d[e.to] = d[u] + e.dist;
					p[e.to] = G[u][i];
					Q.push((HeapNode){d[e.to], e.to});
				}
			}
		}
	}
};

struct BellmanFord
{
	int n, m;
	vector<Edge> edges;
	vector<int> G[maxn];
	bool inq[maxn];
	int d[maxn];
	int p[maxn];
	int cnt[maxn];

	void init(int n)
	{
		this->n = n;
		for (int i = 0; i < n; i++)
			G[i].clear();
		edges.clear();
	}

	void AddEdge(int from, int to, int dist)
	{
		edges.push_back((Edge){from, to, dist});
		m = edges.size();
		G[from].push_back(m - 1);
	}

	bool negativeCycle()
	{
		queue<int> Q;
		memset(inq, 0, sizeof(inq));
		memset(cnt, 0, sizeof(cnt));
		for (int i = 0; i < n; i++)
		{
			d[i] = 0;
			inq[0] = true;
			Q.push(i);
		}

		while (!Q.empty())
		{
			int u = Q.front();
			Q.pop();
			inq[u] = false;
			for (int i = 0; i < G[u].size(); i++)
			{
				Edge &e = edges[G[u][i]];
				if (d[e.to] > d[u] + e.dist)
				{
					d[e.to] = d[u] + e.dist;
					p[e.to] = G[u][i];
					if (!inq[e.to])
					{
						Q.push(e.to);
						inq[e.to] = true;
						if (++cnt[e.to] > n)
							return true;
					}
				}
			}
		}
		return false;
	}
};
```



### 2.2 - scc

```c++
const int maxn = 1000000 + 10;

vector<int> G[maxn];
int pre[maxn], lowlink[maxn], sccno[maxn], dfs_clock, scc_cnt;
stack<int> S;

void dfs(int u)
{
	pre[u] = lowlink[u] = ++dfs_clock;
	S.push(u);
	for (int i = 0; i < G[u].size(); i++)
	{
		int v = G[u][i];
		if (!pre[v])
		{
			dfs(v);
			lowlink[u] = min(lowlink[u], lowlink[v]);
		}
		else if (!sccno[v])
			lowlink[u] = min(lowlink[u], pre[v]);
	}
	if (lowlink[u] == pre[u])
	{
		scc_cnt++;
		for ( ; ; )
		{
			int x = S.top();
			S.pop();
			sccno[x] = scc_cnt;
			if (x == u)
				break;
		}
	}
}

void find_scc(int n)
{
	dfs_clock = scc_cnt = 0;
	memset(sccno, 0, sizeof(sccno));
	memset(pre, 0, sizeof(pre));
	for (int i = 0; i < n; i++)
		if (!pre[i])
			dfs(i);
}
```



### 2.3 - dinic

```c++
const int maxn = 100 + 10;

struct Edge { int from, to, cap, flow; };

struct Dinic
{
	int n, m, s, t;
	vector<Edge> edges;
	vector<int> G[maxn];
	bool vis[maxn];
	int d[maxn];
	int cur[maxn];
	
	void AddEdge(int from, int to, int cap)
	{
		edges.push_back((Edge){from, to, cap, 0});
		edges.push_back((Edge){to, from, 0, 0});
		m = edges.size();
		G[from].push_back(m - 2);
		G[to].push_back(m - 1);
	}

	bool BFS()
	{
		memset(vis, 0, sizeof(vis));
		queue<int> Q;
		Q.push(s);
		d[s] = 0;
		vis[s] = 1;
		while (!Q.empty())
		{
			int x = Q.front();
			Q.pop();
			for (int i = 0; i < G[x].size(); i++)
			{
				Edge &e = edges[G[x][i]];
				if (!vis[e.to] && e.cap > e.flow)
				{
					vis[e.to] = 1;
					d[e.to] = d[x] + 1;
					Q.push(e.to);
				}
			}
		}
		return vis[t];
	}

	int DFS(int x, int a)
	{
		if (x == t || a == 0)
			return a;
		int flow = 0, f;
		for (int &i = cur[x]; i < G[x].size(); i++)
		{
			Edge &e = edges[G[x][i]];
			if (d[x] + 1 == d[e.to] && (f = DFS(e.to, min(a, e.cap - e.flow))) > 0)
			{
				e.flow += f;
				edges[G[x][i] ^ 1].flow -= f;
				flow += f;
				a -= f;
				if (a == 0)
					break;
			}
		}
		return flow;
	}

	int Maxflow(int s, int t)
	{
		this->s = s;
		this->t = t;
		int flow = 0;
		while (BFS())
		{
			memset(cur, 0, sizeof(cur));
			flow += DFS(s, oo);
		}
		return flow;
	}
};
```



### 2.4 - mincost

```c++
struct Edge
{
	int from, to, cap, flow, cost;
	Edge(int u, int v, int c, int f, int w)
		: from(u), to(v), cap(c), flow(f), cost(w) {}
};

struct MCMF
{
	static const int maxn = 100;
	int n, m;
	vector<Edge> edges;
	vector<int> G[maxn];
	int inq[maxn], d[maxn], p[maxn], a[maxn];
	
	void init(int n)
	{
		this->n = n;
		for (int i = 0; i < n; i++)
			G[i].clear();
		edges.clear();
	}

	void AddEdge(int from, int to, int cap, int cost)
	{
		edges.push_back(Edge(from, to, cap, 0, cost));
		edges.push_back(Edge(to, from, 0, 0, -cost));
		m = edges.size();
		G[from].push_back(m - 2);
		G[to].push_back(m - 1);
	}

	bool BellmanFord(int s, int t, int &flow, long long &cost)
	{
		for (int i = 0; i < n; i++)
			d[i] = +oo;
		memset(inq, 0, sizeof(inq));
		d[s] = 0;
		inq[s] = 1;
		p[s] = 0;
		a[s] = +oo;

		queue<int> Q;
		Q.push(s);
		while (!Q.empty())
		{
			int u = Q.front();
			Q.pop();
			inq[u] = 0;
			for (int i = 0; i < G[u].size(); i++)
			{
				Edge &e = edges[G[u][i]];
				if (e.cap > e.flow && d[e.to] > d[u] + e.cost)
				{
					d[e.to] = d[u] + e.cost;
					p[e.to] = G[u][i];
					a[e.to] = min(a[u], e.cap - e.flow);
					if (!inq[e.to])
					{
						Q.push(e.to);
						inq[e.to] = 1;
					}
				}
			}
		}
		if (d[t] == +oo)
			return false;
		flow += a[t];
		cost += (long long)d[t] * (long long)a[t];
		for (int u = t; u != s; u = edges[p[u]].from)
		{
			edges[p[u]].flow += a[t];
			edges[p[u] ^ 1].flow -= a[t];
		}
		return true;
	}

	int MincostMaxflow(int s, int t, long long &cost)
	{
		int flow = 0;
		cost = 0;
		while (BellmanFord(s, t, flow, cost))
			;
		return flow;
	}
};
```



### 2.5 - kruscal

```c++
const int maxn = 10000 + 10;
const int maxm = 100000 + 10;
int p[maxn], u[maxm], v[maxm], w[maxm], r[maxm];
int n, m;

bool cmp(int i, int j) { return w[i] < w[j]; }
int find(int x) { return p[x] == x ? x : p[x] = find(p[x]); }

int kruscal()
{
	int ans = 0;
	for (int i = 0; i < n; i++) 
		p[i] = i;
	for (int i = 0; i < m; i++) 
		r[i] = i;
	sort(r, r + m);
	for (int i = 0; i < m; i++)
	{
		int e = r[i], x = find(u[e]), y = find(v[e]);
		if (x != y)
		{
			ans += w[e];
			p[x] = y;
		}
	}
	return ans;
}
```



### 3.1 - lca

```c++
const int maxv = 1000000 + 10;
const int maxlogv = 27;

vector<int> G[maxv];
int root;

int parent[maxlogv][maxv];
int depth[maxv];

void dfs(int v, int p, int d)
{
	parent[0][v] = p;
	depth[v] = d;
	for (int i = 0; i < G[v].size(); i++)
		if (G[v][i] != p)
			dfs(G[v][i], v, d + 1);
}

void init(int V)
{
	dfs(root, -1, 0);
	for (int k = 0; k + 1 < maxlogv; k++)
		for (int v = 0; v < V; v++)
			if (parent[k][v] < 0)
				parent[k + 1][v] = -1;
			else
				parent[k + 1][v] = parent[k][parent[k][v]];
}

int lca(int u, int v)
{
	if (depth[u] > depth[v])
		swap(u, v);
	for (int k = 0; k < maxlogv; k++)
		if ((depth[v] - depth[u]) >> k & 1)
			v = parent[k][v];
	if (u == v)
		return u;
	for (int k = maxlogv - 1; k >= 0; k--)
		if (parent[k][u] != parent[k][v])
		{
			u = parent[k][u];
			v = parent[k][v];
		}
	return parent[0][u];
}
```



### 3.2 - bit

```c++
const int maxn = 100000 + 10;
int C[maxn], n; //from 1 to n

int lowbit(int x) { return x & -x; }

int sum(int x)
{
	int ret = 0;
	while (x > 0)
	{
		ret += C[x];
		x -= lowbit(x);
	}
	return ret;
}

void add(int x, int d)
{
	while (x <= n)
	{
		C[x] += d;
		x += lowbit(x);
	}
}
```



### 3.3 - rmq

```c++
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
```



### 3.4.1 - segtree

```c++
//node update

const int maxn = 200000 + 10;
int minv[maxn];

int ql, qr; 

int query(int o, int L, int R) //get min in [ql, qr]
{
	int M = L + (R - L) / 2, ans = +oo;
	if (ql <= L && R <= qr)
		return minv[o];
	if (ql <= M)
		ans = min(ans, query(o * 2, L, M));
	if (M < qr)
		ans = min(ans, query(o * 2 + 1, M + 1, R));
	return ans;
}

int p, v; 

void update(int o, int L, int R) //let A[p] = v;
{
	int M = L + (R - L) / 2;
	if (L == R)
		minv[o] = v;
	else
	{
		if (p <= M)
			update(o * 2, L, M);
		else
			update(o * 2 + 1, M + 1, R);
		minv[o] = min(minv[o * 2], minv[o * 2 + 1]);
	}
}
```



### 3.4.2 - segtree

```c++
//segment add

const int maxn = 200000 + 10;
int minv[maxn], maxv[maxn], sumv[maxn], addv[maxn];

void maintain(int o, int L, int R)
{
	int lc = o * 2, rc = o * 2 + 1;
	sumv[o] = minv[o] = maxv[o] = 0;
	if (R > L)
	{
		sumv[o] = sumv[lc] + sumv[rc];
		minv[o] = min(minv[lc], minv[rc]);
		maxv[o] = max(maxv[lc], maxv[rc]);
	}
	minv[o] += addv[o];
	maxv[o] += addv[o];
	sumv[o] += addv[o] * (R - L + 1);
}

int ql, qr, v;

void update(int o, int L, int R) //let [ql, qr] add v;
{
	int lc = o * 2, rc = o * 2 + 1;
	if (ql <= L && qr >= R)
		addv[o] += v;
	else
	{
		int M = L + (R - L) / 2;
		if (ql <= M)
			update(lc, L, M);
		if (qr > M)
			update(rc, M + 1, R);
	}
	maintain(o, L, R);
}

int _min, _max, _sum;

void query(int o, int L, int R, int add) //get min, max, sum in [ql, qr]
{
	if (ql <= L && qr >= R)
	{
		_sum += sumv[o] + add * (R - L + 1);
		_min = min(_min, minv[o] + add);
		_max = max(_max, maxv[o] + add);
	}
	else
	{
		int M = L + (R - L) / 2;
		if (ql <= M)
			query(o * 2, L, M, add + addv[o]);
		if (qr > M)
			query(o * 2 + 1, M + 1, R, add + addv[o]);
	}
}
```



### 3.4.3 - segtree

```c++
//segment set

const int maxn = 200000 + 10;
int minv[maxn], maxv[maxn], sumv[maxn], setv[maxn];

void maintain(int o, int L, int R)
{
	int lc = o * 2, rc = o * 2 + 1;
	sumv[o] = minv[o] = maxv[o] = 0;
	if (R > L)
	{
		sumv[o] = sumv[lc] + sumv[rc];
		minv[o] = min(minv[lc], minv[rc]);
		maxv[o] = max(maxv[lc], maxv[rc]);
	}
	minv[o] = setv[o];
	maxv[o] = setv[o];
	sumv[o] = setv[o] * (R - L + 1);
}

void pushdown(int o)
{
	int lc = o * 2, rc = o * 2 + 1;
	if (setv[o] >= 0)
	{
		setv[lc] = setv[rc] = setv[o];
		setv[o] = -1; // no mark
	}
}

int ql, qr, v;

void update(int o, int L, int R) //let [ql, qr] add v;
{
	int lc = o * 2, rc = o * 2 + 1;
	if (ql <= L && qr >= R)
		setv[o] = v;
	else
	{
		pushdown(o);
		int M = L + (R - L) / 2;
		if (ql <= M)
			update(lc, L, M);
		if (qr > M)
			update(rc, M + 1, R);
	}
	maintain(o, L, R);
}

int _min, _max, _sum;

void query(int o, int L, int R) //get min, max, sum in [ql, qr]
{
	if (setv[o] >= 0)
	{
		_sum += setv[o] * (min(R, qr) - max(L, ql) + 1);
		_min = min(_min, setv[o]);
		_max = max(_max, setv[o]);
	}
	else if (ql <= L && qr >= R)
	{
		_sum += sumv[o];
		_min = min(_min, minv[o]);
		_max = max(_max, maxv[o]);
	}
	else
	{
		int M = L + (R - L) / 2;
		if (ql <= M) 
			query(o * 2, L, M);
		if (qr > M)
			query(o * 2 + 1, M + 1, R);
	}
}
```



### 3.4.4 - segtree

```c++
//1.segment add
//2.segment mul
//3.segment query

namespace cyc
{
    const int maxN = 131072;
    LL addv[maxN * 2], mulv[maxN * 2], sumv[maxN * 2], mod;

    LL mul(LL a, LL b) { return a * b % mod; }
    LL add(LL a, LL b) { return (a + b) % mod; }

    void pushdown(int o, int L, int R)
    {
        int lc = o * 2, rc = o * 2 + 1;
        sumv[lc] = mul(sumv[lc], mulv[o]);
        sumv[rc] = mul(sumv[rc], mulv[o]);
        mulv[lc] = mul(mulv[lc], mulv[o]);
        mulv[rc] = mul(mulv[rc], mulv[o]);
        addv[lc] = mul(addv[lc], mulv[o]);
        addv[rc] = mul(addv[rc], mulv[o]);

        int M = (L + R) / 2;
        sumv[lc] = add(sumv[lc], addv[o] * (M - L + 1));
        sumv[rc] = add(sumv[rc], addv[o] * (R - M));
        addv[lc] = add(addv[lc], addv[o]);
        addv[rc] = add(addv[rc], addv[o]);

        mulv[o] = 1;
        addv[o] = 0;
    }

    int y1, y2;
    LL v;

    void update_add(int o = 1, int L = 1, int R = maxN)
    {
        int lc = o * 2, rc = o * 2 + 1;
        if (y1 <= L && y2 >= R)
        {
            addv[o] = add(addv[o], v);
            sumv[o] = add(sumv[o], v * (R - L + 1));
        }
        else
        {
            pushdown(o, L, R);
            int M = (L + R) / 2;
            if (y1 <= M)
                update_add(lc, L, M);
            if (y2 > M)
                update_add(rc, M + 1, R);
            sumv[o] = add(sumv[lc], sumv[rc]);
        }
    }

    void update_mul(int o = 1, int L = 1, int R = maxN)
    {
        int lc = o * 2, rc = o * 2 + 1;
        if (y1 <= L && y2 >= R)
        {
            mulv[o] = mul(mulv[o], v);
            addv[o] = mul(addv[o], v);
            sumv[o] = mul(sumv[o], v);
        }
        else
        {
            pushdown(o, L, R);
            int M = (L + R) / 2;
            if (y1 <= M)
                update_mul(lc, L, M);
            if (y2 > M)
                update_mul(rc, M + 1, R);
            sumv[o] = add(sumv[lc], sumv[rc]);
        }
    }

    LL _sum;
    void query(int o = 1, int L = 1, int R = maxN)
    {
        if (y1 <= L && y2 >= R)
            _sum = (_sum + sumv[o]) % mod;
        else
        {
            pushdown(o, L, R);
            int M = (L + R) / 2;
            if (y1 <= M)
                query(o * 2, L, M);
            if (y2 > M)
                query(o * 2 + 1, M + 1, R);
        }
    }
}
```



### 3.5 - kmp

```c++
void getFail(char *P, int *f)
{
	int m = strlen(P);
	f[0] = f[1] = 0;
	for (int i = 1; i < m; i++)
	{
		int j = f[i];
		while (j && P[i] != P[j])
			j = f[j];
		f[i + 1] = P[i] == P[j] ? j + 1 : 0;
	}
}

void find(char *T, char *P, int *f)
{
	int n = strlen(T), m = strlen(P);
	getFail(P, f);
	int j = 0;
	for (int i = 0; i < n; i++)
	{
		while (j && P[j] != T[i])
			j = f[j];
		if (P[j] == T[i])
			j++;
		if (j == m)
			printf("%d\n", i - m + 1);
	}
}
```

