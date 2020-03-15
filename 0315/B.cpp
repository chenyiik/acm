#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    string s;
    cin>>s;
    string ans="";
    int ccnt=0,scnt=0;
    for (auto ch:s)
    {
        if (ch=='C')
        {
            scnt=0;
            ++ccnt;
            if (ccnt==3)
            {
                ans+='P';
                ccnt=0;
            }
            else ans+='B';
        } else
        {
            ccnt=0;
            ++scnt;
            if (scnt==3)
            {
                ans+='T';
                scnt=0;
            }
            else ans+='D';
        }
    }
    cout<<ans<<endl;
}