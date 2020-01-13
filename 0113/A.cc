#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_set>

using namespace std;

typedef long long LL;
enum E { R, D };

const int maxn = 6, maxv = 11;
int a[maxn][maxn], vn = 0;

struct P { E dir; int len; } v[maxv];
struct T { LL value; int step; };
int X[maxv], Y[maxv];

LL init();
void draw(LL value);
LL fuck(LL i, LL x, LL y);

int main()
{
	for (int i = 0; i < maxn; i++) for (int j = 0; j < maxn; j++)
		scanf("%d", &a[i][j]);
	LL cnm = init();
	//cout << cnm << endl;
	if (v[1].dir == D) return puts("-1"), 0;
	queue<T> Q; Q.push({cnm, 2});
	unordered_set<LL> S; S.insert(cnm);
	while (!Q.empty() && Q.front().step <= 10)
	{
		T u = Q.front(); Q.pop();
		//cout << u.step << endl;
		draw(u.value);
		if (X[1] != 2) break;
		if (Y[1] + v[1].len == 5) return printf("%d\n", u.step), 0;
		for (int i = 1; i <= vn; i++)
		{
			if (v[i].dir == R)
			{
				if (Y[i] - 1 >= 0 && a[X[i]][Y[i] - 1] == 0)
				{
					//cout << i << " 0" << endl;
					LL tmp = fuck(i, X[i], Y[i] - 1);
					//cout << tmp << endl;
					if (S.find(tmp) == S.end())
						Q.push({tmp, u.step + 1}), S.insert(tmp);
				}
				if (Y[i] + v[i].len + 1 < maxn 
						&& a[X[i]][Y[i] + v[i].len + 1] == 0)
				{
					//cout << i << " 1" << endl;
					LL tmp = fuck(i, X[i], Y[i] + 1);
					//cout << tmp << endl;
					if (S.find(tmp) == S.end())
						Q.push({tmp, u.step + 1}), S.insert(tmp);
				}
			}
			else
			{
				if (X[i] - 1 >= 0 && a[X[i] - 1][Y[i]] == 0)
				{
					//cout << i << " 2" << endl;
					LL tmp = fuck(i, X[i] - 1, Y[i]);
					//cout << tmp << endl;
					if (S.find(tmp) == S.end())
						Q.push({tmp, u.step + 1}), S.insert(tmp);
				}
				if (X[i] + v[i].len + 1 < maxn
						&& a[X[i] + v[i].len + 1][Y[i]] == 0)
				{
					//cout << i << " 3" << endl;
					LL tmp = fuck(i, X[i] + 1, Y[i]);
					//cout << tmp << endl;
					if (S.find(tmp) == S.end())
						Q.push({tmp, u.step + 1}), S.insert(tmp);
				}
			}
		}
		//cout << Q.size() << endl;
	}
	puts("-1");
	return 0;
}

LL fuck(LL i, LL x, LL y)
{
	LL ans = 0;
	for (int j = vn; j > 0; j--)
	{
		if (j == i)
			ans = ans * 36 + x * 6 + y;
		else
			ans = ans * 36 + X[j] * 6 + Y[j];
	}
	return ans;
}

void draw(LL value)
{
	memset(a, 0, sizeof(a));
	memset(X, 0, sizeof(X));
	memset(Y, 0, sizeof(Y));
	for (int i = 1; i <= vn; i++)
	{
		int tmp = value % 36; value /= 36;
		int x = tmp / 6, y = tmp % 6;
		X[i] = x, Y[i] = y;
		for (int j = 0; j <= v[i].len; j++)
			a[x][y] = i, (v[i].dir == D ? x : y)++;
	}
	/*
	for (int i = 0; i < maxn; i++)
	{
		for (int j = 0; j < maxn; j++)
			cout << a[i][j] << ' ';
		cout << endl;
	}
	for (int i = 1; i <= vn; i++)
		cout << i << X[i] << Y[i] << endl;
	*/
}

LL init()
{
	LL ans = 0;
	for (int i = 0; i < maxn; i++) for (int j = 0; j < maxn; j++)
		if (a[i][j] > 0 && v[a[i][j]].len == 0)
		{
			vn = max(vn, a[i][j]);
			LL tmp = i * 6 + j;
			for (int k = a[i][j] - 1; k > 0; k--)
				tmp *= 36;
			ans += tmp;
			if (j + 1 < maxn && a[i][j + 1] == a[i][j])
			{
				v[a[i][j]].dir = R;
				for (int k = j + 1; k < maxn && a[i][k] == a[i][j]; k++)
					v[a[i][j]].len++;
			}
			else
			{
				v[a[i][j]].dir = D;
				for (int k = i + 1; k < maxn && a[k][j] == a[i][j]; k++)
					v[a[i][j]].len++;
			}
		}
	return ans;
}
