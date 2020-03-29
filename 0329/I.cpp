#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

const int maxn = int(2e5) + 5, maxm = int(1e5) + 5;
pair<int, int> p[maxn];
vector<int> a[maxm];
vector<int> b[maxm];
int n;
int up[100050],down[100050];
int f1()
{
    int ans = 0;
    for (int i=1;i<=n;i++)
        up[p[i].first]++,down[p[i].second]++;
    for (int i=1;i<=100000;i++) up[i]+=up[i-1],down[i]+=down[i-1];
    for (int i=1;i<=n;i++) ans=max(ans,up[p[i].second-1]-down[p[i].first]);
    return ans;
}

int f2()
{
    int ans = 0, now = 0;
    for (int i = 1; i <= 100000; i++)
    {
        now += a[i].size() - b[i].size();
        ans = max(ans, now);
    }
    return ans;
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d%d", &p[i].first, &p[i].second);
        a[p[i].first].push_back(i);
        b[p[i].second].push_back(i);
    }
    printf("%d %d\n", f1(), f2());
    return 0;
}
