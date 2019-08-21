#include<cstdio>
#include<algorithm>
#define M 10005
using namespace std;
double A[M];
double solve(int n){
    int i;
    double ans=0;
    for(i=1;i<=n;i++)
        scanf("%lf",&A[i]);
    sort(A+1,A+1+n);
    double po=1;
    double mul=0;
    for(i=n;i>=1;i--){
        mul=po*A[i]+(1-A[i])*mul;
        po*=(1-A[i]);
        if(mul>ans)
            ans=mul;
        else
            break;
    }
    return ans;
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n;
        scanf("%d",&n);
        printf("%.12f\n",solve(n));
    }
    return 0;
}