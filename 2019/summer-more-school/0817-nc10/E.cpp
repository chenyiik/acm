#include<cstdio>
#include<algorithm>
#define M 1000005
using namespace std;
struct node{
    int x,y;
}A[M];
int n,k;
int rot[]={1,0,0,-1};
bool cmp(node a,node b){
    //printf("(%d,%d) (%d,%d)\n",a.x,a.y,b.x,b.y);
    int ai=-1,bi=-1;
    int id[]={0,3,1,2};
    int LX=1,LY=1,RX=(1<<k),RY=(1<<k);
    while(LX<RX){
        int midx=(LX+RX)>>1;
        int midy=(LY+RY)>>1;
        ai=(a.x>midx)+(a.y>midy)*2;
        bi=(b.x>midx)+(b.y>midy)*2;
        //printf("(%d,%d)->(%d,%d)= %d %d\n",LX,LY,RX,RY,ai,bi);
        if(ai==bi){
            if(id[ai]==0)
                swap(id[1],id[2]);
            else if(id[ai]==3)
                swap(id[0],id[3]);
            if(ai==1||ai==3)LX=midx+1;
            else RX=midx;
            if(ai==2||ai==3)LY=midy+1;
            else RY=midy;
        }else return id[ai]<id[bi];
    }
    return 0;
}
/*void solve(int L,int R,int k,int dir){
    if(L==R)return;
}*/
int main(){
    int i;
    scanf("%d %d",&n,&k);
    for(i=1;i<=n;i++)
        scanf("%d %d",&A[i].y,&A[i].x);
    sort(A+1,A+n+1,cmp);
    for(i=1;i<=n;i++)
        printf("%d %d\n",A[i].y,A[i].x);
    return 0;
}
