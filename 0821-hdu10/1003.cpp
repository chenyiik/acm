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
    }
    return 0;
}