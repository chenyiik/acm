#include<bits/stdc++.h>
using namespace std;
int main()
{
    int v,n;
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>v>>n;
    long double ap=v*n;
    long double p;
    for (int r=1;r<=9;r++)
    {
        p = ap * (0.1 * r);
        long long d = floor(p+0.9999);
        cout << d << " \n"[r == 9];
    }
}