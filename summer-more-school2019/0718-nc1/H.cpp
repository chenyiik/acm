#include<bits/stdc++.h>
#include<vector>
using namespace std;
const long long maxn=1e5+50;
const long long modl=(long long)(1e9+7);
long long qpow(long long a,long long b)
{
    long long res=1;
    while (b)
    {
        if (b&1) {res*=a;res%=modl;}
        a=a*a%modl;
        b>>=1;
    }
    return res;
}
struct linear_base
{
    vector<long long> base;
    linear_base() {base.resize(128);}
    linear_base(const linear_base& b) {base=b.base;}
    static long long getbit(int b)
    {
        return (long long)((1LL)<<b);
    }
    bool insert(long long x)
    {
        for (int i=0;i<63;i++)
        if (x&getbit(i))
        {if (base[i]==0) {base[i]=x;return true;} x^=base[i];}
        return false;
    }
};
int main() {
    int n;
    ios::sync_with_stdio(0);cin.tie(0);
    while (cin >> n) {
        static long long a[maxn];
        linear_base all_base;
        vector<long long> inbase, outbase;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            if (all_base.insert(a[i])) inbase.emplace_back(a[i]); else outbase.emplace_back(a[i]);
        }
        long long tmp=qpow(2,outbase.size()-1);
        long long ans = outbase.size() * qpow(2, outbase.size() - 1) % modl;
        linear_base part_base;
        int cnt = 0;
        for (auto x:outbase) if (part_base.insert(x)) cnt++;
        for (auto x:inbase) {
            linear_base tmpbase = part_base;
            int cl = 0;
            for (auto y:inbase) if (y != x) if (tmpbase.insert(y)) ++cl;
            int tmpc = cnt + cl;
            if (!tmpbase.insert(x)) {
                ans += qpow(2, n - tmpc - 1) % modl;
                ans %= modl;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
