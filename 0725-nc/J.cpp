#include<bits/stdc++.h>
using namespace std;
struct tl
{
    string name;
    int val;
};
list<tl> mem;
unordered_map<string,list<tl>::iterator> mp;
void Rd(int &res){
    res=0;
    char c;
    while(c=getchar(),!isdigit(c));
    do{
        res=res*10+(c^48);
    }while(c=getchar(),isdigit(c));
}

int main()
{
    int T;
    Rd(T);
    while (T--)
    {
        mem.clear();
        mp.clear();
        int Q,M;
        Rd(Q),Rd(M);
        while (Q--)
        {
            int op,v;
            char str[15];
            scanf("%d%s%d",&op,str,&v);
            if (op==0)
            {
                if (mp.count(str))
                {
                    printf("%d\n",(*mp[str]).val);
                    v=(*mp[str]).val;
                    mem.push_back(tl{str,v});
                    mem.erase(mp[str]);
                    list<tl>::iterator it=mem.end();
                    --it;
                    mp[str]=it;
                } else
                {
                    mem.push_back(tl{str,v});
                    list<tl>::iterator it=mem.end();
                    --it;
                    mp[str]=it;
                    printf("%d\n",v);
                    if (mem.size()>M)
                    {
                        auto t=mem.begin();
                        mp.erase((*t).name);
                        mem.pop_front();
                    }
                }
            } else
            {
                if (!mp.count(str)) {puts("Invalid");continue;}
                auto x=mp[str];
                if (x==mem.begin() && v==-1) {puts("Invalid");continue;}
                if (x==prev(mem.end()) && v==1) {puts("Invalid");continue;}
                advance(x,v);
                printf("%d\n",(*x).val);
            }
        }
    }
    return 0;
}