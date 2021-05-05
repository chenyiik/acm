#include<cstdio>
#include<algorithm>
#include<vector>
#define M 500005
using namespace std;
char str[M];
struct node{
	int p,x;
};
vector<node>D;
int pos[M];
bool cmp(node a,node b){
	return a.x<b.x;
}
int main(){
	int i,j,n,k,cnt=0,p=0,ans=0;
	scanf("%d %d %s",&n,&k,str);
	for(i=0;i<n;i++)
		if(str[i]=='a'){
			cnt++;
			pos[p++]=i;
		}
	if(cnt==0){
		printf("%d\n",k-1);
		for(i=0;i<k;i++)
			str[i]='a';
		puts(str);
		return 0;
	}else if(cnt==1){
		printf("%d\n",k);
		for(i=pos[0]-1;i>=0&&k>0;i--){
			str[i]='a';
			ans++;
			k--;
		}
		for(i=pos[0]+1;i<n&&k>0;i++){
			str[i]='a';
			ans++;
			k--;
		}
		puts(str);
		return 0;
	}
	for(i=0;i<p-1;i++)
		D.push_back((node){i,pos[i+1]-pos[i]-1});
	sort(D.begin(),D.end(),cmp);
	for(i=0;i<(int)D.size();i++){
		int L=pos[D[i].p],R=pos[D[i].p+1];
		if(D[i].x<=k){
			k-=D[i].x;
			for(j=L+1;j<R;j++)
				str[j]='a';
			ans+=D[i].x+1;
		}else{
			for(j=1;j<=k;j++){
				str[j+L]='a';
				ans++;
			}
			k=0;
			break;
		}
	}
	if(k>0){
		for(i=pos[0]-1;i>=0&&k>0;i--){
			str[i]='a';
			ans++;
			k--;
		}
		for(i=pos[p-1]+1;i<n&&k>0;i++){
			str[i]='a';
			ans++;
			k--;
		}
	}
	printf("%d\n%s\n",ans,str);
	return 0;
}
