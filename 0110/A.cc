#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

int check(int x)
{
	while (x >= 202)
	{
		if (x % 1000 == 202)
			return 1;
		x /= 10;
	}
	return 0;
}

int k[13] = { -1,
	31, -1, 31, 30,
	31, 30, 31, 31,
	30, 31, 30, 31
};

void cal(int a, int b, int c, int &d, int &e, int &f)
{
	if (a % 400 == 0) k[2] = 29;
	else if (a % 100 == 0) k[2] = 28;
	else if (a % 4 == 0) k[2] = 29;
	else k[2] = 28;
	d = a, e = b, f = c + 1;
	if (f > k[e])
	{
		f = 1;
		if (++e > 12)
			e = 1, d++;
	}
}

int main()
{
	unordered_map<int, int> M;
	M[20000101] = 0;
	//init
	int a = 2000, b = 1, c = 1, d, e, f;
	while (true)
	{
		if (a == 9999 && b == 12 && c == 31)
			break;
		cal(a, b, c, d, e, f);
		int x = a * 10000 + b * 100 + c;
		int y = d * 10000 + e * 100 + f;
		M[y] = M[x] + check(y);
		a = d, b = e, c = f;
		//if (a == 9999) cout << a << ' ' << b << ' ' << c << ' ' << y << endl;
	}
	//cout << "done" << endl;
	//qa
	int _; scanf("%d", &_);
	while (_--)
	{
		scanf("%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f);
		int x = a * 10000 + b * 100 + c;
		int y = d * 10000 + e * 100 + f;
		int ans = M[y] - M[x] + check(x);
		printf("%d\n", ans);
	}
	return 0;
}
