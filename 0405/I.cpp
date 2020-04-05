#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    int n;
    cin>>n;
    vector<char> t;
    bool res=true;
    while (n--)
    {
        string s;
        cin>>s;
        t.push_back(s[0]);
    }
    for (int i=t.size()-1;i>=0;i--)
    {
        if (t[i]=='L') res=!res;
    }
    cout<<vector<string>{"LIE","TRUTH"}[res]<<endl;
}