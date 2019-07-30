#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

int main()
{
	long long n = 0, m = 0;
	while (~scanf("%lld%lld", &n, &m) && n && m)
	{
		stack<long long> s;
		int nn = 2 * m, mm = static_cast<long long>(sqrt(0.5 + nn));
		for (int i = 1; i <= mm; i++)
		{
			if (nn % i == 0 && i * i < nn && (i & 1) != ((nn / i ) & 1))
			{
				s.push(nn / i);
				int mid2 = i, cha = nn / i - 1;
				int a = (mid2 - cha) / 2, b = (mid2 + cha) / 2;
				if (a >= 1 && b <= n)
					printf("[%d,%d]\n", a, b);
			}
		}
		while (!s.empty())
		{
			int mid2 = s.top(), cha = nn / mid2 - 1;
			s.pop();
			int a = (mid2 - cha) / 2, b = (mid2 + cha) / 2;
			if (a >= 1 && b <= n)
				printf("[%d,%d]\n", a, b);
		}
		puts("");
	}
	return 0;
}
