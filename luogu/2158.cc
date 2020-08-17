#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = 40005;

long long phi[maxn];

void phi_table(int n)
{
	for (int i = 2; i <= n; i++)
		phi[i] = 0;
	phi[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		if (!phi[i])
		{
			for (int j = i; j <= n; j += i)
			{
				if (!phi[j])
					phi[j] = j;
				phi[j] = phi[j] / i * (i - 1);
			}
		}
	}
}

int main()
{
	int n = 0;
	cin >> n;
	if (n == 1)
		return puts("0"), 0;
	phi_table(n - 1);
	long long tot = 0;
	for (int i = 1; i < n; i++)
		tot += phi[i];
	cout << tot * 2 + 1 << endl;
	return 0;
}
