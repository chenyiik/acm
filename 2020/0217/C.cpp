#include<cstdio>
#define P 1000000007
#define LL long long
int quick(int x,LL a){
    int res=1;
    while(a>0){
        if(a&1)res=1LL*res*x%P;
        a>>=1;
        x=1LL*x*x%P;
    }
    return res;
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        LL n;
        scanf("%lld",&n);
        int ans=(1LL*(n-3)%P*quick(2,n)%P+n%P+3)%P;
        printf("%d\n",ans);
    }
    return 0;
}
