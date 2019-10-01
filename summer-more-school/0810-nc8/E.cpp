#include<bits/stdc++.h>
using namespace std;
int n,m;
void read(int &x)
{
    char ch=getchar();x=0;
    while (!isdigit(ch)) ch=getchar();
    while (isdigit(ch)) {x=x*10+ch-'0';ch=getchar();}
}
struct edget
{
    int u,v;
    int l,r;
};
edget edge[100050];
vector<int> hive[524288+5];
namespace segtree
{
    struct node
    {
        int l,r;
        int id;
    };
    node tree[800050];
    int root=1;
    void build(int root,int l,int r)
    {
        tree[root].id=root;
        if (l==r) {hive[tree[root].id].clear();tree[root].l=l;tree[root].r=r;return;}
        int mid=(l+r)>>1;
        build(root<<1,l,mid);build(root<<1|1,mid+1,r);
        tree[root].l=l;tree[root].r=r;
        hive[tree[root].id].clear();
    }
    void modify(int root,int l,int r,int x,int y,int ind)
    {
        if (x<=l && y>=r) {hive[tree[root].id].push_back(ind);return;}
        int mid=(l+r)>>1;
        if (x<=mid) modify(root<<1,l,mid,x,y,ind);
        if (y>=mid+1) modify(root<<1|1,mid+1,r,x,y,ind);
    }
}
namespace disjointset
{
    int fa[100050],size[100050];
    void init(int n) {for (int i=1;i<=n;i++) fa[i]=i,size[i]=1;}
    //int find(int x) {return (x==fa[x])?fa[x]:find(fa[x]);}
    int find(int x) {while (fa[x]!=x) x=fa[x];return x;}
    void del(int x) {size[fa[x]]-=size[x];fa[x]=x;}
    int merge(int x,int y)
    {
        int fx=find(x),fy=find(y);
        if (fx==fy) return -1;
        if (size[fx]<size[fy]) swap(fx,fy);
        fa[fy]=fx;size[fx]+=size[fy];
        return fy;
    }
    void debug() {/*for (int i=1;i<=n;i++) cout<<fa[i]<<" ";puts("");*/}
}
namespace lsh
{
    int raw[200050];
    int num=0;
    int nm=0;
    void add(int x) {raw[++num]=x;}
    void ready() {sort(raw+1,raw+num+1);nm=unique(raw+1,raw+num+1)-raw-1;}
    int get(int x) {return lower_bound(raw+1,raw+nm+1,x)-raw;}
    int getunique() {return nm;}
}
namespace solve
{
    int ans=0;
    void calc(int root,int l,int r)
    {
        stack<int> conn;
        for(int i=0;i<hive[segtree::tree[root].id].size();i++)
        {
            int u=edge[hive[segtree::tree[root].id][i]].u,v=edge[hive[segtree::tree[root].id][i]].v;
            //printf("%d %d\n",u,v);
            //disjointset::debug();
            int f1=disjointset::find(u),f2=disjointset::find(v);
            if (f1!=f2)
                conn.push(disjointset::merge(f1,f2));
        }
        if (disjointset::find(1)==disjointset::find(n))
            ans+=lsh::raw[r+1]-lsh::raw[l];
        else if (l!=r)
            {
                int mid=(l+r)>>1;
                calc(root<<1,l,mid);calc(root<<1|1,mid+1,r);
            }
        while (!conn.empty())
        {
            int tmp=conn.top();
            disjointset::del(tmp);
            disjointset::debug();
            conn.pop();
        }
    }
}
int main()
{
    //freopen("in.txt","r",stdin);
    read(n),read(m);
    //cout<<n<<m<<endl;
    disjointset::init(n);
    for (int i=1;i<=m;i++)
    {
        read(edge[i].u),read(edge[i].v),read(edge[i].l),read(edge[i].r);
        lsh::add(edge[i].l);lsh::add(edge[i].r+1);
    }
    lsh::ready();
    int maxq=lsh::getunique();
    //cout<<maxq<<endl;
    segtree::build(segtree::root,1,maxq);
    for (int i=1;i<=m;i++)
    {
        //if (edge[i].l==0) printf("%d %d %d \n",i,edge[i].l,edge[i].r);
        //printf("%d %d %d\n",i,lsh::get(edge[i].l),lsh::get(edge[i].r+1)-1);
        segtree::modify(segtree::root,1,maxq,lsh::get(edge[i].l),lsh::get(edge[i].r+1)-1,i);
    }
    solve::calc(segtree::root,1,maxq);
    printf("%d\n",solve::ans);
}