#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=(int)(1e5+5);
struct node{
    int L,R,x;
}tree[maxn<<2];
int lzy[maxn<<2];
void build(int L,int R,int p){
    tree[p].L=L;
    tree[p].R=R;
    tree[p].x=0;
    lzy[p]=0;
    if(L==R)return;
    int mid=(L+R)>>1;
    build(L,mid,p<<1);
    build(mid+1,R,p<<1|1);
}
void up(int p){
    tree[p].x=min(tree[p<<1].x,tree[p<<1|1].x);
}
void down(int p){
    lzy[p<<1]+=lzy[p];
    lzy[p<<1|1]+=lzy[p];
    tree[p<<1].x+=lzy[p];
    tree[p<<1|1].x+=lzy[p];
    lzy[p]=0;
}
void update(int L,int R,int x,int p){
    if(tree[p].L==L&&tree[p].R==R){
        tree[p].x+=x;
        lzy[p]+=x;
        return;
    }
    down(p);
    int mid=(tree[p].L+tree[p].R)>>1;
    if(R<=mid)update(L,R,x,p<<1);
    else if(L>mid)update(L,R,x,p<<1|1);
    else{
        update(L,mid,x,p<<1);
        update(mid+1,R,x,p<<1|1);
    }
    up(p);
}
int query(int L,int R,int p){
    if(tree[p].L==L&&tree[p].R==R)
        return tree[p].x;
    down(p);
    int mid=(tree[p].L+tree[p].R)>>1;
    if(R<=mid)return query(L,R,p<<1);
    else if(L>mid)return query(L,R,p<<1|1);
    else return min(query(L,mid,p<<1),query(mid+1,R,p<<1|1));
}
int main(){
    return 0;
}
