#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int t = 0;
	scanf("%d", &t);
	while (t--)
	{
		int n = 0;
		scanf("%d", &n);
		double nnn = -1e9;
		for (int i = 0; i < n; i++)
		{
			double mmm = 0.0;
			scanf("%lf", &mmm);
			nnn = max(nnn, mmm);
		}
		printf("%.2f\n", nnn);
	}
	return 0;
}
