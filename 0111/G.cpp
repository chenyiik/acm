#include<bits/stdc++.h>
using namespace std;
map<int,bool> used;
int main()
{
    int n,m;
    while (cin>>n>>m)
    {
        used.clear();
        for (int i = 1; i <= n; i++)
        {
            int x;
            cin >> x;
            used[x] = 1;
        }
        int time[1050];
        for (int i = 1; i <= m; i++) cin >> time[i];
        for (int gap=0;gap<=1000;gap++)
        {
            bool ok=true;
            for (int i=1;i<=m;i++)
                ok=ok&&(!used[time[i]+gap]);
            if (ok)
            {
                cout<<gap<<endl;break;
            }
        }
    }
}