#include<bits/stdc++.h>
using namespace std;
struct scorerank
{
    long long down,up;
    long long get(int day)
    {
        return up*day-down;
    }
};
vector<scorerank> score2rank;
vector<long long> score,sum;
vector<long long> upd;
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    cout.setf(ios::fixed);cout.precision(9);
    int n,w;
    cin>>n>>w;
    score2rank.resize(w+1,{0,0});
    sum.resize(n+1,w);score.resize(n+1,0);
    for (int i=1;i<=w;i++)
    {
        int k;cin>>k;
        upd.clear();
        while (k--)
        {
            int tmp;
            cin>>tmp;
            upd.push_back(tmp);
        }
        for (auto x:upd) sum[x]+=score2rank[score[x]].get(i-1);
        for (auto x:upd) score2rank[score[x]].down+=i-1,score2rank[score[x]++].up++;
        for (auto x:upd) sum[x]-=score2rank[score[x]].get(i-1);
    }
    for (int i=1;i<=n;i++)
    {
        sum[i]+=score2rank[score[i]].get(w);
        cout<<double(sum[i])/double(w)<<endl;
    }
}