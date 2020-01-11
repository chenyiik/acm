#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b)
{
    return b==0?a:gcd(b,a%b);
}
int main()
{
    int n;
    while (cin>>n) {
        string s;
        cin >> s;
        map<char, int> mpl;;
        mpl['a'] = 1;
        mpl['v'] = 2;
        mpl['i'] = 3;
        mpl['n'] = 4;
        int sum[5];
        memset(sum,0,sizeof(sum));
        for (auto ch:s) {
            sum[mpl[ch]]++;
        }
        int sx = 1;
        for (int i = 1; i <= 4; i++) sx *= sum[i];
        int sw = n * n * n * n;
        if (sx == 0) {
            puts("0/1");
            continue;
        }
        int gx = gcd(sw, sx);
        printf("%d/%d\n", sx / gx, sw / gx);
    }
}