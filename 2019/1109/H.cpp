#include<bits/stdc++.h>
using namespace std;
set<pair<int,int> > st;
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    int n;
    cin>>n;
    string da;
    cin>>da;
    int m;
    cin>>m;
    string s[105];
    for (int i=1;i<=m;i++) cin>>s[i];
    st.clear();
    for (int i=1;i<=m;i++)
        for (int j=i+1;j<=m;j++)
        {
            int aa=0,wa=0,a1=0,w1=0,a2=0,w2=0;
            for (int k=0;k<s[i].length();k++)
                a1+=int(s[i][k]==da[k]),w1+=int(s[i][k]!=da[k]);
            for (int k=0;k<s[j].length();k++)
                a2+=int(s[j][k]==da[k]),w2+=int(s[j][k]!=da[k]);
            for (int k=0;k<s[i].length();k++)
                if (s[i][k]==s[j][k])
                    aa+=(s[i][k]==da[k]),wa+=(s[i][k]!=da[k]);
            if (2*aa>a1 && 2*aa>a2 && 2*wa>w1 && 2*wa>w2)
                st.insert(make_pair(i,j));
        }
    cout<<st.size()<<endl;
    for (auto x:st)
        cout<<x.first<<" "<<x.second<<endl;
}