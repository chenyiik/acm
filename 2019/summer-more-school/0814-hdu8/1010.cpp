#include<bits/stdc++.h>
using namespace std;
const double eps=1e-8;
struct team
{
    string name;
    int problem;
    int penalty;
    bool operator<(const team &b) const
    {
        if (problem>b.problem) return true;
        if (problem==b.problem && penalty<b.penalty) return true;
        return false;
    }
};
team tmm[100050];
int main()
{
    int T;
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>T;
    while (T--)
    {
        int n,d;
        cin>>n>>d;
        double pr=d*0.1;
        for (int i=1;i<=n;i++) cin>>tmm[i].name>>tmm[i].problem>>tmm[i].penalty;
        sort(tmm+1,tmm+n+1);
        double nr=n*pr;
        double fr=nr-floor(nr);
        if (fabs(fr-0.5)>eps) cout<<"Quailty is very great"<<endl;
        else
        {
            cout<<tmm[int(ceil(nr))].name<<endl;
        }
    }
}