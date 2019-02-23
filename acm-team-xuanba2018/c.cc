#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int main()
{
	int n = 0;
	cin >> n;
	string s;
	getline(cin, s);
	map<string, vector<int>> M;
	for (int i = 1; i <= n; i++)
	{
		getline(cin, s);
		istringstream s_in(s);
		while (s_in)
		{
			string str;
			getline(s_in, str, '/');
			//cout << str << ' ' << i << endl;
			if (str.empty())
				continue;
			M[str].push_back(i);
		}
	}
	for (auto it = M.begin(); it != M.end(); it++)
	{
		cout << it->first << ": ";
		for (int i = 0; i < it->second.size(); i++)
			cout << it->second[i] << ' ';
		cout << endl;
	}
	return 0;
}
