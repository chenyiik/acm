#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#define M 100005
#define SM 50
using namespace std;
char str[M];
char ans[M];
int cnt[SM];
int L[SM],R[SM];
int sum[SM][M];
queue<int>Q[SM];
int main(){
	int i,j,n,k;
	while(scanf("%s %d",str,&k)!=EOF){
		n=strlen(str);
		//printf("%d %d\n",n,k);
		for(i=0;i<26;i++){
			scanf("%d %d",&L[i],&R[i]);
			sum[i][n]=0;
			cnt[i]=0;
			while(!Q[i].empty())Q[i].pop();
		}
		for(i=n-1;i>=0;i--)
			for(j=0;j<26;j++){
				sum[j][i]=sum[j][i+1]+(str[i]==(j+'a'));
			}
		for(i=0;i<n;i++)
			Q[str[i]-'a'].push(i);
		bool flag=1;
		//puts("");
		for(int ap=0;ap<k;ap++){
			int x=-1,p=-1;
			for(i=0;i<26;i++){
				if(cnt[i]>=R[i]||Q[i].empty())continue;
				p=Q[i].front();
				//printf("%d %d\n",i,p);
				cnt[i]++;
				bool flag2=1;
				int tmp=0,tmp2=0;
				for(j=0;j<26;j++){
					tmp+=max(0,L[j]-cnt[j]);
					tmp2+=min(sum[j][p+1],R[j]-cnt[j]);
					if(sum[j][p+1]+cnt[j]<L[j]){
						flag2=0;
						break;
					}
				}
				if(tmp2<k-ap-1)flag2=0;
				if(tmp>k-ap-1)flag2=0;
				if(!flag2){
					cnt[i]--;
				}else{
					x=i;
					break;
				}
			}
			//printf("\t%d\n",x);
			if(x<0){
				flag=0;
				break;
			}
			ans[ap]='a'+x;
			for(i=0;i<26;i++)
				while(!Q[i].empty()&&Q[i].front()<=p)
					Q[i].pop();
		}
		ans[k]='\0';
		if(!flag)puts("-1");
		else puts(ans);
	}
	return 0;
}
