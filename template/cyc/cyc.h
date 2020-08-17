#include <cstring>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <set>
#include <map>

using namespace std;

typedef long long LL;

const int oo = 0x3f3f3f3f;

void sieve(int);
int gen_primes(int);

LL gcd(LL, LL);
void gcd(LL, LL, LL &, LL &, LL &);

LL pow_mod(LL, LL, LL);

int euler_phi(int);
void phi_table(int n);

LL inv(LL, LL);
LL inv2(LL, LL);
