#include<cstdio>
#define M 1005
char A[M],B[M],K[M];
int main(){
    int i,n,m;
    scanf("%d %d",&n,&m);
    scanf("%s %s",A+m-n+1,B+1);
    int tmp=0;
    while(m-tmp>0){
        for(i=0;i<n;i++){
            if(m-tmp-i-n<=0){
                tmp=m;
                break;
            }
            K[m-tmp-i]=(B[m-tmp-i]-A[m-tmp-i]+26)%26+'a';
            A[m-tmp-i-n]=K[m-tmp-i];
        }
        tmp+=n;
    }
    for(i=1;i<=m;i++)
        putchar(A[i]);
    puts("");
    return 0;
}
