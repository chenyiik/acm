#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int init(long long k, char *t)
{
	static int r[100];
	int n = 0;
	do
	{
		r[n++] = k % 2;
		k >>= 1;
	} while (k > 0);
	for (int i = 0; i < n; i++)
		t[i] = r[n - i - 1] == 1 ? '1' : '0';
	t[n] = '\0';
	return n;
}

int main()
{
	long long k = 0;
	static char t[100], s[100];
	scanf("%lld%s", &k, s);
	int n = init(k, t);
	//cout << t << endl;
	int m = strlen(s);
	int i = 0;
	for (int j = 0; i < n && j < m; j++)
	{
		if (t[i] == '1' || (t[i] == '0' && s[j] == '0'))
			i++;
	}
	//while (i < n && j < m)
	//{
		//if (t[i] == '1')
			//i++, j++;
		//else //if(t[i] == '0')
		//{
			//if (s[j] == '0')
				//i++, j++;
			//else
				//j++;
		//}
	//}
	printf("%d\n", max(0, (i == n ? m - n : m - (n - 1)))); 
	return 0;
	//100000000000000000000000000000000000000000000000000000000000
}
