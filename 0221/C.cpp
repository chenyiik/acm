#include<bits/stdc++.h>
using namespace std;
int diff[255],res[255],n;
int get(int pos)
{
    cout<<1<<" "<<pos<<endl;
    cout.flush();
    int tmp;
    cin>>tmp;
    return tmp;
}
void solved()
{
    cout<<3<<" ";
    for (int i=1;i<=n;i++) cout<<res[i]<<" \n"[i==n];
    cout.flush();
}
int maxdiffer(int pos)
{
    cout<<2<<" "<<pos<<" ";
    for (int i=1;i<=pos;i++) cout<<i<<" \n"[i==pos];
    cout.flush();
    int maxval=-0x3f3f3f3f;
    for (int i=1;i<=((pos*(pos-1))>>1);i++)
    {
        int tmp;
        cin>>tmp;
        maxval=max(maxval,tmp);
    }
    return maxval;
}
vector<int> querydiffer(int mxid,vector<int> pos)
{
    map<int,int> differ;
    if (pos.size()>1)
    {
        cout<<2<<" "<<pos.size();
        for (auto x:pos) cout<<" "<<x;cout<<endl;
        cout.flush();
        for (int i=1;i<=((pos.size()*(pos.size()-1))>>1);i++)
        {
            int tmp;cin>>tmp;
            differ[tmp]--;
        }
    }
    pos.push_back(mxid);
    cout<<2<<" "<<pos.size();
    for (auto x:pos) cout<<" "<<x;cout<<endl;
    cout.flush();
    for (int i=1;i<=((pos.size()*(pos.size()-1))>>1);i++)
    {
        int tmp;cin>>tmp;
        differ[tmp]++;
    }
    vector<int> rv;
    for (auto x:differ)
        if (x.second>0)
            rv.push_back(x.first);
    return rv;
}
int main()
{
    cin>>n;
    if (n<=30)
    {
        for (int i=1;i<=n;i++) res[i]=get(i);
        solved();
        return 0;
    }
    int mx=maxdiffer(n);
    int l=1,r=n;
    while (l<=r)
    {
        int mid=(l+r)>>1;
        int now=maxdiffer(mid);
        if (now==mx) r=mid-1;
        else l=mid+1;
    }
    int mxpos=l;
    int mxval=get(mxpos),cmpd=mxpos<n?mxpos+1:mxpos-1;
    int isbiggest=mxval>get(cmpd);
    map<int,int> occur;
    for (int i=0;i<8;i++)
    {
        vector<int> pos;
        for (int j=1;j<=n;j++)
            if (j!=mxpos && ((j>>i)&1)) pos.push_back(j);
        if (pos.empty()) continue;
        vector<int> out=move(querydiffer(mxpos,pos));
        for (auto x:out) occur[x]+=(1<<i);
    }
    for (auto x:occur) diff[x.second]=x.first;
    for (int i=1;i<=n;i++) res[i]+=mxval+(isbiggest?-1:1)*diff[i];
    solved();
    return 0;
}