#include<cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#define LL long long
#define M 10000005
LL A[M],B[M];

using namespace std;

bool cmp(int a, int b) { return a > b; }

long long merge_sort(long long  *be, long long *en)
{
	//cout << en - be << endl;
		//puts("aaa");
	if (be + 1 >= en)
		return 0;
	//long long ans = 0;
	long long *mid = be + (en - be) / 2;
	merge_sort(be, mid);
	merge_sort(mid, en);
	//long long ans = min(min(*be * *mid, *be * *(en - 1)), min(*(mid - 1) * *mid, *(mid - 1) * *(en - 1)));
	//long long *p = be, *q = mid;
	//while (p < mid && q < en)
	//{
		//while (p < mid && *q <= *p)
			//p++;
		//ans += mid - p;
		//q++;
	//}
	merge(be, mid, mid, en, B, cmp);
	//for (int i = 0, *pt = be; pt < en; pt++, i++)
		//*pt = B[i];
	memcpy(be, B, sizeof(long long) * (en - be));
	return ans;
}

int main(){
	int i,T;
	scanf("%d",&T);
	while(T--){
		LL n,l,r,x,y,z;
		scanf("%lld %lld %lld %lld %lld %lld %lld %lld",&n,&l,&r,&x,&y,&z,&B[1],&B[2]);
		//scanf("%I64d %I64d %I64d %I64d %I64d %I64d %I64d %I64d",&n,&l,&r,&x,&y,&z,&B[1],&B[2]);
		A[1]=B[1]%(r-l+1)+l;
		A[2]=B[2]%(r-l+1)+l;
		for(i=3;i<=n;i++){
			B[i]=(B[i-2]*x+B[i-1]*y+z)%(1LL<<32);
			A[i]=B[i]%(r-l+1)+l;
		}
		//for(i=1;i<=n;i++)
			//printf("%lld ",A[i]);
			//printf("%I64d ",A[i]);
		//puts("");
		long long ans = merge_sort(A + 1, A + n + 1);
		if (ans == 0)
			puts("IMPOSSIBLE");
		else
			printf("%lld\n", ans);
	}
	return 0;
}

