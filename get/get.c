#include <stdio.h>
#include <string.h>

void nowcoder(); void hdu(); 
int main() 
{ 
	fprintf(stderr, "\nFucking nowcoder *t...\n");
	nowcoder(); 
	fprintf(stderr, "Nowcoder Fucking complete!\n");
	fprintf(stderr, "\nFucking HDU *t...\n");
	hdu(); 
	fprintf(stderr, "HDU Fucking complete!\n");
	return 0; 
}

void nowcoder()
{
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
			else if (num < 400)
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
}

void hdu()
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
			else if (num < 400)
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
}
