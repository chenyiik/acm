#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    string s;
    while (cin>>s)
    {
        int cnt=0;
        vector<char> st;
        for (auto x:s)
        {
            st.push_back(x);
            if (st.size()>=3)
            {
                auto pr=st.end();--pr;
                char ch=*pr;--pr;
                char ch2=*pr;--pr;
                char ch3=*pr;
                if (ch==ch2 && ch2==ch3)
                {
                    cnt++;
                    st.pop_back();
                    st.pop_back();
                    st.pop_back();
                }
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}