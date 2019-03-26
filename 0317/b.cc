#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int hpA, hpB, atkA, atkB;

long long killAB(char st[])
{
	int i, j;
	for (i = 1; hpA > 0; i++)
	{
		st[i] = 'A';
		hpA -= i;
	}
	if (-hpA >= hpB)
	{
		st[i--] = 0;
		st[hpB] = 'B';
		return i * atkA + hpB * atkB;
	}
	for (j = i; hpB > 0; j++)
	{
		st[j] = 'B';
		hpB -= j;
	}
	st[j--] = 0;
	i--;
	if (hpB + j <= -hpA)
	{
		st[j--] = 0;
		st[-hpA] = 'B';
	}
	return i * atkA + j * atkB;
}

long long killBA(char st[])
{
	int i, j;
	for (i = 1; hpB > 0; i++)
	{
		st[i] = 'B';
		hpB -= i;
	}
	for (j = 1; j < i && hpA > 0; j++)
		if (-hpB - j > j || -hpB == j)
		{
			st[j] = 'A';
			hpB += j;
			hpA -= j;
		}
	if (hpA <= 0)
	{
		j--;
		st[i--] = 0;
		return i * atkB + j * atkA;
	}
	for ( ; hpA > 0; j++)
	{
		st[j] = 'A';
		hpA -= j;
	}
	i--;
	st[j--] = 0;
	return i * atkB + j * atkA;
}

int main()
{
	int t = 0;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d%d%d%d", &hpA, &hpB, &atkA, &atkB);
		const int maxM = static_cast<int>(1e5) + 5;
		char stA[maxM], stB[maxM];
		int r4 = hpA, r5 = hpB;
		long long ansA = killAB(stA);
		hpA = r4, hpB = r5;
		long long ansB = killBA(stB);
		//if (ansA < ansB || ansA == ansB && strcmp(stA, stB) < 0)
			printf("%lld %s\n", ansA, stA + 1);
		//else
			printf("%lld %s\n", ansB, stB + 1);
	}
	return 0;
}
