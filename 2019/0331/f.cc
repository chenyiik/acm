#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

const int sign = 0, digit = 1, L = 2, R = 3;

int g(char c)
{
	if (c == ')')
		return R;
	else if (c == '(')
		return L;
	else if (isalpha(c))
		return digit;
	else
		return sign;
}

bool f(const char *s, int n)
{
	int k = 0;
	int gg = g(s[0]);
	if (gg == sign || gg == R)
		return false;
	if (gg == L)
		k++;
	for (int i = 1; i < n; i++)
	{
		int ff = gg;
		gg = g(s[i]);
		//cerr << ff << ' ' << gg << endl;
		if (gg == sign)
		{
			if (ff == sign || ff == L)
				return false;
		}
		else if (gg == digit)
		{
			if (ff == digit || ff == R)
				return false;
		}
		else if (gg == L)
		{
			if (ff == digit || ff == R)
				return false;
			k++;
		}
		else if (gg == R)
		{
			if (ff == sign || ff == L)
				return false;
			if (--k < 0)
				return false;
		}
	}
	if (g(s[n - 1]) == sign || k > 0)
		return false;
	return true;
}

bool h(const char *s, int n)
{
	stack<bool> S;
	S.push(false);
	for (int i = 0; i < n; i++)
	{
		int gg = g(s[i]);
		if (gg == sign)
		{
			if (S.top())
				return false;
			S.top() = true;
		}
		else if (gg == L)
			S.push(false);
		else if (gg == R)
		{
			if (!S.top())
				return false;
			S.pop();
		}
	}
	return S.top();
}

int main()
{
	const int N = static_cast<int>(1e4);
	static char ss[N];
	fgets(ss, N - 5, stdin);
	static char s[N];
	int n = 0;
	for (char *p = ss; *p != 0; p++)
	{
		if (isalpha(*p) || *p == '(' || *p == ')' || *p == '+' || *p == '-' || *p == '*' || *p == '/' || *p == '%')
			s[n++] = *p;
	}
	cerr << s << ' ' << n << endl;
	if (!f(s, n))
		return puts("error"), 0;
	static char t[N];
	int m = 0;
	for (int i = 0; i < n; i++)
		if (g(s[i]) != digit)
			t[m++] = s[i];
	cerr << t << ' ' << m << endl;
	puts(h(t, m) ? "proper" : "improper");
	return 0;
}
