#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    string s;
    cin>>s;
    static int cnt[2];
    for (auto ch:s) cnt[ch-'0']++;
    if (cnt[0]!=cnt[1])
    {
        if (cnt[0]<cnt[1])
            cout<<string(s.size(),'0')<<endl;
        else
            cout<<string(s.size(),'1')<<endl;
        return 0;
    }
    if (s[0]=='0')
        cout<<'1'+string(s.size()-1,'0')<<endl;
    else
        cout<<'0'+string(s.size()-1,'1')<<endl;
}