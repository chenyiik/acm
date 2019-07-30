#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

struct P
{
	stack<int> S;
	void push(int x)
	{
		//while (!S.empty() && S.top() > x)
			//S.pop();
		if (S.empty() || S.top() <= x)
			S.push(x);
	}
	int size() const { return S.size(); }
};

int main()
{
	int t = 0;
	scanf("%d", &t);
	while (t--)
	{
		//const int N = static_cast<int>(1e6) + 5;
		//static int a[N];
		int n = 0;
		scanf("%d", &n);
		P S;
		for (int i = 0; i < n; i++)
		{
			//scanf("%d", &a[i]);
			int x = 0;
			scanf("%d", &x);
			S.push(x);
		}
		printf("%d\n\n", S.size());
	}
	return 0;
}
