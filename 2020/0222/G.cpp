#include<bits/stdc++.h>
using namespace std;
int sz,last;
int pre[200050<<1],nxt[200050<<1][26],len[200050<<1];
void add(char ch)
{
    ch=ch-'A';
    int nx=sz++;len[nx]=len[last]+1;
    int u=last;
    while (u!=-1 && !nxt[u][ch])
        nxt[u][ch]=nx,u=pre[u];
    if (u==-1) pre[nx]=0;
    else
    {
        int v=nxt[u][ch];
        if (len[v]==len[u]+1) pre[nx]=v;
        else
        {
            int nv=sz++;
            pre[nv]=pre[v];
            memcpy(nxt[nv],nxt[v],sizeof(nxt[v]));
            len[nv]=len[u]+1;
            while (u!=-1 && nxt[u][ch]==v) nxt[u][ch]=nv,u=pre[u];
            pre[v]=pre[nx]=nv;
        }
    }
    last=nx;
}
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    sz=1,last=0;len[0]=0;pre[0]=-1;
    string s;cin>>s;
    for (auto ch:s)
        add(ch);
    int n;cin>>n;
    while (n--)
    {
        string ask;
        cin>>ask;
        int ans=0;
        for (int i=0;i<ask.size();i++)
        {
            if (nxt[0][ask[i]-'A']==0) {ans=-1;break;}
            ++ans;
            int u=0;
            while (i<ask.size() && nxt[u][ask[i]-'A']) u=nxt[u][ask[i++]-'A'];
            i--;
        }
        cout<<ans<<endl;
    }
}