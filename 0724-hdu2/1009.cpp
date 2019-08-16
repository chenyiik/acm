#include<bits/stdc++.h>
using namespace std;
const int MAXN=300005;
const int N=26;
char s[MAXN];
struct Palindromic_Tree
{
    int next[MAXN][N];//next指针，next指针和字典树类似，指向的串为当前串两端加上同一个字符构成
    int fail[MAXN];//fail指针，失配后跳转到fail指针指向的节点
    int cnt[MAXN];
    int num[MAXN];
    int len[MAXN];//len[i]表示节点i表示的回文串的长度
    int S[MAXN];//存放添加的字符
    int last;//指向上一个字符所在的节点，方便下一次add
    int n;//字符数组指针
    int p;//节点指针
    int endpos[MAXN];
    int newnode(int l)
    {//新建节点
        for(int i=0;i<N;++i) next[p][i]=0;
        cnt[p]=0;
        num[p]=0;
        len[p]=l;
        return p++;
    }
    void init()
    {//初始化
        p=0;
        newnode(0);
        newnode(-1);
        last=0;
        n=0;
        S[n]=-1;//开头放一个字符集中没有的字符，减少特判
        fail[0]=1;
    }
    int get_fail(int x)
    {//和KMP一样，失配后找一个尽量最长的
        while(S[n-len[x]-1]!=S[n]) x=fail[x];
        return x;
    }
    void add(int c,int pos)
    {
        c-='a';
        S[++n]=c;
        int cur=get_fail(last);//通过上一个回文串找这个回文串的匹配位置
        if(!next[cur][c])
        {//如果这个回文串没有出现过，说明出现了一个新的本质不同的回文串
            int now=newnode(len[cur]+2);//新建节点
            fail[now]=next[get_fail(fail[cur])][c];//和AC自动机一样建立fail指针，以便失配后跳转
            next[cur][c]=now;
            num[now]=num[fail[now]]+1;
        }
        last=next[cur][c];
        cnt[last]++;
        endpos[last]=pos;
    }
    void solve()
    {
        for(int i=p-1;i>0;i--)
        {
            //printf("cnt[%d]=cnt[%d]+cnt[%d]=%d\n",fail[i],fail[i],i,cnt[fail[i]]);
            cnt[fail[i]]+=cnt[i];
        }
    }
};
class HASH
{
public:
    using ULL=unsigned long long;
    ULL base=233;
    ULL p[2*MAXN];
    ULL Hash[2*MAXN];//u[x]=hashvalue(1,x);
    void init(char s[],int k)  //预处理主串的Hash前缀hash值和p的次方.
    {
        p[0]=1;
        Hash[0]=0;
        for(int i=1;i<=k;i++) p[i]=p[i-1]*base;
        for(int i=1;i<=k;i++)
        {
            Hash[i]=Hash[i-1]*base+(s[i]-'a'+1);
        }
    }
    ULL get(int l,int r)   //由公式得到hash[r-l]的值.
    {
        return Hash[r]-Hash[l-1]*p[r-l+1];
    }
};
HASH hash1,hash2;
Palindromic_Tree pam;
int ans[MAXN];
bool check(int pos,int cl,int l)
{
    int l1=pos-cl+1,r1=pos;
    int r2=l-l1+1,l2=l-r1+1;
    return hash1.get(l1,r1)==hash2.get(l2,r2);
}
int main()
{
    while (~scanf("%s",s+1))
    {
        memset(ans,0,sizeof(ans));
        int len=strlen(s+1);
        pam.init();
        for (int i=1;i<=len;i++) pam.add(s[i],i);
        hash1.init(s,len);
        reverse(s+1,s+len+1);
        hash2.init(s,len);
        pam.solve();
        for (int i=2;i<pam.p;i++)
        {
            int cl=pam.len[i],pos=pam.endpos[i];
            if (check(pos-(cl/2),(cl+1)/2,len)) ans[cl]+=pam.cnt[i];
        }
        for (int i=1;i<=len;i++)
        printf("%d%c",ans[i]," \n"[i==len]);
    }
    return 0;
}