#include <cstdio>
#include <cstring>
#include <cctype>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

const int maxn = int(1e5) + 10;
struct P
{
	int v;
	string s;
	bool operator<(const P &o) const { return v > o.v || (v == o.v && s < o.s); }
} a[maxn];

int d[15];

int royal()
{
	if (d[1] && d[10] && d[11] && d[12] && d[13])
		return 1 << 30;
	return 0;
}

int straight()
{
	for (int i = 13; i >= 5; i--)
		if (d[i])
		{
			for (int j = i - 1; j >= i - 4; j--)
				if (!d[j])
					return 0;
			return i << 26;
		}
	return 0;
}

int four()
{
	for (int i = 13; i >= 1; i--)
		if (d[i] == 4)
			return i << 22;
	return 0;
}

int full()
{
	for (int i = 13; i >= 1; i--)
		if (d[i] == 3)
			for (int j = 13; j >= 1; j--)
				if (d[j] == 2)
					return (i << 18) + (j << 6);
	return 0;
}

int three()
{
	for (int i = 13; i >= 1; i--)
		if (d[i] == 3)
			return i << 14;
	return 0;
}

int two()
{
	for (int i = 13; i >= 1; i--)
		if (d[i] == 2)
			for (int j = i - 1; j >= 1; j--)
				if (d[j] == 2)
					return (i << 10) + (j << 6);
	return 0;
}

int _pair()
{
	for (int i = 13; i >= 1; i--)
		if (d[i] == 2)
			return i << 6;
	return 0;
}

int main()
{
	for (int n; cin >> n; )
	{
		string t;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i].s >> t;
			memset(d, 0, sizeof(d));
			for (char c : t)
			{
				if (c == '1') continue;
				else if (c == '0') d[10]++;
				else if (isdigit(c)) d[c - '0']++;
				else if (c == 'A') d[1]++;
				else if (c == 'J') d[11]++;
				else if (c == 'Q') d[12]++;
				else if (c == 'K') d[13]++;
			}
			a[i].v = 0;
			if (a[i].v = royal());
			else if (a[i].v = straight());
			else if (a[i].v = four());
			else if (a[i].v = full());
			else if (a[i].v = three());
			else if (a[i].v = two());
			else if (a[i].v = _pair());
			for (int j = 1; j <= 13; j++)
				a[i].v += j * d[j];
		}
		sort(a, a + n);
		for (int i = 0; i < n; i++)
			cout << a[i].s << endl;
	}
	return 0;
}
