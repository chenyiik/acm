#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int t; scanf("%d", &t);
	while (t--)
	{
		long long a, b, c; scanf("%lld%lld%lld", &a, &b, &c);
		cout << a + b + c << endl;
	}
	return 0;
}
