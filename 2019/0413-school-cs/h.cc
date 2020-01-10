#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int gcd(int a, int b) { return !b ? a : gcd(b, a % b); }

int main()
{
	int n = 0;
	scanf("%d", &n);
	const int maxN = static_cast<int>(5e5+7);
	static long long a[maxN], nxt[maxN];
	for (int i = 0; i < n; i++)
	{
		scanf("%lld", &a[i]);
		nxt[i] = 1;
	}
	long long tot = 0;
	const long long mod = 1000000007;
	while (n)
	{
		/*
		cout << endl;
		for (int i = 0; i < n; i++)
			cout << a[i] << ' ';
		cout << endl;
		for (int i = 0; i < n; i++)
			cout << nxt[i] << ' ';
		cout << endl;
		*/
		for (int i = 0, j = -1; i < n; j = i, i += nxt[i])
		{
//cout << i << endl;
			if (i + nxt[i] >= n)
			{
				tot += (n - i) * a[i];
				tot %= mod;
			}
			else
			{
				tot += nxt[i] * a[i];
				tot %= mod;
			}
			if (j == -1)
				continue;
			a[i - 1] = gcd(a[i - 1], a[i]);
			if (i - 1 == j)
			{
				if (a[i - 1] == a[i])
				{
					nxt[i - 1] = nxt[i] + 1;
					i--;
				}
				else { ; }
			}
			else
			{
				if (a[i - 1] == a[j] && a[i - 1] == a[i])
				{
					nxt[j] += nxt[i];
					i = j;
				}
				else if (a[i - 1] == a[j]) { ; }
				else if (a[i - 1] == a[i])
				{
					nxt[j]--;
					nxt[i - 1] = nxt[i] + 1;
					i--;
				}
				else
				{
					nxt[j]--;
					nxt[i - 1] = 1;
				}
			}
		}
		n--;
	}
	printf("%lld\n", tot);
	return 0;
}
		/*
		for (int i = 0, j = 0, k = -1; i < n; k = j, j = i++)
		{
			if (i + nxt[i] >= n)
			{
				tot += (n - i) * a[i];
				tot %= mod;
				break;
			}
			else
			{
				tot += nxt[i] * a[i];
				tot %= mod;
			}
			nxt[i];
			i += nxt[i] - 1;
			a[i] = gcd(a[i], a[i + 1]);
			if (k != -1 && a[k] == a[i])
				nxt[k] += nxt[i];
cout << i << endl;
		}
		*/
