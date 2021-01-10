#include<cstdio>
#define M 100005
#define oo 1000000000
#define LL long long
int A[M],B[M];
LL sum[M],loc[M];
void out(__int128 x)
{
    if (x>=10) out(x/10);
    putchar(x%10+'0');
}
int main(){
    int T;
    scanf("%d",&T);
    for(int cas=1;cas<=T;cas++){
        int i,n;
        scanf("%d",&n);
        for(i=1;i<=n;i++)
            scanf("%d",&A[i]);
        scanf("%d",&B[1]);
        int tmp=B[1];
        for(i=2;i<=n;i++){
            scanf("%d",&B[i]);
            if(B[i]>tmp){
                B[i]=tmp;
            }else tmp=B[i];
        }
        LL ma=-oo,mloc=1;sum[0]=0;
        for(i=1;i<=n;i++){
            sum[i]=sum[i-1]+A[i];
            if(sum[i]>=ma){
                ma=sum[i];
                mloc=i;
            }
            loc[i]=mloc;
        }
        __int128 ans=0;
        int R=loc[n];
        for(i=1;i<=B[1];i++){
            while(B[R]<i)
                R=loc[R-1];
            ans+=(__int128)sum[R];
        }
        printf("Case #%d: %d ",cas,B[1]);
        if (ans<0) {putchar('-'),ans=-ans;}out(ans);puts("");
    }
    return 0;
}