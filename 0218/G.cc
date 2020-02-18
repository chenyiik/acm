#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <stack>
#include <queue>
#include <utility>

using namespace std;

char _s[25], _t[25];
map<string, int> animal_2_int;
vector<string> int_2_animal;
bool rel[205][205];
const int maxn = int(1e5) + 5;
int que[maxn], fwd[maxn];
queue<pair<int, int>> Q[205];

int main()
{
	int S, L, N; scanf("%d%d%d", &S, &L, &N);
	for (int i = 0; i < S; i++)
		scanf("%s", _s), animal_2_int[string(_s)] = 0;
	for (auto &i : animal_2_int)
	{
		i.second = int_2_animal.size();
		int_2_animal.push_back(i.first);
	}
	while (L--)
	{
		scanf("%s%s", _s, _t);
		int s = animal_2_int[string(_s)], t = animal_2_int[string(_t)];
		rel[s][t] = rel[t][s] = true;
	}
	que[0] = S;
	for (int i = 1; i <= N; i++)
		scanf("%s", _s), que[i] = animal_2_int[_s];
	for (int i = 0; i < S; i++)
	{
		stack<int> st;
		for (int j = N; j >= 0; j--)
		{
			if (st.empty() && que[j] != i) continue;
			else if (que[j] == i) st.push(j);
			else if (!rel[que[j]][i])
				while (!st.empty()) fwd[st.top()] = j + 1, st.pop();
		}
	}
	for (int i = 1; i <= N; i++)
		Q[que[i]].push(make_pair(fwd[i], i));
	int tot = 0;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 0; j < S; j++)
			while (!Q[j].empty() && Q[j].front().first == i)
			{
				printf("%s%c", int_2_animal[j].c_str(), " \n"[++tot == N]);
				Q[j].pop();
			}
	}
	/*
	for (int i = 1; i <= N; i++)
		cout << i << ' ';
	cout << endl;
	for (int i = 1; i <= N; i++)
		cout << que[i] << ' ';
	cout << endl;
	for (int i = 1; i <= N; i++)
		cout << fwd[i] << ' ';
	cout << endl;
	*/
	return 0;
}
