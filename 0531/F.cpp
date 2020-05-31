#include<cstdio>
#include<algorithm>
#define LL long long
#define M 100005
using namespace std;
struct P{
    int x,y;
    LL z;
}A[M];
int B[M];
struct node{
    int L,R;
    LL x;
}tree[M<<2];
bool cmp(P a, P b){
    if(a.x==b.x)return a.y>b.y;
    return a.x<b.x;
}
void build(int L,int R,int p){
    tree[p].L=L;
    tree[p].R=R;
    tree[p].x=0;
    if(L==R)return;
    int mid=(L+R)>>1;
    build(L,mid,p<<1);
    build(mid+1,R,p<<1|1);
}
void up(int p){
    tree[p].x=max(tree[p<<1].x,tree[p<<1|1].x);
}
LL query(int L,int R,int p){
    if(tree[p].L==L&&tree[p].R==R)
        return tree[p].x;
    int mid=(tree[p].L+tree[p].R)>>1;
    if(R<=mid)return query(L,R,p<<1);
    else if(L>mid)return query(L,R,p<<1|1);
    else return max(query(L,mid,p<<1),query(mid+1,R,p<<1|1));
}
void update(int x,LL a,int p){
    if(tree[p].L==tree[p].R){
        tree[p].x=max(tree[p].x,a);
        return;
    }
    int mid=(tree[p].L+tree[p].R)>>1;
    if(x<=mid)update(x,a,p<<1);
    else update(x,a,p<<1|1);
    up(p);
}
int main(){
    int i,n,p=0;
    LL ans=0;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d %d %lld",&A[i].x,&A[i].y,&A[i].z);
        B[i]=A[i].y;
    }
    sort(B,B+n);
    int m=unique(B,B+n)-B;
    for(i=0;i<n;i++)
        A[i].y=lower_bound(B,B+m,A[i].y)-B+2;
    sort(A,A+n,cmp);
    for(i=0;i<n;i++){
        int j=i+1;
        while(j<n&&A[i].x==A[j].x&&A[i].y==A[j].y){
            A[i].z+=A[j].z;
            j++;
        }
        A[p++]=A[i];
        i=j-1;
    }
    build(1,p,1);
    for(i=0;i<p;i++){
        LL tmp=query(1,A[i].y-1,1);
        ans=max(ans,tmp+A[i].z);
        update(A[i].y,tmp+A[i].z,1);
    }
    printf("%lld\n",ans);
    return 0;
}
