#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s1,s2;
    cin>>s1;
    cin>>s2;
    int ans=0;
    static set<char> zero,one;
    int mov=s1.length()-s2.length();
    for (int i=0;i<=mov;i++)
    {
        zero.clear();one.clear();
        bool succ=false;
        for (int j=0;j<s2.length();j++)
        {
            if (s2[j]=='1') one.insert(s1[i+j]);
            else zero.insert(s1[i+j]);
        }
        succ|=(one.size()<=1 && zero.size()<=1);
        zero.clear();one.clear();
        for (int j=0;j<s2.length();j++)
        {
            if (s2[j]=='1') one.insert(s1[i+s2.length()-1-j]);
            else zero.insert(s1[i+s2.length()-1-j]);
        }
        succ|=(one.size()<=1 && zero.size()<=1);
        ans+=int(succ);
    }
    cout<<ans<<endl;
}