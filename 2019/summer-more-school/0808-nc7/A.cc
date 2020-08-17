#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>

using namespace std;

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		string s;
		cin >> s;
		vector<string> v;
		for (char c : s)
		{
			if (v.empty() || (c == '0' && v.back().back() == '1'))
				v.push_back(string(1, c));
			else
				v.back() += c;
		}
		vector<string> S;
		while (!v.empty())
		{
			S.push_back(v.back());
			v.pop_back();
			while (S.size() > 1 && S[S.size() - 1] <= S[S.size() - 2])
			{
				S[S.size() - 2] = S[S.size() - 1] + S[S.size() - 2];
				S.pop_back();
			}
		}
		while (!S.empty())
		{
			cout << S.back() << " \n"[S.size() == 1];
			S.pop_back();
		}
	}
	return 0;
}
