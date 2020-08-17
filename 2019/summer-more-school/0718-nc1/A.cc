#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

struct P { int value, index; };

const int maxn = int(1e5) + 5;
int a[maxn], b[maxn], n;

int sol()
{
	stack<int> A, B;
	for (int i = 1; i <= n; i++)
	{
		while (!A.empty() && A.top() > a[i])
			A.pop();
		while (!B.empty() && B.top() > b[i])
			B.pop();
		//cout << i << ' ' << A.size() << ' ' << B.size() << endl;
		if (A.size() != B.size())
			return i - 1;
		A.push(a[i]);
		B.push(b[i]);
	}
	return n;
}

int main()
{
	while (~scanf("%d", &n))
	{
		for (int i = 1; i <= n; i++)
			scanf("%d", &a[i]);
		for (int i = 1; i <= n; i++)
			scanf("%d", &b[i]);
		printf("%d\n", sol());
	}
	return 0;
}
