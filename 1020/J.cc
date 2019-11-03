#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

char s[20][10];

int main()
{
	int n, k; scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++)
	{
		scanf("%s", s[i]);
		sort(s[i], s[i] + 4);
	}
	for (int p = k - 1; ; p = (p + 1) % n)
	{
	}
	return 0;
}
