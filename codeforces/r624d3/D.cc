#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <utility>

using namespace std;

template <typename A, typename B, typename C>
class Tuple
{
private:
	pair<A, pair<B, C>> _element;
public:
	A &first;
	B &second;
	C &third;
	Tuple()
		: _element(make_pair(A(), make_pair(B(), C()))),
		first(_element.first), second(_element.second.first),
		third(_element.second.second) { }
	Tuple(const A &a, const B &b, const C &c) 
		: _element(make_pair(a, make_pair(b, c))),
		first(_element.first), second(_element.second.first),
		third(_element.second.second) { }
	Tuple(const Tuple &o) : _element(o._element), 
		first(_element.first), second(_element.second.first),
		third(_element.second.second) { }
	Tuple &operator=(const Tuple &o) 
	{
		_element = o._element;
		return *this;
	}
	bool operator<(const Tuple &o) const { return _element < o._element; }
	friend istream &operator>>(istream &is, Tuple &o)
	{
		is >> o.first >> o.second >> o.third;
		return is;
	}
	friend ostream &operator<<(ostream &os, const Tuple &o)
	{
		os << o.first << ' ' << o.second << ' ' << o.third;
		return os;
	}
};

int main()
{
	int t; scanf("%d", &t);
	while (t--)
	{
		Tuple<int, int, int> input, output;
		cin >> input;
		int ans = 0x7fffffff;
		const int N = 10000 * 2;
		for (int a = 1; a <= N; a++)
		{
			for (int b = a; b <= N; b += a)
			{
				for (int c = b; c <= N; c += b)
				{
					int cnt = abs(input.first - a)
						+ abs(input.second - b)
						+ abs(input.third - c);
					if (cnt < ans)
						ans = cnt, output = Tuple(a, b, c);
				}
			}
		}
		cout << ans << endl << output << endl;
	}
	return 0;
}
