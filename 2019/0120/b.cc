#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

#define white false
#define black true

#define strong_black 2
#define weekly_black 1
#define no_color 0

using namespace std;

struct P
{
	bool color;
	unsigned ip;
	int snet;
	bool operator[](int x) const { return ip & (1U << (32 - x)); }
};

const int maxN = static_cast<int>(2e5) + 5;
P a[maxN];

struct R
{
	int color;
	int left, right;
};

const int maxM = static_cast<int>(2e6) + 5;
R tree[maxM];
int m = 0;

int main()
{
	int n = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		static char str[100];
		scanf("%s", str);
		if (str[0] == '+')
			a[i].color = white;
		else
			a[i].color = black;
		unsigned u, v, w, x, y;
		if (sscanf(str + 1, "%u%u%u%u%u", &u, &v, &w, &x, &y) == 5)
			a[i].snet = y;
		else
			a[i].snet = 32;
		a[i].ip = (u << 24) + (v << 16) + (w << 8) + x;
	}
	tree[m++] = {weekly_black, -1, -1};
	for (int i = 0; i < n; i++)
	{
		if (a[i].color == white)
			continue;
		int cnt = 0;
		for (int j = 1; j <= a[i].snet; j++)
		{
			bool x = a[i][j];
			if (!x)
			{
				if (tree[cnt].left == -1)
				{
					tree[cnt].left = m;
					tree[m++] = {weekly_black, -1, -1};
				}
				cnt = tree[cnt].left;
			}
			else
			{
				if (tree[cnt].right == -1)
				{
					tree[cnt].right = m;
					tree[m++] = {weekly_black, -1, -1};
				}
				cnt = tree[cnt].right;
			}
		}
		tree[cnt].color = strong_black;
	}
	for (int i = 0; i < n; i++)
	{
		if (a[i].color == black)
			continue;
		int cnt = 0;
		for (int j = 1; j <= a[i].snet; j++)
		{
			bool x = a[i][j];
			if (tree[cnt].color == weekly_black)
				tree[cnt].color = no_color;
			if (!x)
			{
				if (tree[cnt].left == -1)
				{
					tree[cnt].left = m;
					tree[m++] = {weekly_black, -1, -1};
				}
				if (tree[cnt].color == weekly_black) {
					if (tree[cnt].right == -1)
					{
						tree[cnt].right = m;
						tree[m++] = {weekly_black, -1, -1};
					}
				}
				cnt = tree[cnt].left;
				if (tree[cnt].color == strong_black)
				{
					return puts("-1"), 0;
				}
			}
			else
			{
				if (tree[cnt].right == -1)
				{
					tree[cnt].right = m;
					tree[m++] = {weekly_black, -1, -1};
				}
				if (tree[cnt].color == weekly_black) {
					if (tree[cnt].left == -1)
					{
						tree[cnt].left = m;
						tree[m++] = {weekly_black, -1, -1};
					}
				}
				cnt = tree[cnt].right;
				if (tree[cnt].color == strong_black)
				{
					return puts("-1"), 0;
				}
			}
		}
	}
	return 0;
}
