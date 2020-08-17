#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <ctime>
#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <utility>
#include <queue>
#include <stack>
#include <list>
#include <vector>
#include <set>
#include <map>

using namespace std;

int g[101];

int gcd(int a, int b) { return !b ? a : gcd(b, a % b); }

int main()
{
	int t = 0;
	scanf("%d", &t);
	while (t--)
	{
		int k[] = {2, 1, 0, 2};
		int n = 0;
		scanf("%d", &n);
		int a = k[n % 4] + n / 4 * 2, b = n;
		int g = gcd(a, b);
		a /= g, b /= g;
		if (b == 1)
			printf("%d\n", a);
		else
			printf("%d/%d\n", a, b);
	}
	return 0;
}
