#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    static string name[11];
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>name[i];
    vector<pair<string,string>> G[1050];
    queue<string> q;
    for(int i=5;i<=n;i++) q.push(name[i]);
    int w=0,b=0;
    string match;
    cin>>match;
    string wo,bo,wd,bd;
    wo=name[1],bo=name[2],wd=name[3],bd=name[4];
    pair<string,string> tmname;
    for(int i=0;i<match.size();++i)
    {
        char r=match[i];
        if(r=='W')
        {
            w++;
            b=0;
            if (!(i>0 && match[i-1]=='W'))
                if (i==0)
                    tmname=make_pair(wo,wd);
                else
                    tmname=make_pair(wd,wo);
            G[w].push_back(tmname);
            q.push(bd);
            bd=bo;
            bo=q.front();
            q.pop();
            swap(wo,wd);
        }else
        {
            b++;
            w=0;
            if (!(i>0 && match[i-1]=='B'))
                if (i==0)
                    tmname=make_pair(bo,bd);
                else
                    tmname=make_pair(bd,bo);
            G[b].push_back(tmname);
            q.push(wd);
            wd=wo;
            wo=q.front();
            q.pop();
            swap(bo,bd);
        }
    }
    for(int i=match.size();i;--i)
    {
        if (G[i].empty()) continue;
        for (auto v:G[i]) cout<<v.first<<" "<<v.second<<endl;
        break;
    }
}