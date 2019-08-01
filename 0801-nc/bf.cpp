#include<bits/stdc++.h>
using namespace std;
int x[1000001];
int main()
{
    int a,b;
    cin>>x[0]>>x[1]>>a>>b;
    for (int i=2;i<=10000;i++) x[i]=a*x[i-1]+b*x[i-2];
    int n,modl;
    cin>>n>>modl;
    cout<<x[n]%modl<<endl;
}