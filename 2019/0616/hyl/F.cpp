#include <bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>T;
    while (T--)
    {
        int cnt=0;
        string str;
        cin>>str;
        if (!(str[0]>='a' && str[0]<='z'))
        {
            cout<<"NO"<<endl;
            continue;
        }
        cnt++;
        bool bj=true;
        for (auto ch:str)
        {
            if (!((ch>='a' && ch<='z')||(ch>='A' && ch<='Z')))
            {
                bj=false;break;
            }
        }
        if (!bj)
        {
            cout<<"NO"<<endl;
            continue;
        }
        for (auto ch:str)
        {
            if (ch>='A' && ch<='Z') cnt++;
            if (cnt>7) goto lb;
        }
        cout<<"YES"<<endl;
        continue;
        lb:cout<<"NO"<<endl;
    }
    return 0;
}