#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int a[300000 + 7];
int d[300000 + 7];

int main()
{
	int n = 0;
	scanf("%d", &n);
	if (n < 5)
		return puts("-1"), 0;
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for (int i = 1; i <= n / 2 + n % 2; i++)
		d[i] = i * 2 - 1;
	for (int i = n / 2 + n % 2 + 1, j = 1; i <= n; i++, j++)
		d[i] = j * 2;
	if (n % 2 == 0)
		swap(d[n], d[n - 1]);
	for (int i = 1; i <= n; i++)
		printf("%d%c", a[d[i]], " \n"[i == n]);
	return 0;
}
