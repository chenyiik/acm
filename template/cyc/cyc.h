#include <cstring>
#include <cmath>
#include <algorithm>
#include <string>
#include <queue>
#include <vector>
#include <set>
#include <map>

typedef long long LL;

void sieve(int);
int gen_primes(int);

LL gcd(LL, LL);
void gcd(LL, LL, LL &, LL &, LL &);

LL pow_mod(LL, LL, LL);

int euler_phi(int);
void phi_table(int n);

LL inv(LL, LL);
LL inv2(LL, LL);
