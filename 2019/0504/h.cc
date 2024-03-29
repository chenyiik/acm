#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

//123
//456
//789
// 0

int a[] = {
	1, 2, 3, 4, 5, 6, 7, 8, 9,
	10, 11, 12, 13, 14, 15, 16, 17, 18, 19,
	20, 22, 23, 25, 26, 28, 29,
	33, 36, 39,
	40, 44, 45, 46, 47, 48, 49,
	50, 55, 56, 58, 59,
	66, 69,
	70, 77, 78, 79,
	80, 88, 89,
	99,
	100, 
	110, 111, 112, 113, 114, 115, 116, 117, 118, 119,
	120, 122, 123, 125, 126, 128, 129,
	133, 136, 139,
	140, 144, 145, 146, 147, 148, 149,
	150, 155, 156, 158, 159,
	166, 169,
	170, 177, 178, 179,
	180, 188, 189,
	199,
	200
};

int f[201] = {
	0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 
	10, 11, 12, 13, 14, 15, 16, 17, 18, 19,
	20, 20, 22, 23, 23, 25, 26, 26, 28, 29,
	33, 33, 33, 33, 33, 36, 36, 36, 39, 39,
	40, 40, 40, 44, 44, 45, 46, 47, 48, 49,
	50, 50, 50, 55, 55, 55, 56, 56, 58, 59,
	66, 66, 66, 66, 66, 66, 66, 66, 69, 69,
	70, 70, 70, 70, 77, 77, 77, 77, 78, 79,
	80, 80, 80, 80, 80, 88, 88, 88, 88, 89,
	99, 99, 99, 99, 99, 99, 99, 99, 99, 99,
	100, 100, 100, 100, 100, 100, 100, 100, 100, 100,
	110, 111, 112, 113, 114, 115, 116, 117, 118, 119,
	120, 120, 122, 123, 123, 125, 126, 126, 128, 129,
	133, 133, 133, 133, 133, 136, 136, 136, 139, 139,
	140, 140, 140, 144, 144, 145, 146, 147, 148, 149,
	150, 150, 150, 155, 155, 155, 156, 156, 158, 159,
	166, 166, 166, 166, 166, 166, 166, 166, 169, 169,
	170, 170, 170, 170, 177, 177, 177, 177, 178, 179,
	180, 180, 180, 180, 180, 188, 188, 188, 188, 189,
	199, 199, 199, 199, 199, 199, 199, 199, 199, 199,
	200
};

int main()
{
	int t = 0;
	scanf("%d", &t);
	while (t--)
	{
		int n = 0;
		scanf("%d", &n);
		//printf("%d\n", f[n]);
		int ans = 1;
		for (int i : a)
		{
			if (abs(i - n) <= abs(ans - n))
			{
				//printf("%d %d %d %d\n", ans, abs(ans - n), i, abs(i - n));
				ans = i;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
