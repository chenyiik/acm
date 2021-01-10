#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    long long t;cin>>t;
    while (t--)
    {
        static long long cas=0;
        cout<<"Case "<<++cas<<": ";
        static long long mp[5][250][250];
        memset(mp,0,sizeof(mp));
        static tuple<long long,long long> tile[250*250];
        long long n,m,cnt=0;cin>>n>>m;
        for (long long i=1;i<=n;i++)
        {
            string s;cin>>s;
            for (long long j=1;j<=m;j++)
                if (s[j-1]=='#')
                {
                    mp[0][i][j]=++cnt;
                    tile[cnt]=make_tuple(i,j);
                }
        }
        for (long long i=1;i<=n;i++)
            for (long long j=m,k=m;j;j--)
                if (mp[0][i][j])
                    mp[1][i][k--]=mp[0][i][j];
        for (long long j=1;j<=m;j++)
            for (long long i=1,k=1;i<=n;i++)
                if (mp[1][i][j])
                    mp[2][k++][j]=mp[1][i][j];
        for (long long i=1;i<=n;i++)
            for (long long j=1,k=1;j<=m;j++)
                if (mp[2][i][j])
                    mp[3][i][k++]=mp[2][i][j];
        for (long long j=1;j<=m;j++)
            for (long long i=n,k=n;i;i--)
                if (mp[3][i][j])
                    mp[4][k--][j]=mp[3][i][j];
        static map<tuple<long long,long long>,tuple<long long,long long>> go;go.clear();
        for (long long i=1;i<=n;i++)
            for (long long j=1;j<=m;j++)
                if (mp[4][i][j]) go[tile[mp[4][i][j]]]=make_tuple(i,j);
        static long long fraccnt[250*250];
        memset(fraccnt,0,sizeof(fraccnt));
        for (long long i=1;i<=cnt;i++)
        if (go.count(tile[i]))
        {
            auto p=tile[i];
            long long cir=0;
            while (go.count(p))
            {
                auto pt=go[p];
                go.erase(p);
                p=pt;
                ++cir;
            }
            for (long long j=2;j*j<=cir;j++)
                if (cir%j==0)
                {
                    long long qx=0;
                    while (cir%j==0) cir/=j,++qx;
                    fraccnt[j]=max(fraccnt[j],qx);
                }
            fraccnt[cir]=max(fraccnt[cir],1LL);
        }
        long long res=1;
        for (long long frac=1;frac<=cnt;frac++)
        {
            res*=(long long)pow(frac,fraccnt[frac]);
            res%=78294349LL;
        }
        cout<<res<<endl;
    }
}