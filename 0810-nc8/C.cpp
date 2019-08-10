#include<cstdio>
#define M 4096
int A[M][M];
void Prt(int n){
    if(n==1)return;
    int mid=n/2;
    Prt(mid);
    int i,j;
    for(i=1;i<=mid;i++){
        for(j=1;j<=mid;j++){
            A[i][j+mid]=A[i][j];
            A[i+mid][j]=A[i][j];
            A[i+mid][j+mid]=-A[i][j];
        }
    }
}
int main(){
    int m;
    A[1][1]=1;
    scanf("%d",&m);
    Prt(m);
    for(int i=1;i<=m;i++,putchar('\n'))
        for(int j=1;j<=m;j++)
            printf("%d ",A[i][j]);
    return 0;
}
