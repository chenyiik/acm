#include <bits/stdc++.h>
using namespace std;

const int kN = 500 + 5, kM = 15;
const int kInf = 1e9;
bitset<505> bs[21];
char buf[kN];

int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        int n,m;
        cin>>m>>n;
        for (int i=0;i<n;i++) bs[i].reset();
        for (int i=0;i<n;i++)
        {
            string s;
            cin>>s;
            for (int j=0;j<m;j++)
            {
                bs[i][j]=(s[j]=='1');
            }
        }
        int ans=0x3f3f3f3f;
        for (int s=0;s<(1<<n);s++)
        {
            static bitset<505> v;
            v.reset();
            for (int i=0;i<n;i++)
            {
                if (s&(1<<i)) v|=bs[i];
            }
            if (v.count()==m) ans=min(ans,__builtin_popcount(s));
        }
        cout<<((ans==0x3f3f3f3f)?-1:ans)<<endl;
    }
}
