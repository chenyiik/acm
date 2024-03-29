#include "cyc.h"

//1.segment add
//2.segment mul
//3.segment query

namespace cyc
{
    const int maxN = 131072;
    LL addv[maxN * 2], mulv[maxN * 2], sumv[maxN * 2], mod;

    LL mul(LL a, LL b) { return a * b % mod; }
    LL add(LL a, LL b) { return (a + b) % mod; }

    void pushdown(int o, int L, int R)
    {
        int lc = o * 2, rc = o * 2 + 1;
        sumv[lc] = mul(sumv[lc], mulv[o]);
        sumv[rc] = mul(sumv[rc], mulv[o]);
        mulv[lc] = mul(mulv[lc], mulv[o]);
        mulv[rc] = mul(mulv[rc], mulv[o]);
        addv[lc] = mul(addv[lc], mulv[o]);
        addv[rc] = mul(addv[rc], mulv[o]);

        int M = (L + R) / 2;
        sumv[lc] = add(sumv[lc], addv[o] * (M - L + 1));
        sumv[rc] = add(sumv[rc], addv[o] * (R - M));
        addv[lc] = add(addv[lc], addv[o]);
        addv[rc] = add(addv[rc], addv[o]);

        mulv[o] = 1;
        addv[o] = 0;
    }

    int y1, y2;
    LL v;

    void update_add(int o = 1, int L = 1, int R = maxN)
    {
        int lc = o * 2, rc = o * 2 + 1;
        if (y1 <= L && y2 >= R)
        {
            addv[o] = add(addv[o], v);
            sumv[o] = add(sumv[o], v * (R - L + 1));
        }
        else
        {
            pushdown(o, L, R);
            int M = (L + R) / 2;
            if (y1 <= M)
                update_add(lc, L, M);
            if (y2 > M)
                update_add(rc, M + 1, R);
            sumv[o] = add(sumv[lc], sumv[rc]);
        }
    }

    void update_mul(int o = 1, int L = 1, int R = maxN)
    {
        int lc = o * 2, rc = o * 2 + 1;
        if (y1 <= L && y2 >= R)
        {
            mulv[o] = mul(mulv[o], v);
            addv[o] = mul(addv[o], v);
            sumv[o] = mul(sumv[o], v);
        }
        else
        {
            pushdown(o, L, R);
            int M = (L + R) / 2;
            if (y1 <= M)
                update_mul(lc, L, M);
            if (y2 > M)
                update_mul(rc, M + 1, R);
            sumv[o] = add(sumv[lc], sumv[rc]);
        }
    }

    LL _sum;
    void query(int o = 1, int L = 1, int R = maxN)
    {
        if (y1 <= L && y2 >= R)
            _sum = (_sum + sumv[o]) % mod;
        else
        {
            pushdown(o, L, R);
            int M = (L + R) / 2;
            if (y1 <= M)
                query(o * 2, L, M);
            if (y2 > M)
                query(o * 2 + 1, M + 1, R);
        }
    }
}
