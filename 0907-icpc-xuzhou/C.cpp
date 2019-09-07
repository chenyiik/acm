#include<bits/stdc++.h>
using namespace std;
int main()
{
    int w;
    cin>>w;
    if (w&1) {cout<<"NO"<<endl;return 0;}
    w/=2;
    if (w>=2) {cout<<"YES"<<endl;return 0;}
    cout<<"NO"<<endl;
    return 0;
}