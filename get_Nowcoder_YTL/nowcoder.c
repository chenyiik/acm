#include <stdio.h>
#include <string.h>

int main()
{
	//freopen("nowcoder.txt", "r", stdin);
	//freopen("nowcoder.md", "w", stdout);
	puts("## nowcoder");
	static const int date[10] = {718, 720, 725, 727, 801, 803, 808, 810, 815, 817}, off = 881;
	const char maxch = 'K';
	printf("| |");
	for (char c = 'A'; c <= maxch; c++)
		printf(" %c |", c);
	puts("");
	printf("| :-: |");
	for (char c = 'A'; c <= maxch; c++)
		printf(" :-: |");
	puts("");
	static char st[100];
	scanf("%s", st);
	for (int i = 0; i < 10; i++)
	{
		printf("| [0%d](%s) |", date[i], st);
		char c = 'A';
		int b;
		while (b = ~scanf("%s", st))
		{
			if (strcmp(st, "EOF") == 0)
			{
				b = 0;
				break;
			}
			if (strlen(st) > 1)
				break;
			scanf("%s", st);
			printf(" %s |", st);
			c++;
		}
		while (c++ <= maxch)
			printf(" - |");
		puts("");
		if (b == 0)
			break;
	}
}
