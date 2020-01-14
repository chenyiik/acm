#include<bits/stdc++.h>
using namespace std;
char str[500050];
vector<long long> modl={(long long)(1e9+7),(long long)(1e9+21)};
vector<vector<long long>> ipot;
long long modinv(long long a,long long b)
{
    return a>1?b-((modinv(b%a,a)*b)/a):1;
}
long long inv(long long a,long long b)
{
    long long z=modinv(a,b);
    return z<0?z+b:z;
}
struct strhash
{
    vector<vector<long long>> strhashs;
    strhash(){}
    strhash(string str)
    {
        strhashs.resize(modl.size(),vector<long long>(str.size()+1,0));
        for (int k=0;k<modl.size();k++)
        {
            long long v=1;
            for (int i=0;i<str.size();i++)
            {
                strhashs[k][i + 1] = (strhashs[k][i]+(str[i]-'a')*v)%modl[k];
                v=v*31%modl[k];
            }
        }
    }
    vector<long long> computestrhash(int l,int r)
    {
        vector<long long> ret;
        for (int i=0;i<modl.size();i++)
            ret.push_back((((strhashs[i][r]-strhashs[i][l-1])*ipot[i][l-1])%modl[i]+modl[i])%modl[i]);
        return ret;
    }
};
void build(int n)
{
    ipot.resize(modl.size(),vector<long long>(n+1,0));
    for (int k=0;k<modl.size();k++)
    {
        ipot[k][0]=1;
        long long invv=inv(31,modl[k]);
        for (int i=1;i<=n;i++)
            ipot[k][i]=(ipot[k][i-1]*invv)%modl[k];
    }
}
int main()
{
    build(500050);
    int n,m;
    scanf("%d%d",&n,&m);
    scanf("%s",str);
    strhash h(str);
    reverse(str,str+n);
    strhash h1(str);
    for (int i=0;i<n-m+1;i++)
    {
        int j=i+m-1;
        auto x=move(h1.computestrhash(i+1,j+1));
        int ii=n-i-1,jj=n-j-1;
        auto y=move(h.computestrhash(jj+1,ii+1));
        if (x==y) return puts("Accept"),0;
    }
    puts("Reject");
}