#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int a[105], n, m;
bool t[3][21];

int f(int i1, int i2, int i5, int i10, int k)
{
    for (int j1 = 0; j1 <= i1; j1++)
        for (int j2 = 0; j2 <= i2; j2++)
            for (int j5 = 0; j5 <= i5; j5++)
                for (int j10 = 0; j10 <= i10; j10++)
                    if (j1 + j2 * 2 + j5 * 5 + j10 * 10 == k)
                        return true;
    return false;
}

int main()
{
    int _; scanf("%d", &_);
    while (_--)
    {
        scanf("%d", &n);
        bool b = true;
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &a[i]);
            if (a[i] % 10 != 0)
                b = false;
            a[i] /= 10;
        }
        if (!b)
        {
            puts("-1");
            continue;
        }
        sort(a, a + n);
        m = max(0, a[n - 1] / 10 - 1);
        memset(t, false, sizeof(t));
        for (int i = 0; i < n; i++)
        {
            if (a[i] < 10)
                t[0][a[i]] = true;
            else if (a[i] < (m + 1) * 10)
                t[1][a[i] % 10] = true;
            else
                t[2][a[i] % 10] = true;
        }
        int ans = 0x7fffffff;
        for (int i1 = 0; i1 <= 20; i1++)
            for (int i2 = 0; i2 <= 10; i2++)
                for (int i5 = 0; i5 <= 4; i5++)
                    for (int i10 = 0; i10 <= 2; i10++)
                    {
                        bool b = true;
                        /*
                        if (i1 == 1 && i2 == 2 && i5 == 1 && i10 == 0)
                        {
                            for (int k = 0; k < n; k++)
                            {
                                if (a[k] < 10)
                                    b = b && f(i1, i2, i5, i10, a[k]);
                                else if (a[k] < (m+1) * 10)
                                    b = b && (f(i1, i2, i5, i10, a[k] % 10) || f(i1, i2, i5, i10, a[k] % 10 + 10));
                                else
                                    b = b && f(i1, i2, i5, i10, a[k] % 10 + 10);
                                if (!b)
                                    cout<<a[k]<<endl, k = n;
                            }
                        } else
                            */
                        for (int k = 0; k < 10; k++) if (t[0][k])
                            b = b && f(i1, i2, i5, i10, k);
                        for (int k = 0; k < 10; k++) if (t[1][k])
                            b = b && (f(i1, i2, i5, i10, k) || f(i1, i2, i5, i10, k + 10));
                        for (int k = 0; k < 10; k++) if (t[2][k])
                            b = b && f(i1, i2, i5, i10, k + 10);
                        /*
                        for (int k = 0; k < n; k++)
                        {
                            if (a[k] < 10)
                                b = b && f(i1, i2, i5, i10, a[k]);
                            else if (a[k] < (m+1) * 10)
                                b = b && (f(i1, i2, i5, i10, a[k] % 10) || f(i1, i2, i5, i10, a[k] % 10 + 10));
                            else
                                b = b && f(i1, i2, i5, i10, a[k] % 10 + 10);
                        }
                        */
                        if (b)
                            ans = min(ans, m + i1 + i2 + i5 + i10);
                        //if (b && m + i1 + i2 + i5 + i10 == ans)
                            //cout << i1 << i2 << i5 << m + i10 <<endl;
                    }
        printf("%d\n", ans);
    }
    return 0;
}
