#include <stdio.h>
#include <string.h>

int main()
{
	//freopen("nowcoder.txt", "r", stdin);
	//freopen("nowcoder.md", "w", stdout);
	FILE *file = fopen("nowcoder.ac", "r");
	puts("## nowcoder");
	static const int date[10] = {722, 724, 729, 731, 805, 807, 812, 814, 819, 821};
	const int maxnu = 1013;
	printf("| [log](https://docs.qq.com/sheet/DWW9aU2VObHV2a2ph?preview_token=&tab=BB08J2&coord=A1A0A0) |");
	for (int i = 1001; i <= 1013; i++)
		printf(" %d |", i);
	puts("");
	printf("| :-: |");
	for (int i = 1001; i <= 1013; i++)
		printf(" :-: |");
	puts("");
	static char st[500];
	scanf("%s", st);
	for (int i = 0; i < 10; i++)
	{
		static char aa[30], ab[30], ac[30];
		fscanf(file, "%s%s", aa, ab);
		printf("| [0%d](%s) |", date[i], st);
		static char *url = "http://acm.hdu.edu.cn/showproblem.php?pid=";
		int d = 1001;
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
			scanf("%s", st);
			fscanf(file, "%s", ac);
			int num;
			sscanf(st, "%d", &num);
			if (ac[0] == '-')
				printf(" |");
			else if (num < 300)
				printf(" %s |", st);
			else
				printf(" [%s](%s%d) |", st, url, d);
			d++;
		}
		while (d++ <= maxnu)
			printf(" - |");
		puts("");
		if (b == 0)
			break;
	}
	fclose(file);
	return 0;
}
