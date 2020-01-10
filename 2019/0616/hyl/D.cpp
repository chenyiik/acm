#include<bits/stdc++.h>
using namespace std;
const int maxnum=(1<<10)-1;
vector<int> pre[11];
int ans[11][11][11];
void init()
{
    for (int i=0;i<=maxnum;i++)
    {
        int tmp=i;
        int cnt=0;
        while (tmp>0)
        {
            cnt+=tmp&1;
            tmp>>=1;
        }
        pre[cnt].push_back(i);
    }
    memset(ans,-1,sizeof(ans));
}
void output(int x)
{
    bitset<10> outp(x);
    cout<<outp<<endl;
}
int main()
{
    init();
    int T;
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>T;
    while (T--)
    {
        static int onesnum[4];
        for (int i=1;i<=3;i++)
        {
            string str;
            cin>>str;
            onesnum[i]=0;
            for (auto ch:str) onesnum[i]+=(ch=='1');
        }
        if (ans[onesnum[1]][onesnum[2]][onesnum[3]]!=-1)  {output(ans[onesnum[1]][onesnum[2]][onesnum[3]]);continue;}
        int tmp=0;
        for (auto u:pre[onesnum[1]])
            for (auto v:pre[onesnum[2]])
                for (auto w:pre[onesnum[3]])
                {
                    tmp=max(tmp,u^v^w);
                }
        ans[onesnum[1]][onesnum[2]][onesnum[3]]=tmp;
        output(ans[onesnum[1]][onesnum[2]][onesnum[3]]);
    }
}