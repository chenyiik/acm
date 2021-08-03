#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

const int maxn = int(5e5) + 5;
int a[maxn], t[maxn];


int main()
{
	int _; scanf("%d", &_);
	while (_--)
	{
		int n; scanf("%d", &n);
		for (int i = 0; i < n; i++)
			scanf("%d", &a[i]);
		sort(a, a + n);
		int m = n / 2;
		int l = 0, r = m;
		queue<int> p, q;
		int no = false;
		for (int line = 0; (1 << line) <= n; line++)
		{
			int L = 1 << line, R = min(1 << (line + 1), n + 1);
			for (int i = L; i < R; i++)
			{
				if (line % 2 == 0)
				{
					if (i == 1)
						t[i] = a[l++], cout << i << t[i] << endl;
					else if (i % 2 == 0)
					{
						if (!p.empty())
							t[i] = p.front(), p.pop(), cout << i << t[i] << endl;
						else if (l < m)
							t[i] = a[l++], cout << i << t[i] << endl;
						else
						{
							no = true;
							break;
						}
					}
					else
					{
						while (l < m && a[l] >= t[i / 2])
							p.push(a[l++]);
						if (l < m)
							t[i] = a[l++], cout << i << t[i] << endl;
						else
						{
							no = true;
							break;
						}
					}
				}
				else
				{
					if (i % 2 == 0)
					{
						while (r < n && a[r] <= t[i / 2])
							q.push(a[r++]), cout << i << t[i] << endl;
						if (r < n)
							t[i] = a[r++], cout << i << t[i] << endl;
						else
						{
							no = true;
							break;
						}
					}
					else
					{
						if (!q.empty())
							t[i] = q.front(), q.pop();
						else if (r < n)
							t[i] = a[r++], cout << i << t[i] << endl;
						else
						{
							no = true;
							break;
						}
					}
				}
			}
			if (no)
				break;
		}
		if (no)
			puts("No");
		else 
		{ 
			puts("Yes");
			for (int i = 1; i <= n; i++)
			{
				printf("%d %d %d\n", t[i], i * 2 > n ? 0 : i * 2, i * 2 + 1 > n ? 0 : i * 2 + 1);
			}
		}
	}
	return 0;
}
