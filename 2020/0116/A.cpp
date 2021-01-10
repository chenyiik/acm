#include<bits/stdc++.h>
using namespace std;
int f[505][505];
string s;
int calc(int l,int r)
{
    if(l>r) return f[l][r]=0;
    if (l==r) return s[l]!='*';
    if (f[l][r]>=0) return f[l][r];
    if (s[l]!=s[r] && isalpha(s[l]) && isalpha(s[r])) return 0x3f3f3f3f;
    int ans=0x3f3f3f3f;
    if (s[l]=='*' && s[r]=='*') ans=min(ans,calc(l+1,r-1));else ans=min(ans,calc(l+1,r-1)+2);
    if (s[l]=='*' && s[r]!='*') ans=min(ans,calc(l,r-1)+2);
    if (s[l]!='*' && s[r]=='*') ans=min(ans,calc(l+1,r)+2);
    if (s[l]=='*') ans=min(ans,calc(l+1,r));
    if (s[r]=='*') ans=min(ans,calc(l,r-1));
    return f[l][r]=ans;
}
string fill(int l,int r)
{
    if (l>r) return "";
    if (l==r) return (s[l]=='*')?"":string(1,s[l]);
    if (s[l]=='*' && s[r]=='*' && f[l][r]==calc(l+1,r-1)) return fill(l+1,r-1);
    if (f[l][r]==calc(l+1,r-1)+2) return s[l]+fill(l+1,r-1)+s[r];
    if (s[l]=='*' && s[r]!='*')
        if (f[l][r]==calc(l,r-1)+2) return s[r]+fill(l,r-1)+s[r];
    if (s[l]!='*' && s[r]=='*')
        if (f[l][r]==calc(l+1,r)+2) return s[l]+fill(l+1,r)+s[l];
    if (s[l]=='*' && f[l][r]==calc(l+1,r)) return fill(l+1,r);
    if (s[r]=='*' && f[l][r]==calc(l,r-1)) return fill(l,r-1);
    return "";
}
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    memset(f,-1,sizeof(f));
    cin>>s;
    bool et=true;
    for (auto ch:s) if (ch!='*') et=false;
    if (et) return puts("");
    int ans=calc(0,s.length()-1);
    if (ans>=0x3f3f3f3f) return puts("-1");
    string out=fill(0,s.length()-1);
    for (int i=0;i<=(out.length()>>1);i++)
    if (isalpha(out[i])) out[out.length()-i-1]=out[i];
    else if (isalpha(out[out.length()-i-1])) out[i]=out[out.length()-i-1];
    else out[i]=out[out.length()-i-1]='x';
    cout<<out<<endl;
}