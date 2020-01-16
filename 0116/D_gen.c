#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	srand(time(NULL));
	int n = rand() % 10 + 1, k = rand() % n;
	printf("%d %d\n", n, k);
	while (n--)
	{
		int m = rand() % 11;
		printf("%d ", m);
		while (m--)
			printf("%d ", rand() % 30);
		puts("");
	}
	return 0;
}
