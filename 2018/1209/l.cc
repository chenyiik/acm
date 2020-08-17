#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int main()
{
	int n = 0;
	scanf("%d", &n);
	map<int, int> M;
	while (n--)
	{
		int x = 0;
		scanf("%d", &x);
		auto it = M.find(x);
		if (it == M.end())
			M[x] = 1;
		else
			it->second++;
	}
	const int maxN = static_cast<int>(2e5);
	static int a[maxN + 5];
	n = 0;
	for (auto it : M)
		a[n++] = it->second;
	sort(a, a + n);
	int ans = 0;

	printf("%d\n", ans);
	return 0;
}
