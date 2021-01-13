#include<cstdio>
#include<vector>
#include<algorithm>
#include<queue>
#define M 100005
using namespace std;
vector<int>edge[M],edge2[M];
queue<int>Q;
int st[M],ind[M],ans[M];
int main(){
	int i,j,n,m;
	int aans=0;
	scanf("%d %d",&n,&m);
	while(m--){
		int a,b;
		scanf("%d %d",&a,&b);
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
	for(i=0;i<n;i++)
		for(j=0;j<(int)edge[i].size();j++){
			int y=edge[i][j];
			if(edge[y].size()>edge[i].size()){
				edge2[i].push_back(y);
				ind[y]++;
			}
		}
	for(i=0;i<n;i++)
		ans[i]=1;
	for(i=0;i<n;i++)
		if(ind[i]==0)
			Q.push(i);
	while(!Q.empty()){
		int x=Q.front();
		aans=max(aans,ans[x]);
		Q.pop();
		for(i=0;i<(int)edge2[x].size();i++){
			int y=edge2[x][i];
			if(ans[y]<ans[x]+1)
				ans[y]=ans[x]+1;
			ind[y]--;
			if(ind[y]==0)Q.push(y);
		}
	}
	printf("%d\n",aans);
	return 0;
}
