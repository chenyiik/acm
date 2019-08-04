#include <bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    cin>>T;
    while (T--)
    {
        static bool choice[10000];
        static int a[10000];
        static int valsum[10000];
        static set<int> used[10000];
        int n,k;
        cin>>n>>k;
        for (int i=1;i<=n;i++) cin>>a[i];
        for (int st=1;st<=n;st++)
        {
            valsum[st]=a[st];
            used[st].insert(st);
            int maxp=a[st];
            for (int j=st+1;j<=n;j++)
            if (a[j]>=maxp)
            {
                valsum[st]+=a[j];
                maxp=a[j];
                used[st].insert(j);
            }
        }
        memset(choice,0,sizeof(choice));
        int ans=0;
        while (k--)
        {
            int tj=-1,maxval=-1;
            for (int i=1;i<=n;i++)
            {
                if (!choice[i] && valsum[i]>maxval) {maxval=valsum[i];tj=i;}
            }
            choice[tj]=true;
            ans+=maxval;
            while (!used[tj].empty())
            {
                int t=*(used[tj].begin());
                used[tj].erase(t);
                for (int i=1;i<=n;i++)
                if (!choice[i])
                {
                    if (used[i].count(t))
                    {
                        used[i].erase(t);
                        valsum[i]-=a[t];
                    }
                }
            }
        }
        cout<<ans<<endl;
    }
}