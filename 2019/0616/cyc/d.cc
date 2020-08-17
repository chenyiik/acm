#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 10;
char s[15];
int a[3];

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		a[0] = a[1] = a[2] = 0;
		for (int i = 0; i < 3; i++)
		{
			scanf("%s", s);
			for (int j = 0; j < N; j++)
				if (s[j] == '1')
					a[i]++;
		}
		sort(a, a + 3, [](int x, int y){return x>y;});
		int tot = a[0] + a[1] + a[2], bit = N;
		vector<int> v;
		while (tot > bit && a[0] && a[1] && a[2])
		{
			tot -= 3, a[0]--, a[1]--, a[2]--, bit--;
			v.push_back(1);
		}
		if (tot <= bit)
		{
			while (tot--)
			{
				v.push_back(1);
				bit--;
			}
			while (bit--)
				v.push_back(0);
		}
		else
		{
			int count = 0;
			while (tot > bit && a[0] && a[1])
				tot -= 2, bit--, a[0]--, a[1]--, count++;
			while (tot--)
				v.push_back(1);
			while (count--)
				v.push_back(0);
		}
		for (auto i : v)
			printf("%d", i);
		puts("");
	}
	return 0;
}
