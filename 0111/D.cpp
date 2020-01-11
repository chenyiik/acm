#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,c;
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n>>c;
    static vector<int> pos[105];
    for (int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        pos[x].emplace_back(i);
    }
    int ans=0;
    for (int i=1;i<=c;i++)
        for (int j=1;j<=c;j++)
        if (i!=j)
        {
            int p1=0,p2=0;
            int tmp=0,sum=0;
            vector<int>& c1=pos[i];
            vector<int>& c2=pos[j];
            int len1=c1.size(),len2=c2.size();
            while (1)
            {
                while (p1<len1 && c1[p1]<tmp) p1++;
                if (p1==len1) break;
                tmp=c1[p1];
                sum++;
                while (p2<len2 && c2[p2]<tmp) p2++;
                if (p2==len2) break;
                tmp=c2[p2];
                sum++;
            }
            ans=max(ans,sum);
        }
    cout<<ans<<endl;
}