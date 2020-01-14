#include<bits/stdc++.h>
using namespace std;
int main()
{
    int c,p,s;
    cin>>c>>p>>s;
    static vector<string> h;
    static map<string,int> scc,pass,score;
    for (int i=0;i<c;i++)
    {
        string handle;
        cin>>handle;
        h.push_back(handle);
    }
    for (int i=0;i<p;i++)
    {
        string prob;
        int sco;
        cin>>prob>>sco;
        scc[prob]=sco;
    }
    for (int i=0;i<s;i++)
    {
        string u,pr,v;
        cin>>u>>pr>>v;
        string idf=u+"#"+pr;
        if (!pass[idf])
        {
            if (v=="AC")
            {
                pass[idf]=1;
                score[u]+=scc[pr];
            }
        }
    }
    for (int i=0;i<c;i++)
        cout<<h[i]<<" "<<score[h[i]]<<endl;
}