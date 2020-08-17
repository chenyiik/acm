#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    cin>>T;
    while (T--)
    {
        static priority_queue<int> pq=priority_queue<int>();
        int n;
        cin>>n;
        for (int i=1;i<=n;i++)
        {
            int t;
            cin>>t;
            pq.emplace(-t);
        }
        int ans=0;
        while (!pq.empty())
        {
            int t=-pq.top();pq.pop();
            t-=pq.top();pq.pop();
            ans+=t;
            if (pq.empty()) break;
            pq.emplace(-t);
        }
        cout<<ans<<endl;
    }
}