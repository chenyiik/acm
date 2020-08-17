#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <queue>

using namespace std;

int main()
{
	int t = 0;
	scanf("%d", &t);
	while (t--)
	{
		long long n;
		scanf("%lld", &n);
		set<long long> S;
		priority_queue<long long> Q;
		//while (n)
		Q.push(n);
		S.insert(n);
		while (!Q.empty())
		{
			long long p = Q.top();
			//cout << p << endl;
			if (p == 1)
				break;
			while (!Q.empty() && Q.top() == p)
				Q.pop();
			long long b = p / 2;
			long long a = p - b;
			S.insert(a), Q.push(a);
			if (b)
				S.insert(b), Q.push(b);
		}
		S.insert(1);
		//cout << "aaa" << endl;
		vector<long long> v;
		for (auto i : S)
			v.push_back(i);
		//cout << endl;
		//for (auto i : v)
			//cout << i << ' ';
		//cout << endl;
		printf("%d\n-1 -1\n", v.size());
		for (int i = 1; i < v.size(); i++)
		{
			long long b = v[i] / 2, a = v[i] - b;
			//cout << "\t\t" << b << ' ' << a << endl;
			int j = 0;
			for ( ; j < i; j++)
			{
				if (v[j] == b)
					break;
			}
			int k = j;
			for ( ; j < i; j++)
			{
				if (v[j] == a)
					break;
			}
			printf("%d %d\n", j, k);
		}
		printf("%d\n", v.size() - 1);
	}
	return 0;
}
