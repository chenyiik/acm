#include<cstdio>
#include<algorithm>
using namespace std;
int A[10];
int main(){
    double x;
    int i,sum=0,tar,ma=0,mi=10000000;
    for(i=0;i<4;i++){
        scanf("%lf",&x);
        A[i]=(int)(x*100+1e-9);
        sum+=A[i];
        if(A[i]>ma)ma=A[i];
        if(A[i]<mi)mi=A[i];
    }
    scanf("%lf",&x);
    tar=(int)(x*100+1e-9);
    if(3*tar<sum-ma){
        puts("impossible");
    }else if(3*tar>=sum-mi){
        puts("infinite");
    }else{
        printf("%.2f\n",(tar*3-sum+ma+mi)/100.0);
    }
    return 0;
}
