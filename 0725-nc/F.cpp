#include<bits/stdc++.h>

using namespace std;
const int inf = 0x3f3f3f3f;
void Rd(int &res){
    res=0;
    char c;
    while(c=getchar(),!isdigit(c));
    do{
        res=res*10+(c^48);
    }while(c=getchar(),isdigit(c));
}

int main() {
    int T;
    Rd(T);
    while (T--) {
        int n, m;
        Rd(n),Rd(m);
        static int a[1005][1005];
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++) Rd(a[i][j]);
        int ans = 0;
        static int incq[1005][2];
        for (int i = 1; i <= n; i++) {
            static int maxx[1005], minn[1005];
            for (int x = 1; x <= n; x++) minn[x] = -(maxx[x] = -inf);
            for (int j = i; j <= n; j++) {
                for (int x = 1; x <= n; x++) {
                    minn[x] = min(minn[x], a[j][x]);
                    maxx[x] = max(maxx[x], a[j][x]);
                }
                int l = 1, h0 = 0, h1 = 0, t0 = 1, t1 = 1;
                for (int r = 1; r <= n; r++) {
                    while (h0 >= t0 && maxx[r] >= maxx[incq[h0][0]]) h0--;
                    while (h1 >= t1 && minn[r] <= minn[incq[h1][1]]) h1--;
                    incq[++h0][0] = r;
                    incq[++h1][1] = r;
                    while (l <= r && maxx[incq[t0][0]] - minn[incq[t1][1]] > m) {
                        l++;
                        if (incq[t0][0] < l) t0++;
                        if (incq[t1][1] < l) t1++;
                    }
                    ans = max(ans, (r - l + 1) * (j - i + 1));
                }
            }
        }
        cout << ans << endl;
    }
}