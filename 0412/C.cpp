#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    int n,k;
    cin>>n>>k;
    static int a[100050];
    for (int i=1;i<=n;i++) cin>>a[i];
    static vector<int> sp[100050];
    static set<int> s;
    static int nxt[100050];
    for (int i=1;i<=n;i++)
    {
        sp[a[i]].push_back(i);
        s.insert(a[i]);
        nxt[i]=-1;
    }
    for (auto x:s)
        for (int i=sp[x].size()-2;i>=0;i--)
            nxt[sp[x][i]]=sp[x][i+1];
    int ans=0;
    static set<int> st;
    for (int i=1;i<=n;i++)
    {
        if (st.count(i)) st.erase(i);
        else
        {
            ++ans;
            if (st.size()>=k)
                st.erase(*(st.rbegin()));
        }
        if (nxt[i]!=-1) st.insert(nxt[i]);
    }
    cout<<ans<<endl;
}