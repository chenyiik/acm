#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

int main()
{
	int t = 0;
	scanf("%d", &t);
	while (t--)
	{
		int n, m;
		scanf("%d%d", &n, &m);
		if (n < m)
			swap(n, m);
		stack<int> S;
		while (m > 0)
		{
			S.push(n / m);
			n = n % m;
			swap(n, m);
			//cout << n << ' ' << m << endl;
		}
		int p = false;
		while (!S.empty())
		{
			int d = S.top();
			S.pop();
			if (d == 1)
				p = !p;
			else
				p = true;
		}
		puts(p ? "Stan wins" : "Ollie wins");
	}
	return 0;
}
