#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = int(1e5) + 5;
int a[maxn];

bool solve(int n, int x, int y)
{
		if (min(y, n - x + 1) < y)
			return false;
        while (n)
        {
				int p = min(y, n - x + 1);
                for (int i = 0; i < p; i++)
                        a[n - p + 1 + i] = n - i;
                x--, n -= p;
				if (x < 0)
					return false;
        }
		return x == 0;
		
}

int main()
{
        int _; scanf("%d", &_);
        while (_--)
        {
                int n, x, y; scanf("%d%d%d", &n, &x, &y);
				for (int i = 1; i <= n; i++)
					a[i] = i;
                if (solve(n, x, y))
                {
                        puts("YES");
                        for (int i = 1; i <= n; i++)
                                printf("%d%c", a[i], " \n"[i == n]);
                }
                else
                        puts("NO");
        }
        return 0;
}
