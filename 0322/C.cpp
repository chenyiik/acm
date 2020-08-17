#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    string s1,s2;
    cin>>s1>>s2;
    queue<char> q;
    for (auto ch:s2) q.push(ch);
    for (auto x:s1)
    {
        char k=q.front();q.pop();
        char ans=((x-'A')-(k-'A')+26)%26+'A';
        cout<<ans;
        q.push(ans);
    }
    cout<<endl;
}