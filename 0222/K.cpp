#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    string s;
    cin>>s;
    static vector<long long> zeropoint;
    for (long long i=1;i<s.size();i++) if (s[i]!=s[i-1]) zeropoint.push_back(2*i+1);
    static long long p[10050];p[0]=1;
    long long n=zeropoint.size();
    for (long long i=0;i<n;i++)
    {
        static long long t[10050];
        memset(t,0,sizeof(t));
        for (long long j=0;j<=n;j++)
            t[j+1]=p[j],t[j]+=p[j]*(-zeropoint[i]);
        for (long long j=0;j<=n;j++) p[j]=t[j];
    }
    cout<<n<<endl;
    long long rev=1;
    if (n%2 ^ (s[0]=='A')) rev=-1;
    for (long long i=n;i>=0;i--) cout<<p[i]*rev<<" \n"[i==0];
}