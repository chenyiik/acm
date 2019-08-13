#include <stdio.h>
#include <string.h>

int main()
{
	//freopen("nowcoder.txt", "r", stdin);
	//freopen("nowcoder.md", "w", stdout);
	//FILE *file = fopen("nowcoder.ac", "r");
	puts("## nowcoder");
	static const int date[10] = {718, 720, 725, 727, 801, 803, 808, 810, 815, 817};
	const char maxch = 'K';
	printf("| [log](https://docs.qq.com/sheet/DWW9aU2VObHV2a2ph?preview_token=&tab=BB08J2&coord=A1A0A0) |");
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
		//static char aa[30], ab[30], ac[30];
		//fscanf(file, "%s%s%s", aa, ab, ac);
		printf("| [0%d](%s) |", date[i], st);
		static char url[100];
		strcpy(url, st);
		for (int i = strlen(url) - 1; url[i] != '#'; i--)
			url[i] = 0;
		url[strlen(url) - 1] = '/';
		char c = 'A';
		int b;
		while ((b = ~scanf("%s", st)))
		{
			if (strcmp(st, "EOF") == 0)
			{
				b = 0;
				break;
			}
			if (strlen(st) > 1)
				break;
			static char ac[5];
			scanf("%s%s", st, ac);
			int num;
			sscanf(st, "%d", &num);
			if (ac[0] == '-')
				printf(" |");
			else if (num < 300)
				printf(" %s |", st);
			else
				printf(" [%s](%s%c) |", st, url, c);
			c++;
		}
		while (c++ <= maxch)
			printf(" - |");
		puts("");
		if (b == 0)
			break;
	}
	//fclose(file);
	return 0;
}
