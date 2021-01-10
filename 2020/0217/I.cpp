#include<cstdio>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<utility>
#define M 100005
using namespace std;
int A[M];
struct node{
    int L,R,x;
}tree[M<<2];
void up(int p){
    tree[p].x=max(abs(A[tree[p<<1].R]-A[tree[p<<1|1].L]),max(tree[p<<1].x,tree[p<<1|1].x));
}
void build(int L,int R,int p){
    tree[p].L=L;
    tree[p].R=R;
    if(L==R){
        tree[p].x=0;
        return;
    }
    int mid=(L+R)>>1;
    build(L,mid,p<<1);
    build(mid+1,R,p<<1|1);
    up(p);
}
pair<int,int> query(int x,int H,int p){
    if(tree[p].L==tree[p].R)
        return make_pair(tree[p].L,tree[p].R);
    int mid=(tree[p].L+tree[p].R)>>1;
    if(tree[p].x<=H)
        return make_pair(tree[p].L,tree[p].R);
    if(x<=mid){
        pair<int,int> prL=query(x,H,p<<1);
        if(prL.second==mid&&abs(A[mid]-A[mid+1])<=H){
            pair<int,int> prR=query(x,H,p<<1|1);
            if(prR.first==mid+1)
                return make_pair(prL.first,prR.second);
            else
                return prL;
        }else
            return prL;
    }else{
        pair<int,int> prR=query(x,H,p<<1|1);
        if(prR.first==mid+1&&abs(A[mid]-A[mid+1])<=H){
            pair<int,int> prL=query(x,H,p<<1);
            if(prL.second==mid)
                return make_pair(prL.first,prR.second);
            else
                return prR;
        }else
            return prR;
    }
}
void update(int x,int H,int p){
    if(tree[p].L==tree[p].R){
        A[tree[p].L]=H;
        return;
    }
    int mid=(tree[p].L+tree[p].R)>>1;
    if(x<=mid)update(x,H,p<<1);
    else update(x,H,p<<1|1);
    up(p);
}
int main(){
    int i,n,q;
    scanf("%d %d",&n,&q);
    for(i=1;i<=n;i++)
        scanf("%d",&A[i]);
    build(1,n,1);
    while(q--){
        int op,H;
        scanf("%d %d %d",&op,&i,&H);
        if(op==1)update(i,H,1);
        else{
            pair<int,int> pr=query(i,H,1);
            printf("%d\n",pr.second-pr.first+1);
        }
    }
    return 0;
}
