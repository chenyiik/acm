#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    string s;
    cin>>s;
    int dans=s.size();
    for (int l=0;l<s.size();l++)
        for (int r=l+1;r<s.size();r++)
        {
            string outp=s,macro=s.substr(l,r-l+1);
            int ans=outp.size();
            for (int i=0;i<s.size();i++)
                if (outp.substr(i,macro.size())==macro) ans-=macro.size()-1,i+=macro.size()-1;
            dans=min(ans+(int)macro.size(),dans);
        }
    cout<<dans<<endl;
}