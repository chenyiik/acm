#include <stdio.h>
#define ULL unsigned long long

char s[65];

int main()
{
	int n; ULL k; scanf("%d%llu", &n, &k);
	ULL d = 1ULL << (n - 1);
	for (char *p = s; n--; ++p)
		*p = k < d ? '0' : (k = (d << 1) + ~k, '1'), d >>= 1;
	puts(s);
	return 0;
}
