#include<bits/stdc++.h>
using namespace std;
int main()
{
    int l;
    double p,q;
    while (cin>>l>>p>>q){
    static double o_q[100050],pp[100050];
    o_q[0]=1;pp[0]=0;
    for (int i=1;i<=l;i++) {
        o_q[i] = o_q[i - 1] * (1.0 - q);
        pp[i] = pp[i - 1] + o_q[i] * i;
    }
    double ans=0;
    for (int i=0;i<l;i++) ans+=2.0*p*(pp[l-i-1]*q+o_q[l-i]*(l-i))/(1.0-p);
    printf("%.10f\n",ans+(double)(l));}
}