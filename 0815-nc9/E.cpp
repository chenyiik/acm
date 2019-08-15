#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long uli;
uli C[100005][10];
void init()
{
    C[0][0]=1;
    C[1][0]=C[1][1]=1;
    for (uli i=1;i<=100000;i++) C[i][0]=1;
    C[2][2]=C[3][3]=C[4][4]=1;
    for (uli i=2;i<=100000;i++)
        for (uli j=1;j<=4;j++) C[i][j]=C[i-1][j-1]+C[i-1][j];
}
uli size[100005],fa[100005];
uli cnl;
uli find(uli x)
{
    return fa[x]=((fa[x]==x)?x:find(fa[x]));
}
void merge(uli x,uli y)
{
    uli t1=find(x),t2=find(y);
    fa[t2]=t1;
    size[t1]+=size[t2];
    cnl--;
}
int main()
{
    uli n,m;
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m;cnl=n;
    for (uli i=1;i<=n;i++) {fa[i]=i,size[i]=1;}
    init();
    uli ans=C[n][4];
    cout<<ans<<endl;
    for (uli i=1;i<=m;i++)
    {
        uli u,v;
        cin>>u>>v;
        uli f1=find(u),f2=find(v);
        if (f1==f2) {cout<<ans<<endl;continue;}
        uli dm=(size[f1]*size[f1])+(cnl-1)*size[f2];
        uli dm2=(size[f1]*size[f2]*C[n-size[f1]-size[f2]][2]);
        //cout<<size[f1]<<" "<<size[f2]<<endl;
        if (ans>dm2) ans-=dm2;else ans=0;
        merge(u,v);
        cout<<ans<<endl;
    }
    return 0;
}