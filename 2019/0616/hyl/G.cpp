#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>T;
    while (T--)
    {
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        cout<<abs(x1-x2)+abs(y1-y2)<<endl;
    }
    return 0;
}