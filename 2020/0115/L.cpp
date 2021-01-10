#include<bits/stdc++.h>
using namespace std;
vector<int> num,r;
bool chk(int pos)
{
    int sum=0;
    for (int i=max(0,pos-int(r.size()));i<=min(pos,int(r.size())-1);i++)
        if (pos-i<r.size())
            sum+=r[i]*r[pos-i];
    return num[pos]==sum%10;
}
bool dfs(int pos)
{
    if (pos>=r.size())
    {
        while (pos<num.size())
        {
            if (!chk(pos)) return 0;
            ++pos;
        }
        return 1;
    }
    for (int x=0;x<=9;x++)
    {
        r[pos]=x;
        if (!chk(pos)) continue;
        if (dfs(pos+1)) return 1;
    }
    return 0;
}
int main()
{
    string s;
    cin>>s;
    if ((s.size()&1)==0) return puts("-1");
    for (int i=0;i<s.size();i++) num.push_back(s[i]-'0');
    r.resize((1+s.size())>>1,0);
    if (dfs(0))
    {
        for (auto x:r) cout<<x;
        return puts("");
    }
    puts("-1");
}