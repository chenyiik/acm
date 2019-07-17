#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <functional>

using namespace std;

const int maxn = int(3e5) + 5;
int a[maxn], b[maxn];

int sol()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (int i = 0; i < n; i++)
		scanf("%d", &b[i]);
	priority_queue<int, vector<int>, greater<int>> S;
	for (int i = 0; i < n; )
	{
		for (int j = i; j < n; j++)
		{
			S.push(a[j]);
			while (!S.empty() && S.top() == b[i])
				S.pop(), i++;
			if (S.empty())
				break;
		}
		if (!S.empty())
			return puts("NO");
	}
	return puts("YES");
}

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
		sol();
	return 0;
}
