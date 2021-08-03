#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = int(1e6) + 1;
bool nprime[maxn];
//bool rp[maxn];

void init()
{
	nprime[0] = nprime[1] = true;
	for (int i = 2; i < maxn; i++) 
		if (!nprime[i])
			for (int j = i * i; j < maxn; j += i)
				nprime[j] = true;
}

const int tenE[] = { 1, 10, 100, 1000, 10000, int(1e5), int(1e6), int(1e7), int(1e8), int(1e9)};
bool fuck(int n)
{
	int bits = 0;
	for (int i = n; i; i /= 10)
		bits++;
	for (int i = 0; i < bits; i++)
	{
		int k = n / tenE[i] + n % tenE[i] * tenE[bits - i];
		if (nprime[k])
			return false;
	}
	return true;
}

//string s[maxn];
string s[100];
int n = 0;

int main()
{
	init();
	for (int i = 0; i < maxn; i++) if (!nprime[i] && fuck(i))
	{
		//rp[i] = true;
		static char tmp[10];
		sprintf(tmp, "%d", i);
		s[n++] = string(tmp);
		//cout << n << ":\t" << i << endl;
	}
	//cout << n << endl;
	string t;
	cin >> t;
	for (int i = n - 1; i >= 0; i--)
	{
		if (t.find(s[i]) != string::npos)
		{
			cout << s[i] << endl;
			return 0;
		}
	}
	cout << -1 << endl;
	/*
	int sum = 0;
	for (int i = 0; i < maxn; i++) if (rp[i])
	{
		cout << i << ' ', sum++;
	}
	cout << endl << sum << endl;
	*/
	return 0;
}
