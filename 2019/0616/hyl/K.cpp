#include<bits/stdc++.h>
using namespace std;
set<int> ans,last,tmp;
int main()
{
    int T;
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>T;
    while (T--)
    {
        int n;
        cin>>n;
        static int a[int(1e5)+50];
        for (int i=1;i<=n;i++) cin>>a[i];
        ans.clear();last.clear();
        for (int j=1;j<=n;j++)
        {
            tmp.clear();
            tmp.insert(a[j]);
            for (auto x:last) tmp.insert(x|a[j]);
            for (auto x:tmp) ans.insert(x);
            last=move(tmp);
        }
        cout<<ans.size()<<endl;
    }
}