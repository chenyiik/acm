#include<bits/stdc++.h>
using namespace std;
const unsigned long long hashx=255ULL;
unsigned long long hashval[40050];
unsigned long long hashtable[40050];
unordered_map<unsigned long long,int> cnt;
int n,m;
unsigned long long gethashval(int l,int r)
{
    return hashval[r]-hashval[l-1]*hashtable[r-l+1];
}
int calc(int len)
{
    cnt.clear();
    int ans=-1;
    for (int i=1;i<=n-len+1;i++)
    {
        int rangeval=gethashval(i,i+len-1);
        int tmp=++cnt[rangeval];
        if (tmp>=m) ans=i;
    }
    return ans;
}
pair<int,int> find(int l,int r)
{
    int len=-1,pos=-1;
    while (l<=r)
    {
        int mid=(l+r)>>1;
        int poss=calc(mid);
        if (poss>=0)
        {
            len=mid;
            pos=poss;
            l=mid+1;
        }
        else r=mid-1;
    }
    return make_pair(len,pos);
}
int main()
{
    hashtable[0]=1;
    for (int i=1;i<40050;i++) hashtable[i]=hashtable[i-1]*hashx;
    while (cin>>m && m)
    {
        string s;
        cin>>s;
        n=s.size();s='\0'+s;
        hashval[0]=0;
        for (int i=1;i<=n;i++) hashval[i]=hashval[i-1]*hashx+s[i]-'a';
        auto ans=find(1,n-m+1);
        if (ans.first==-1) puts("none");else cout<<ans.first<<" "<<ans.second-1<<endl;
    }
}