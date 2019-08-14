#include<bits/stdc++.h>
using namespace std;
int main()
{
    int m;
    cin>>m;
    for (int i=1;i<=m;i++) cout<<1<<" ";cout<<endl;
    int l=1,r=m/2;
    for (int i=2;i<=m;i++)
    {
        for (int i=1;i<l;i++) cout<<1<<" ";
        for (int i=l;i<=r;i++) cout<<-1<<" ";
        for (int i=r+1;i<=m;i++) cout<<1<<" ";
        cout<<endl;
        l++,r++;
    }
    return 0;
}