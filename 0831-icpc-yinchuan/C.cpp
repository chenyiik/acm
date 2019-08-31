#include<bits/stdc++.h>
using namespace std;
string s1,s2;
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    int T;
    cin>>T;
    int n,m;
    for (int cas=1;cas<=T;cas++)
    {
        cin>>n>>m;
        cin>>s1>>s2;
        string saim;
        cin>>saim;
        int diff=s2[0]-s1[0];
        for (int i=0;i<saim.size();i++)
        {
            saim[i]=saim[i]-diff;
            if (saim[i]<'A') saim[i]+=26;
            if (saim[i]>'Z') saim[i]-=26;
        }
        cout<<"Case #"<<cas<<": "<<saim<<endl;
    }
}