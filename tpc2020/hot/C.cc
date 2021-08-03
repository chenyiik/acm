#include <cstdio>

using namespace std;

struct Date 
{ 
	static const int day[13];
	int y, m, d; 
	Date(int Y, int M, int D) : y(Y), m(M), d(D) {}
	Date() : Date(2000, 1, 1) {}
	bool is_run() const { return y % 400 == 0 || (y % 4 == 0 && y % 100 != 0); }
	Date &operator++() 
	{
		if (++d > day[m] && !(m == 2 && d == 29 && is_run())) d = 1, m++;
		if (m > 12) m = 1, y++;
		return *this;
	}
	bool operator<(const Date &o) const
	{
		return y != o.y ? y < o.y : m != o.m ? m < o.m : d < o.d;
	}
	int howmuch9() const
	{
		int tot = 0, num = y * 10000 + m * 100 + d;
		for ( ; num; num /= 10) tot += num % 10 == 9 ? 1 : 0;
		return tot;
	}
	int map() const { return (y - 2000) * 12 * 31 + (m - 1) * 31 + d; }
};

const int Date::day[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main()
{
	static int pre[int(3e6)], last = 0;
	for (Date i = Date(2000, 1, 1); i < Date(10000, 1, 1); ++i)
	{
		int now = i.map();
		pre[now] = pre[last] + i.howmuch9();
		last = now;
	}
	int t; scanf("%d", &t);
	while (t--)
	{
		Date a, b; scanf("%d%d%d%d%d%d", &a.y, &a.m, &a.d, &b.y, &b.m, &b.d);
		printf("%d\n", pre[b.map()] - pre[a.map()] + a.howmuch9());
	}
	return 0;
}
