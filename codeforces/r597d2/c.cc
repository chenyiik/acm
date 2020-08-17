#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
 
using namespace std;
 
const int maxn = int(1e5) + 5, mod = int(1e9) + 7;
char s[maxn];
 
int f[maxn][2];
 
typedef long long LL;
int add(LL a, LL b) { return (a + b) % mod; }
int mul(LL a, LL b) { return a * b % mod; }
 
int main()
{
	f[1][0] = 1;
	for (int i = 2; i < maxn; i++)
	{
		f[i][0] = add(f[i - 1][0], f[i - 1][1]);
		f[i][1] = f[i - 1][0];
	}
	scanf("%s", s);
	int ans = 1;
	for (char *p = s; *p; p++)
	{
		if (*p == 'm' || *p == 'w')
			return puts("0");
		if (*p == 'n')
		{
			int len = 0;
			while (*p == 'n')
				p++, len++;
			ans = mul(ans, f[len][0] + f[len][1]);
			p--;
		}
		if (*p == 'u')
		{
			int len = 0;
			while (*p == 'u')
				p++, len++;
			ans = mul(ans, f[len][0] + f[len][1]);
			p--;
		}
	}
	printf("%d\n", ans);
	return 0;
}
