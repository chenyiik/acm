#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long LL;

const int maxn = 105;
const int maxm = maxn * maxn;
const int mod = 998244353;

vector<int> G[maxn];
int calc_mst(int n);

struct E { int u, v, w; } a[maxm];

int inv(LL q);
int add(LL a, LL b) { return (a + b) % mod; }
int sub(LL a, LL b) { return (a % mod - b % mod + mod) % mod; } 
int mul(LL a, LL b) { return a * b % mod; }
int di(LL p, LL q) { return p * inv(q) % mod; }

int main()
{
       int _; scanf("%d", &_);
       while (_--)
       {
               int n, m; scanf("%d%d", &n, &m);
               for (int i = 1; i <= n; i++)
                       G[i].clear();
               for (int i = 0; i < m; i++)
               {
                       scanf("%d%d%d", &a[i].u, &a[i].v, &a[i].w);
                       G[a[i].u].push_back(a[i].v);
                       G[a[i].v].push_back(a[i].u);
               }
               int sum = calc_mst(n);
               int ans = 0;
               for (int bit = 0; bit < 31; bit++)
               {
                       for (int i = 1; i <= n; i++)
                               G[i].clear();
                       for (int i = 0; i < m; i++)
                               if (a[i].w & (1 << bit))
                               {
                                       G[a[i].u].push_back(a[i].v);
                                       G[a[i].v].push_back(a[i].u);
                               }
                       int one = calc_mst(n);
                       int tmp = di(one, sum);
                       ans = add(ans, mul(tmp, 1 << bit));
               }
               printf("%d\n", ans);
       }
       return 0;
}


int pow_mod(LL a, LL p, LL n = mod)
{
       if (p == 0)
               return 1;
       LL ans = pow_mod(a, p / 2, n);
       ans = ans * ans % n;
       if (p % 2 == 1)
               ans = ans * a % n;
       return ans;
}

int inv(LL q) { return pow_mod(q, mod - 2); }

const int modl = mod;
int calc_mst(int n)
{
    static long long mat[105][105];
    memset(mat,0,sizeof(mat));
    for (long long i=1;i<=n;i++)
        for (auto j:G[i])
        if (j>i)
        {
            mat[i][j]--,mat[j][i]--;
            mat[i][i]++,mat[j][j]++;
        }
    auto gauss=[&]()
    {
        long long ans=1;
        for (long long i=2;i<=n;i++)
        {
            for(long long j=i+1;j<=n;j++)
            {
                while(mat[j][i])
                {
                    long long p=mat[i][i]/mat[j][i];
                    for(long long k=i;k<=n;k++)
                        mat[i][k]=(mat[i][k]-mat[j][k]*p%modl+modl)%modl;
                    swap(mat[i],mat[j]);
                    ans=-ans;
                }
            }
            ans*=mat[i][i];
            ans%=modl;
        }
        return (ans+modl)%modl;
    };
    return gauss();
}
