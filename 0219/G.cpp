#include<bits/stdc++.h>
using namespace std;
const int maxn = 501;
long double c[maxn + 5][maxn + 5];
void init()
{
	c[0][0] = 1;
	for (int i = 1; i < maxn; i++)
	{
		c[i][0] = 1;
		for (int j = 1; j <= i; j++)
			c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
	}
}
int main()
{
	int n,k;
	static long double s[505];
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>k;
	long double sums=0;
	for (int i=1;i<=n;i++) cin>>s[i];
    init();
    cout.setf(ios::fixed);
    cout.precision(8);
    for (int i=1;i<=n;i++)
    {
        long double ans=0;
        for (int d=0;d<n-k+1;d++)
        {
            int nxt=i-d;
            if (nxt<1) nxt+=n;
            double dl=s[nxt]*c[n-d-1][k-1]/c[n][k];
            ans+=dl;
        }
        cout<<ans<<" \n"[i==n];
    }
}