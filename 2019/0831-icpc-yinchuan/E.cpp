#include<bits/stdc++.h>
using namespace std;
struct node
{
    int f;
    vector<int> key;
    vector<int> child;
    void init(int fa,int x)
    {
        f=fa;
        key.clear();
        child.clear();
        key.emplace_back(x);
    }
};
node tree[20050];
int root,cnt;
void insert(int rt,int key)
{
    if(tree[rt].key.size()>=3)
    {
        int tf=tree[rt].f;
        vector<int> kk(tree[rt].key);
        vector<int> cc(tree[rt].child);
        if(rt==root)
        {
            root=++cnt;
            tree[root].init(0,kk[1]);
            tree[++cnt].init(root,kk[0]);
            tree[rt].init(root,kk[2]);
            tree[root].child.push_back(cnt);
            tree[root].child.push_back(rt);
            if(cc.size())
            {
                //left
                tree[cnt].child.push_back(cc[0]);
                tree[cc[0]].f=cnt;
                tree[cnt].child.push_back(cc[1]);
                tree[cc[1]].f=cnt;
                //right
                tree[rt].child.push_back(cc[2]);
                tree[cc[2]].f=rt;
                tree[rt].child.push_back(cc[3]);
                tree[cc[3]].f=rt;
            }
            rt=root;
        }
        else
        {
            tree[rt].init(tf,kk[0]);
            tree[++cnt].init(tf,kk[2]);
            tree[tf].key.push_back(kk[1]);
            sort(tree[tf].key.begin(),tree[tf].key.end());
            tree[tf].child.push_back(cnt);
            for(int i=tree[tf].child.size()-1;i>1;i--)
            {
                if(tree[tf].child[i-1]!=rt) swap(tree[tf].child[i-1],tree[tf].child[i]);
                else break;
            }
            if(cc.size())
            {
                tree[rt].child.push_back(cc[0]);
                tree[cc[0]].f=rt;
                tree[rt].child.push_back(cc[1]);
                tree[cc[1]].f=rt;
                tree[cnt].child.push_back(cc[2]);
                tree[cc[2]].f=cnt;
                tree[cnt].child.push_back(cc[3]);
                tree[cc[3]].f=cnt;
            }
            rt=tf;
        }
    }
    if(!tree[rt].child.size())
    {
        tree[rt].key.push_back(key);
        sort(tree[rt].key.begin(),tree[rt].key.end());
    }
    else
    {
        if(key<tree[rt].key[0]) insert(tree[rt].child[0],key);
        else if(key>tree[rt].key[tree[rt].key.size()-1]) insert(tree[rt].child[tree[rt].child.size()-1],key);
        else
        {
            for (int i=1;i<tree[rt].key.size();i++)
                if (key<tree[rt].key[i])
                {
                    insert(tree[rt].child[i],key);
                    break;
                }
        }
    }
}
void predfs(int rt)
{
    for (int i=0;i<tree[rt].key.size();i++)
        cout<<tree[rt].key[i]<<" \n"[i==tree[rt].key.size()-1];
    for (auto x:tree[rt].child)
        predfs(x);
}
void solve()
{
    int n;
    cin>>n;
    static int a[5050];
    for(int i=1;i<=n;i++) cin>>a[i];
    root=cnt=1;
    tree[root].init(0,a[1]);
    for(int i=2;i<=n;i++) insert(root,a[i]);
    predfs(root);
}
int main()
{
    int T;
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>T;
    for(int cas=1;cas<=T;cas++)
    {
        cout<<"Case #"<<cas<<":"<<endl;
        solve();
    }
}