#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int n = 0, m = 0;
	scanf("%d%d", &n, &m);
	int l = 0, r = 0;
	for (int i = 0; i < n; i++)
	{
		int x = 0;
		scanf("%d", &x);
		x < m ? l++ : r++;
	}
	printf("%d\n", max(0, r - l));
	return 0;
}
