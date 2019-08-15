#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;
typedef long long LL;
const LL mod = LL(1e9) + 7;
LL pow_mod(LL a, LL p, LL n = mod)
{
	if (p == 0)
		return 1;
	LL ans = pow_mod(a, p / 2, n);
	ans = ans * ans % n;
	if (p % 2 == 1)
		ans = ans * a % n;
	return ans;
}
LL inv(LL a, LL n = mod) // when n is a prime
{
	return pow_mod(a, n - 2, n);
}

int main()
{
	int _;
	while (cin >> _)
		cout << inv(_) << endl;
	return 0;
}
