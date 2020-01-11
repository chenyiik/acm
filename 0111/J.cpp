#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int gcd(int a, int b) { return !b ? a : gcd(b, a % b); }
int lcm(int a, int b) { return a / gcd(a, b) * b; }

int a[1005];

int main()
{
    int n, m;
    while (~scanf("%d%d", &n, &m))
    {
        int lc = 1;
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &a[i]);
            lc = lcm(lc, a[i]);
        }
        int sum = 0;
        for (int i = 0; i < n; i++)
            sum += lc / a[i];
        if (m % sum != 0)
        {
            puts("No");
            continue;
        }
        puts("Yes");
        int c = m / sum;
        for (int i = 0; i < n; i++)
            printf("%d%c", lc / a[i] * c, " \n"[i + 1 == n]);
    }
    return 0;
}