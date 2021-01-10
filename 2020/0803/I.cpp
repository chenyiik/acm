#include<cstdio>
#include<cstring>
#include<algorithm>
#include<utility>
#define M 100005
using namespace std;
int A[M],B[M],C[M*2];
bool mark[M];
int mark2[M*2];
int tot;
struct node{
    int id,to;
};
vector<node>edge[M*2];
pair<int,int> dfs(int x){
    //printf("\t\t%d\n",x);
    int sum=1;
    bool flag=0;
    for(int i=0;i<(int)edge[x].size();i++){
        node nxt=edge[x][i];
        if(mark[nxt.id])continue;
        if(mark2[nxt.to]){
            flag=1;
            continue;
        }
        //printf("\ty%d %d\n",nxt.id,nxt.to);
        mark[nxt.id]=1;
        mark2[nxt.to]=1;
        pair<int,int> rt=dfs(nxt.to);
        if(rt.first)flag=1;
        sum+=rt.second;
    }
    return make_pair(flag,sum);
}
int main(){
    int T;
    scanf("%d",&T);
    for(int cas=1;cas<=T;cas++){
        memset(mark,0,sizeof(mark));
        memset(mark2,0,sizeof(mark2));
        int i,n,m=0;
        scanf("%d",&n);
        for(i=1;i<=n;i++){
            scanf("%d %d",&A[i],&B[i]);
            C[m++]=A[i];
            C[m++]=B[i];
        }
        sort(C,C+m);
        m=unique(C,C+m)-C;
        for(i=1;i<=m;i++)
            edge[i].clear();
        for(i=1;i<=n;i++){
            A[i]=lower_bound(C,C+m,A[i])-C+1;
            B[i]=lower_bound(C,C+m,B[i])-C+1;
            edge[A[i]].push_back((node){i,B[i]});
            edge[B[i]].push_back((node){i,A[i]});
        }
        /*for(i=1;i<=n;i++){
            printf("\tx%d %d\n",A[i],B[i]);
        }
        for(i=1;i<=m;i++){
            printf("%d: ",i);
            for(int j=0;j<(int)edge[i].size();j++){
                printf("(%d, %d) ",edge[i][j].id,edge[i][j].to);
            }
            puts("");
        }*/
        int ans=0;
        for(i=1;i<=m;i++){
            if(mark2[i])continue;
            mark2[i]=1;
            pair<int,int> rt=dfs(i);
            //printf("\t%d %d\n",rt.first,rt.second);
            ans+=rt.second-1+rt.first;
        }
        printf("Case #%d: %d\n",cas,ans);
    }
    return 0;
}