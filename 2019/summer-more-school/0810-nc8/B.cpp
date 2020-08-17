#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    int n;
    cin>>n;
    static int a[100050];
    for (int i=1;i<=n;i++) cin>>a[i];
    int l=1;
    set<int> st;
    int ans=0;
    for (int r=1;r<=n;r++)
    {
        if (!st.count(a[r])) {ans+=((r-l)+1)*(r-l+2)/2;cout<<l<<" "<<r<<" "<<ans<<endl;st.insert(a[r]);}
        else
        {
            while (st.count(a[r])){ans+=(r-l);cout<<l<<" "<<r<<" "<<ans<<endl;st.erase(a[l]);l++;}
            ans+=((r-l)+1)*(r-l+2)/2;cout<<l<<" "<<r<<" "<<ans<<endl;
        }
    }
    cout<<ans<<endl;
    return 0;
}