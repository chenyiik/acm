#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    double n,a,b;
    cin>>n>>a>>b;
    cout.precision(9);cout.setf(ios::fixed);
    cout<<n+a*b/100-a*(100-b)/100<<endl;
}