#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

string read()
{
	static char s[105];
	scanf("%s", s);
	return s;
}

int main()
{
	string t = read(), s = read();
	vector<string> v;
	for (int i = 0; i < s.size(); i++)
	{
		for (int j = 0; j < t.size(); j++) if (s[i] != t[j])
		{
			string r = s;
			r[i] = t[j];
			v.push_back(r);
		}
		for (int j = 0; j < t.size(); j++)
		{
			string r = s;
			r.insert(i, string(1, t[j]));
			v.push_back(r);
		}
		string r = s;
		r.erase(i, 1);
		v.push_back(r);
	}
	for (int j = 0; j < t.size(); j++)
	{
		string r = s;
		r.append(string(1, t[j]));
		v.push_back(r);
	}
	sort(v.begin(), v.end());
	int n = unique(v.begin(), v.end()) - v.begin();
	for (int i = 0; i < n; i++)
		puts(v[i].c_str());
	return 0;
}
