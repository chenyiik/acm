#include <bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>T;
    while (T--)
    {
        string str;
        cin>>str;
        for (int i=0;i<str.size()-1;i++)
        {
            if (str[i+1]-str[i]==1) continue;
            if (str[i]=='z' && str[i+1]=='a') continue;
            goto fatal;
        }
        cout<<"YES"<<endl;
        continue;
        fatal:cout<<"NO"<<endl;
    }
}