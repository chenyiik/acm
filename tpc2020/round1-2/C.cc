#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <map>
#include <string>

using namespace std;

map<string, int> M;

void init();

const int maxn = int(1e5) + 10;
char s[maxn];

int main()
{
	init();
	int _; scanf("%d", &_);
	while (_--)
	{
		int n; scanf("%d%s", &n, s);
		bool bT = false, bP = false, bC = false;
		for (int i = 0; i < n; i++)
		{
			if (s[i] == 'T') bT = true;
			if (s[i] == 'P') bP = true;
			if (s[i] == 'C') bC = true;
		}
		string S(s);
		if (!bT || !bP || !bC)
		{
			puts("Impossible");
			continue;
		}
		int ans = 4;
		for (auto it : M)
		{
			int type = 0;
			if (it.first.size() == 3) type = 1;
			else if (it.first.size() == 5) type = 4;
			else if (it.first[2] == '*') type = 2;
			else if (it.first[1] == '*') type = 3;
			if (type == 1)
			{
				if (S.find(it.first) != string::npos)
					ans = min(ans, it.second);
			}
			else if (type == 2)
			{
				int p = S.find(it.first.substr(0, 2));
				if (p == string::npos) continue;
				for (int i = p + 3; i < n; i++)
					if (S[i] == it.first[3]) { ans = min(ans, it.second); break; }
			}
			else if (type == 3)
			{
				int p = S.rfind(it.first.substr(2, 2));
				if (p == string::npos) continue;
				for (int i = p - 2; i >= 0; i--)
					if (S[i] == it.first[0]) { ans = min(ans, it.second); break; }
			}
			else if (type == 4)
			{
				for (int i = 0, j = 0; i < n; i++)
				{
					if (S[i] == it.first[j]) i++, j += 2;
					if (j == 6) { ans = min(ans, it.second); break; }
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}

void init()
{
	M["TPC"] = 0; M["TP*C"] = 1; M["T*PC"] = 1; M["T*P*C"] = 2; 
	M["TCP"] = 1; M["TC*P"] = 2; M["T*CP"] = 1; M["T*C*P"] = 2; 
	M["PTC"] = 1; M["PT*C"] = 1; M["P*TC"] = 2; M["P*T*C"] = 2; 
	M["PCT"] = 2; M["PC*T"] = 2; M["P*CT"] = 2; M["P*C*T"] = 2; 
	M["CTP"] = 2; M["CT*P"] = 2; M["C*TP"] = 2; M["C*T*P"] = 2; 
	M["CPT"] = 1; M["CP*T"] = 2; M["C*PT"] = 2; M["C*P*T"] = 3;
}
