#include<bits/stdc++.h>
using namespace std;
int main()
{
    int T;
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        static int x1[105],x2[105],y[105];
        for(int i=1;i<=n;i++) cin>>x1[i]>>x2[i]>>y[i];
        double L=-(1LL<<60),R=(1LL<<60);
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
            {
                if(i==j) continue;
                if(y[i]==1 && y[j]==-1)
                {
                    if(x2[i]==x2[j]) continue;
                    double d=x2[j]-x2[i];
                    double ul=x1[i]-x1[j];
                    double frac=ul/d;
                    if(d<0) L=max(L,frac); else R=min(frac,R);
                }
            }
        if(L<=R)
        {
            cout<<"Successful!"<<endl;
            continue;
        }
        L=-(1LL<<60),R=(1LL<<60);
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
            {
                if(i==j) continue;
                if(y[i]==1 && y[j]==-1)
                {
                    if(x2[i]==x2[j]) continue;
                    double d=x2[j]-x2[i];
                    double ul=-(x1[i]-x1[j]);
                    double frac=ul/d;
                    if(d<0) L=max(L,frac); else R=min(frac,R);
                }
            }
        if(L<=R)
        {
            cout<<"Successful!"<<endl;
            continue;
        }
        cout<<"Infinite loop!"<<endl;
    }
}