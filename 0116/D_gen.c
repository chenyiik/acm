#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	srand(time(NULL));
	int n = rand() % 7 + 1, k = rand() % n;
	printf("%d %d\n", n, k);
	while (n--)
	{
		int m = rand() % 7;
		printf("%d ", m);
		while (m--)
			printf("%d ", rand() % 11);
		puts("");
	}
	return 0;
}
