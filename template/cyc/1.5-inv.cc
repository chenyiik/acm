#include "cyc.h"

LL inv(LL a, LL n) // inv don't exist when it return -1
{
	LL d, x, y;
	gcd(a, n, d, x, y);
	return d == 1 ? (x + n) % n : -1;
}

LL inv2(LL a, LL n) // when n is a prime
{
	return pow_mod(a, n - 2, n);
}
