#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = 305;
int a[maxn], n;
char start[10];

bool cmp(int a, int b) { return a > b; }

int main()
{
	scanf("%d%s", &n, start);
	for (int i = 0; i < n; i++)
	{
		int x; scanf("%d", &x);
		a[x]++;
	}
	int tot = 0;
	for (int i = 1; i <= 300; i++)
	{
		if (a[i] == 1)
			return puts("Alice"), 0;
		if (a[i] == 2)
			tot++;
	}
	if (0 == strcmp(start, "Alice"))
		puts(tot > 0 ? "Alice" : "Bob");
	else
		puts(tot > 1 ? "Alice" : "Bob");
	/*
	if (0 == strcmp(start, "Alice"))
	{
		for (int i = 1; i <= 300; i++)
			if (a[i] % 3 != 0)
				return puts("Alice"), 0;
		puts("Bob");
	}
	else
	{
		bool flag = true;
		for (int i = 1; i <= 300; i++)
			if (a[i] % 3 == 2 && flag)
				flag = false;
			else if (a[i] % 3 != 0)
				return puts("Alice"), 0;
		puts(flag ? "Alice" : "Bob");
	}
	*/
	return 0;
}
