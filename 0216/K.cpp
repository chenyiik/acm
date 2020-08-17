#include<cstdio>
#include<iostream>
#define M 100005
#define LL long long
using namespace std;
int A[M];
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int i,n,x,L=0,R=0;
        LL ans=0;
        scanf("%d %d",&n,&x);
        for(i=0;i<n;i++)
            scanf("%d",&A[i]);
        while(A[L]>=x&&L<n)L++;
        R=L-1;
        LL sum=0;
        for(;L<n;L++){
            if(R<L-1){
                R=L-1;
                sum=0;
            }
            while(R+1<n&&A[R+1]+sum<x){
                R++;
                sum+=A[R];
            }
            ans+=R-L+1;
            sum-=A[L];
        }
        cout<<ans<<endl;
    }
    return 0;
}
