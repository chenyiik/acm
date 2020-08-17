#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> t[5];
int yunsuanfu[16], kuohaozhi[16];
const int oo = 0x7fffffff;

int calc(int L, int R, int op){
	if(op == '+')
		return L + R;
	else if(op == '-')
		return L - R;
	else if(op == '*')
		return L * R;
	else{
		if(R == 0)
			return -oo;
		if(L % R != 0)
			return -oo;
		else
			return L / R;
	}
}

int h(const vector<int> &t, int u)
{
	int L = -oo, R = -oo;
	if (t[u * 2] == 0)
		L = h(t , u * 2);
	else if(t[u * 2] > 0)
		L = t[u * 2];
	if (t[u * 2 + 1] == 0)
		R = h(t , u * 2 + 1);
	else if(t[u * 2 + 1] > 0)
		R = t[u * 2 + 1];
	if(L == -oo || R == -oo)
		return -oo;
	int result = calc(L, R , yunsuanfu[u]);
	return result;
}

int calc_Score(const vector<int> &t, int u){
	int score = 0;
	if(t[u * 2] == 0){
		score += calc_Score(t, u * 2);
		if((yunsuanfu[u] == '*' || yunsuanfu[u] == '/') && (yunsuanfu[u * 2] == '+' || yunsuanfu[u * 2] == '-') )
			score++;
	}
	if(t[u * 2 + 1] == 0){
		score += calc_Score(t, u * 2 + 1);
		if((yunsuanfu[u] == '*' || yunsuanfu[u] == '/') && (yunsuanfu[u * 2 + 1] == '+' || yunsuanfu[u * 2 + 1] == '-') )
			score++;
	}
	return score;
}

int g(const vector<int> &t)
{
	/*for(int i = 0; i < 16; i++)
		printf("%d ",t[i]);
	puts("");*/
	int ans_Score = +oo;
	for(int i = 0; i < 16; i++){
		if(t[i] == 0){
			for(int j = i + 1; j < 16; j++){
				if(t[j] == 0){
					for(int k = j + 1; k < 16; k++){
						if(t[k] == 0){
							string str="+-*/";
							for(int ii = 0; ii < 4 ; ii++){
								for(int jj = 0; jj < 4; jj++){
									for(int kk=0; kk < 4; kk++){
										yunsuanfu[i] = str[ii];
										yunsuanfu[j] = str[jj];
										yunsuanfu[k] = str[kk];
										int result = h(t, 1);
										int score = calc_Score(t, 1);
										/*if(result > 20)
											printf("%c %c %c: %d\n ",str[ii], str[jj], str[kk], result);*/
										if(result != 24) continue;
										ans_Score = min(ans_Score, score);
									}
								}
							}
							break;
						}
					}
					break;
				}
			}
			break;
		}
	}
	return ans_Score == +oo ? -1 : ans_Score;
}

int f(int a, int b, int c, int d)
{
	t[0] = {-1, 0, 0, d, 0, c, -1, -1, a, b, -1, -1, -1, -1, -1, -1};
	t[1] = {-1, 0, 0, d, a, 0, -1, -1, -1, -1, b, c, -1, -1, -1, -1};
	t[2] = {-1, 0, 0, 0, a, b, c, d, -1, -1, -1, -1, -1, -1, -1, -1};
	t[3] = {-1, 0, a, 0, -1, -1, 0, d, -1, -1, -1, -1, b, c, -1, -1};
	t[4] = {-1, 0, a, 0, -1, -1, b, 0, -1, -1, -1, -1, -1, -1, c, d};
	int ans = +oo;
	for (int i = 0; i < 5; i++)
	{
		int k = g(t[i]);
		if (k != -1)
			ans = min(ans, k);
	}
	return ans == +oo ? -1 : ans;
}

int main()
{
	int a[4];
	int b[]={0,1,2,3};
	int ans = +oo;
	scanf("%d%d%d%d", &a[0], &a[1], &a[2], &a[3]);
	do{
		int nixudui = 0;
		for (int i = 0; i < 4; i++)
		{
			for (int j = i + 1; j < 4; j++)
				if (b[i] > b[j])
					nixudui++;
		}
		int k = f(a[b[0]], a[b[1]], a[b[2]], a[b[3]]);
		if (k != -1)
			ans = min(ans, 2 * nixudui + k);
	}while(next_permutation(b,b+4));
	if(ans == +oo)puts("impossible");
	else printf("%d\n",ans);
	return 0;
}
