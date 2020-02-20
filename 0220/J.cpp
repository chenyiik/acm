#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    long long n;
    cin>>n;
    static vector<long long> sc;
    long long julia;cin>>julia;
    for (long long i=1;i<n;i++) {long long tmp;cin>>tmp;sc.push_back(tmp);}
    sort(sc.begin(),sc.end());
    long long ans=0,highest=1;
    while (sc.back()!=julia||highest==1)
    {
        while (sc.size()>1 && sc.back()==sc[sc.size()-2])
        {
            sc.pop_back();
            highest++;
        }
        long long per=(long long)(log2(highest))+1;
        if (sc.size()==1)
        {
            long long df1=julia-sc.back();
            ans+=(df1/(per-1))*per+df1%(per-1);
            break;
        }
        else if (highest==1)
        {
            long long df2=sc.back()-sc[sc.size()-2];
            ans+=df2*per;
            julia-=df2*per;
            sc.pop_back();
            sc.push_back(sc.back());
        }
        else
        {
            long long df1=julia-sc.back(),df2=sc.back()-sc[sc.size()-2];
            long long cost1,cost2;
            cost1=(df1/(per-1))*per+df1%(per-1);
            cost2=df2*per;
            if (cost1<cost2) //101 3 100
            {
                ans+=cost1;
                break;
            } else
            {
                ans+=cost2;
                julia-=cost2;
                sc.pop_back();
                sc.push_back(sc.back());
            }
        }
    }
    cout<<ans<<endl;
}