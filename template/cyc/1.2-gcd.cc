#include "cyc.h"

LL gcd(LL a, LL b) { return !b ? a : gcd(b, a % b); }

void gcd(LL a, LL b, LL &d, LL &x, LL &y)
{
	if (!b)
		d = a, x = 1, y = 0;
	else
	{
		gcd(b, a % b, d, y, x);
		y -= x * (a / b);
	}
}
