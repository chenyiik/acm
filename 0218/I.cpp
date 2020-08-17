#include<bits/stdc++.h>
using namespace std;
int main()
{
    double n1,n2,n3;
    cin>>n1>>n2>>n3;
    double ans=floor((n1+1)*(n2+1)/(n3+1)-1);
    int tans=floor(ans);
    cout<<tans<<endl;
}