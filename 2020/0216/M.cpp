#include<bits/stdc++.h>
using namespace std;
const double eps=1e-9;
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    int t;
    cin>>t;
    while (t--)
    {
        int b1,p1,b2,p2;
        cin>>b1>>p1>>b2>>p2;
        if (b1==0||b2==0)
        {
            if (b1) {cout<<"HaHa"<<endl;continue;}
            if (b2) {cout<<"Congrats"<<endl;continue;}
            cout<<"Lazy"<<endl;
            continue;
        }
        double lg1,lg2;
        lg1=(1.0*p1)*log(1.0*b1);
        lg2=(1.0*p2)*log(1.0*b2);
        if (fabs(lg1-lg2)<eps) {cout<<"Lazy"<<endl;continue;}
        if (lg1>lg2) {cout<<"HaHa"<<endl;continue;}
        {cout<<"Congrats"<<endl;continue;}
    }
}