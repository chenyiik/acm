#include<cstdio>
#include<cctype>
#include<iostream>
#include<algorithm>
#include<queue>
#define M 1000005
#define LL long long
using namespace std;
void Rd(int &res){
    res=0;
    char c;
    while(c=getchar(),!isdigit(c));
    do{
        res=(res*10)+(c^48);
    }while(c=getchar(),isdigit(c));
}
struct node{
    int id,x;
};
int A[M],B[M];
int main(){
    int T;
    Rd(T);
    while(T--){
        queue<node>Q;
        int i,n;
        LL ans=0;
        Rd(n);
        for(i=1;i<=n;i++){
            Rd(A[i]),Rd(B[i]);
            Q.push((node){i,B[i]});
        }
        for(i=1;i<=n;i++){
            int tmpa=0;
            bool flag=0;
            node me;
            while(!Q.empty()){
                node now=Q.front();
                Q.pop();
                if(now.id==i){
                    flag=1;
                    me=now;
                    continue;
                }
                if(A[i]<=now.x){
                    now.x-=A[i];
                    ans+=A[i];
                    Q.push(now);
                    A[i]=0;
                    break;
                }
                A[i]-=now.x;
                tmpa+=now.x;
                ans+=now.x;
            }
            if(A[i]>0){
                if(flag){
                    LL other=ans-(B[i]-me.x)-tmpa;
                    if(other>=me.x){
                        int d=min(A[i],me.x);
                        ans+=d;
                        A[i]-=d;
                        me.x-=d;
                    }else{
                        int d=min(1LL*A[i],other);
                        me.x-=d;
                        ans+=d;
                        A[i]-=d;
                    }
                }
            }
            if(flag&&me.x!=0)Q.push(me);
        }
        printf("%lld\n",ans);
    }
    return 0;
}
