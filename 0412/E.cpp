#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    int n,k;
    cin>>n>>k;
    if (n<=k||(k&1 && n<=k*2))
    {
        for(int i=1;i<=n;i++) cout<<!(i&1)+1<<" \n"[i==n];
        return 0;
    }
    int bn=1,modl=max((n+k-1)/k,3);
    for (int cir=0;;++cir)
    {
        for (int i=1;i<=min(k,n-bn+1);i++)
            cout<<(vector<int>({2,0})[i%2]+cir)%modl+1<<" ";
        if ((bn+k-1)>=n) break;
        bn+=k;
    }
}