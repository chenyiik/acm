#include<bits/stdc++.h>
using namespace std;
map<char,int> cost;
map<char,bool> exist;
int main()
{
    int T;
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>T;
    while (T--)
    {
        int la,lf;
        string s,cs;
        cin>>la>>lf;
        cost.clear();
        exist.clear();
        cin>>s>>cs;
        for (int i=0;i<s.size();i++)
            if (!exist[s[i]])
            {
                cost[s[i]]=cs[i]-'0',exist[s[i]]=true;
            }
            else {cost[s[i]]=min(cost[s[i]],cs[i]-'0');}
        string cl;
        cin>>cl;
        int ans=0;
        for (auto ch:cl)
        {
            if (exist[ch])
            {
                ans+=cost[ch];
            }
            else goto fatal;
        }
        cout<<ans<<endl;
        continue;
        fatal:cout<<-1<<endl;
    }
}