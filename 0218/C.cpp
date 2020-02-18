#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    unordered_set<int> s;
    for (int i=1;i<=n;i++)
    {
        string str;
        cin>>str;
        if (!isdigit(str[0])) continue;
        if (str.length()<=7)
        {
            int val=0;
            for (auto ch:str)
            {
                val=val*10+ch-'0';
            }
            s.insert(val);
        }
    }
    for (int i=0;i<=1000005;i++)
        if (!s.count(i)) {cout<<i<<endl;break;}
}