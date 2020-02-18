#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

pair<string, int> max_animal;

int main()
{
	int n; scanf("%d", &n);
	map<string, int> M;
	for (int i = 0; i < n; i++)
	{
		static char s[int(2e5) + 5];
		scanf("%s", s);
		string str(s);
		auto it = M.find(s);
		if (it == M.end())
			M[str] = 1;
		else if (++(it->second) > max_animal.second)
			max_animal = *it;
	}
	if (max_animal.second * 2 > n)
		puts(max_animal.first.c_str());
	else
		puts("NONE");
	return 0;
}
