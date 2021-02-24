#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

const int maxn = int(2e5) + 5;
int a[maxn], b[4][maxn], n;

int f(const int a[])
{
	int ret = 0x7fffffff;
	for (int i = 1; i < n; i++)
		ret = min(ret, abs(a[i - 1] - a[i]));
	return ret;
}

void show(const int a[])
{
	//cout << f(a) << endl;
	for (int i = 0; i < n; i++)
		printf("%d%c", a[i], " \n"[i + 1 == n]);
}


int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	sort(a, a + n);
	if (n % 2 == 0)
	{
		int m = n / 2;
		for (int i = 0; i < n; i++)
		{
			b[0][i] = a[i / 2 + (i % 2) * m];
			b[1][i] = a[i / 2 + (i % 2 ^ 1) * m];
		}
		if (f(b[0]) >= f(b[1]) && f(b[0]) >= f(b[2]) && f(b[0]) >= f(b[3]))
			show(b[0]);
		else if (f(b[1]) >= f(b[2]) && f(b[1]) >= f(b[3]))
			show(b[1]);
		else if (f(b[2]) >= f(b[3]))
			show(b[2]);
		else
			show(b[3]);
	}
	else
	{
		int m=n>>1;
        int mn=m;
        for(int i=m;i<n;i++) if(a[mn]-a[mn-m]>a[i]-a[i-m]) mn=i;
        int x=mn,y=(mn+m)%n;
        static queue<int> q1,q2;
        for(int i=0;i<n;++++i,x=(x+n-1)%n) q1.push(x);
        for(int i=1;i<n;++++i,y=(y+n-1)%n) q2.push(y);
        for(int i=1;i<=n;i++)
            if(i&1) printf("%d%c", a[q1.front()],' '),q1.pop();
            else printf("%d%c", a[q2.front()],' '),q2.pop();

	}
	return 0;
}
