#include <cmath>
#include <random>
#include <string>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <unordered_set>
using namespace std;
typedef long long LL;

const int N = 10;
mt19937_64 gen(19260817);
unordered_set<LL> Set;

int Rand(int p = 1000000000)
{
	return gen() % p + 1;
}

int Rand(int l, int r)
{
	return l + Rand(r - l + 1) - 1;
}

void PrintSample()
{
	cout << "8" << endl;
	cout << "0 0" << endl;
	cout << "0 1" << endl;
	cout << "-1 0" << endl;
	cout << "0 -1" << endl;
	cout << "1 1" << endl;
	cout << "1 -1" << endl;
	cout << "-1 1" << endl;
	cout << "-1 -1" << endl;
}

inline LL Encode(int x, int y, int LIM)
{
	return 1LL * (x + LIM) * (LIM * 2 + 1) + (y + LIM);
}

void MakeData(int id, int maxn, int maxw)
{
	int n = Rand(maxn / 2 + 1, maxn);
	cout << n << endl;
	for (int i = 1, x, y; i <= n; i ++)
	{
		do
		{
			x = Rand(-maxw, maxw), y = Rand(-maxw, maxw);
		} while (Set.count(Encode(x, y, maxw)));
		cout << x << ' ' << y << endl;
		Set.insert(Encode(x, y, maxw));
	}
	
}

int main()
{
	streambuf *back_up = cout.rdbuf();
	for (int i = 0; i <= N; i ++)
	{
		string filename = to_string(i) + ".in";
		ofstream fout(filename.c_str());
		cout.rdbuf(fout.rdbuf());
		
		if (i == 0) PrintSample();
		else MakeData(i, 1000, 1000000000);
		
		cerr << "Make " << filename << endl;
	}
	cout.rdbuf(back_up);
	return 0;
}
