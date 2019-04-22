#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

namespace cyc
{
	enum { J = 11, Q, K, A, P2, W1, W2 };
	int n = 0, a[20];


	bool is_single() { return n == 1; }

	bool is_pair()
	{
		if (n == 2)
		{
			for (int i = 3; i <= P2; i++)
				if (a[i] == 2)
					return true;
		}
		return false;
	}

	bool is_triple()
	{
		if (n == 3)
		{
			for (int i = 3; i <= P2; i++)
				if (a[i] == 3)
					return true;
		}
		return false;
	}

	bool is_triple_puls_a_single()
	{
		if (n == 4)
		{
			for (int i = 3; i <= P2; i++)
				if (a[i] == 3)
					return true;
		}
		return false;
	}

	bool is_triple_plus_a_pair()
	{
		if (n == 5)
		{
			bool b0 = false, b1 = false;
			for (int i = 3; i <= P2; i++)
			{
				if (a[i] == 3)
					b0 = true;
				if (a[i] == 2)
					b1 = true;
			}
			if (b0 && b1)
				return true;
		}
		return false;
	}

	bool is_single_straight()
	{
		if (n < 5)
			return false;
		int st = 3;
		while (st < P2 && a[st] == 0)
			st++;
		if (st + n > P2)
			return false;
		for (int i = st; i < st + n; i++)
			if (a[i] != 1)
				return false;
		return true;
	}

	bool is_pair_straight()
	{
		if (n % 2 != 0 || n < 6)
			return false;
		int m = n / 2, st = 3;
		while (st < P2 && a[st] == 0)
			st++;
		if (st + m > P2)
			return false;
		for (int i = st; i < st + m; i++)
			if (a[i] != 2)
				return false;
		return true;
	}

	bool is_triple_straight()
	{
		if (n % 3 != 0 || n < 6)
			return false;
		int m = n / 3, st = 3;
		while (st < P2 && a[st] == 0)
			st++;
		if (st + m > P2)
			return false;
		for (int i = st; i < st + m; i++)
			if (a[i] != 3)
				return false;
		return true;
	}

	bool is_airplane_NO_1()
	{
		if (n % 4 != 0 || n < 8)
			return false;
		int m = n / 4, st = 3;
		while (true)
		{
			while (st < P2 && a[st] < 3)
				st++;
			if (st + m > P2)
				return false;
			int fi = st;
			while (fi < st + m)
			{
				if (a[fi] < 3)
					break;
				fi++;
			}
			if (fi == st + m)
				break;
			else
				st = fi;
		}
		return true;
	}

	bool is_airplane_NO_2()
	{
		if (n % 5 != 0 || n < 10 || a[W1] == 1 || a[W2] == 1 || a[P2] == 3)
			return false;
		int m = n / 5, st = 3;
		while (st < P2 && a[st] != 3)
			st++;
		if (st + m > P2)
			return false;
		for (int i = st; i < st + m; i++)
			if (a[i] != 3)
				return false;
		for (int i = 3; i < st; i++)
			if (a[i] % 2 != 0)
				return false;
		for (int i = st + m; i <= P2; i++)
			if (a[i] % 2 != 0)
				return false;
		return true;
	}

	bool is_bomb()
	{
		if (n == 4)
		{
			for (int i = 3; i <= P2; i++)
				if (a[i] == 4)
					return true;
		}
		return false;
	}

	bool is_rocket() { return n == 2 && a[W1] == 1 && a[W2] == 1; }

	bool is_quartet_puls_two_singles()
	{
		if (n == 6)
		{
			for (int i = 3; i <= P2; i++)
				if (a[i] == 4)
					return true;
		}
		return false;
	}


	bool solve()
	{
		cin >> s;
		memset(a, 0, sizeof(a));
		for (int i = 0; i < n; i++)
		{
			char s[5];
			cin >> s;
			if (*s == '1')
				a[10]++;
			else if (*s == 'J')
				a[11]++;
			else if (*s == 'Q')
				a[12]++;
			else if (*s == 'K')
				a[13]++;
			else if (*s == 'A')
				a[14]++;
			else if (*s == '2')
				a[15]++;
			else if (*s == 'W')
			{
				if (s[1] == '1')
					a[16]++;
				else
					a[17]++;
			}
			else
				a[*s - '0']++;
		}

		return is_single() || is_pair() || is_triple() || is_triple_puls_a_single()
			|| is_triple_plus_a_pair() || is_single_straight() || is_pair_straight()
			|| is_triple_straight() || is_airplane_NO_1() || is_airplane_NO_2()
			|| is_bomb() || is_rocket() || is_quartet_puls_two_singles();
	}
}

int main()
{
	int t = 0;
	cin >> s;
	while (t--)
		puts(cyc::solve() ? "Ye5" : "N0");
	return 0;
}
