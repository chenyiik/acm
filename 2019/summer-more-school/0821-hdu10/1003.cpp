<<<<<<< HEAD
#include<bits/stdc++.h>
const double eps=1e-6;
int dcmp(double x,double y)
{
    if ((x-y)>eps) return 1;
    if (fabs(x-y)<eps) return 0;
    return -1;
}
using namespace std;
int main()
{
    int T;
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>T;
    while (T--)
    {
        static double pro[10050];
        int n;
        cin>>n;
        for (int i=1;i<=n;i++) cin>>pro[i];
        sort(pro+1,pro+n+1);
        int x=-1;
        for (int i=1;i<=n;i++)
            if (dcmp(pro[i],0.5)==1 && x==-1) {x=i;break;}
        if (x==-1) x=n+1;
        double pp=0;
        double pref=1.0;
        for (int i=1;i<x;i++)
        {
            pp=pref*pro[i]+pp*(1-pro[i]);
            pref*=(1.0-pro[i]);
        }
        double mxp=0;
        for (int i=x;i<=n;i++) mxp=max(mxp,pro[i]);
        printf("%.12f\n",max(pp,mxp));
=======
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
>>>>>>> b64a12bb4e63070f6828cbb1895a2bf56a62f462
    }
    return 0;
}