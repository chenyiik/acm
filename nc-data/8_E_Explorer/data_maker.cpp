#include <set>
#include <cmath>
#include <random>
#include <string>
#include <fstream>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 10;
mt19937_64 gen(19260817);

int Rand(int p = 1000000000)
{
	return gen() % p + 1;
}

int Rand(int l, int r)
{
	return l + Rand(r - l + 1) - 1;
}

void PrintSample()
{
	cout << "5 5" << endl;
	cout << "1 2 1 4" << endl;
	cout << "2 3 1 2" << endl;
	cout << "3 5 2 4" << endl;
	cout << "2 4 1 3" << endl;
	cout << "4 5 3 4" << endl;
}

struct Edge
{
	int a, b, l, r;
	Edge() {}
	Edge(int a, int b, int l, int r) : a(a), b(b), l(l), r(r) {}
};

bool Flag[100005];
set<pair<int, int>> Set;

void Generate(int id, Edge *E, int n, int maxw, int st, int ed, int mn_w, int mx_w)
{
	vector <int> Vec;
	for (int last = 1, j = st, x; j <= ed; j ++, last = x)
	{
		if (j == ed)
			x = n;
		else do
		{
			x = Rand(2, n - 1);
		} while (Flag[x] || Set.count(minmax(last, x)));
		Flag[x] = true, Vec.push_back(x);
		int l = Rand(mn_w, mx_w), r = Rand(mn_w, mx_w);
		if (l > r) swap(l, r);
		Set.insert(minmax(last, x));
		E[j] = Edge(last, x, l, r);
	}
	for (int id : Vec)
		Flag[id] = false;
}

void MakeData(int id, int maxn, int maxm, int maxw)
{
	if (id == 10)
	{
		int n = 60000, m = 29999 + (60000 - 30001) * 2;
		cout << n << ' ' << m << endl;
		for (int i = 1; i < 15000; i ++)
			cout << i << ' ' << i + 1 << ' ' << 1 << ' ' << maxw << endl;
		for (int i = 15001; i < 45000; i ++)
		{
			int id = i - 15000;
			cout << 15000 << ' ' << i << ' ' << min((id - 1) * (id - 1) + 2, id * id) << ' ' << id * id << endl;
			cout << i << ' ' << 45000 << ' ' << min((id - 1) * (id - 1) + 2, id * id) << ' ' << id * id << endl;
		}
		for (int i = 45000; i < n; i ++)
			cout << i << ' ' << i + 1 << ' ' << 1 << ' ' << maxw << endl;
		return ;
	}
	static int Ord[100005];
	static Edge E[100005];
	Set.clear();
	int n = Rand(maxn / 2 + 1, maxn), m = Rand(n - 1, maxm);
	for (int i = 1; i <= n; i ++)
		Ord[i] = i;
	for (int i = 2; i < n; i ++)
		swap(Ord[i], Ord[Rand(i, n - 1)]);	
	for (int l = 1, r; l <= m; l = r + 1)
	{
		int mn_w = Rand(1, maxw), mx_w = Rand(1, maxw);
		if (mn_w > mx_w) swap(mn_w, mx_w);
		if (id <= 2)
			r = Rand(l, min(m, l + n - 2));
		else if (id <= 5)
			r = m / (m / l);
		else if (id <= 7)
			r = (l + m) / 2;
		else if (id == 8)
			r = min(l + 100, m);
		else if (id == 9)
			r = min(l + 1, m);
		Generate(id, E, n, maxw, l, r, mn_w, mx_w);
	}
	random_shuffle(E + 1, E + m + 1);
	cout << n << ' ' << m << endl;
	int mn = maxw, mx = 0;
	for (int i = 1; i <= m; i ++)
	{
		int u = Ord[E[i].a], v = Ord[E[i].b];
		if (u > v) swap(u, v);
		mn = min(mn, E[i].l), mx = max(mx, E[i].r);
		cout << u << ' ' << v << ' ' << E[i].l << ' ' << E[i].r << endl;
	}
	cerr << "mn = " << mn << ", mx = " << mx << endl;
}

int main()
{
	streambuf *back_up = cout.rdbuf();
	for (int i = 0; i <= N; i ++)
	{
		string filename = to_string(i) + ".in";
		ofstream fout(filename.c_str());
		cout.rdbuf(fout.rdbuf());
		
		if (i == 0) PrintSample();
		else MakeData(i, 100000, 100000, 1000000000);
		
		cerr << "Make " << filename << endl;
	}
	cout.rdbuf(back_up);
	return 0;
}
