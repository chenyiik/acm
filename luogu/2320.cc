#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

int main()
{
	int n = 0;
	cin >> n;
	stack<int> S;
	while (n)
	{
		S.push(n / 2 + n % 2);
		n /= 2;
	}
	cout << S.size() << endl;
	while (!S.empty())
	{
		cout << S.top() << ' ';
		S.pop();
	}
	cout << endl;
	return 0;
}
