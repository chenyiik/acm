#include <stdio.h>
#include <string.h>

int main()
{
	puts("## hdu");
	static const int date[10] = {722, 724, 729, 731, 805, 807, 812, 814, 819, 821};
	const int maxnu = 1013;
	printf("| [log](https://docs.qq.com/sheet/DWW9aU2VObHV2a2ph?preview_token=&tab=BB08J2&coord=A1A0A0) |");
	for (int i = 1001; i <= 1013; i++)
		printf(" %d |", i - 1000);
	puts("");
	printf("| :-: |");
	for (int i = 1001; i <= 1013; i++)
		printf(" :-: |");
	puts("");
	static char st[500];
	scanf("%s", st);
	for (int i = 0; i < 10; i++)
	{
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
			if (strlen(st) > 4)
				break;
			static char prob[10], ac[5];
			strcpy(prob, st);
			scanf("%s%s", st, ac);
			int num;
			sscanf(st, "%d", &num);
			if (ac[0] == '-')
				printf(" |");
			else if (num < 300)
				printf(" %s |", st);
			else
				printf(" [%s](%s%s) |", st, url, prob);
			d++;
		}
		while (d++ <= maxnu)
			printf(" - |");
		puts("");
		if (b == 0)
			break;
	}
	return 0;
}
