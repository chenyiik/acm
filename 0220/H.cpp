#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    int n,c,b;
    static set<int> z;
    cin>>n>>c>>b;
    for (int i=1;i<=b;i++) {int tmp;cin>>tmp;z.insert(tmp);}
    static bool ans[500050];
    ans[1]=(c&1);
    for (int i=2;i<=n;i++)
    {
        if (z.count(i)) {ans[i]=0;if (ans[i]!=ans[i-1]) c--;continue;}
        if (c)
        {
            ans[i]=!ans[i-1];
            c--;
        }
    }
    for (int i=1;i<=n;i++) cout<<ans[i];cout<<endl;
}