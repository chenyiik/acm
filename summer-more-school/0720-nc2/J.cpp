#include<bits/stdc++.h>
using namespace std;
int l[int(1e6)+50],r[int(1e6)+50];
int l1[int(1e6)+50],r1[int(1e6)+50];
int num[int(1e7)*2];
void read(int &x)
{
    int f=1;x=0;char s=getchar();
    while(s<'0'||s>'9'){if(s=='-')f=-1;s=getchar();}
    while(s>='0'&&s<='9'){x=x*10+s-'0';s=getchar();}
    x*=f;
}
int main()
{
    int n;
    read(n);
    for (int i=1;i<=n;i++) read(l[i]),read(r[i]);
    l1[0]=r1[0]=l[0]=r[0]=-1,l[n+1]=r[n+1]=1e9;
    int val=0;
    for (int i=1;i<=n;i++)
    {
        val+=r[i]-l[i]+1;
        if (val>=(l[i+1]-r[i]-1)) {val-=l[i+1]-r[i]-1;r1[i]=l[i+1]-1;}
        else {r1[i]=r[i]+val;val=0;}
    }
    val=0;
    for (int i=n;i>=1;i--)
    {
        val+=r[i]-l[i]+1;
        if (val>=(l[i]-r[i-1]-1)) {val-=l[i]-r[i-1]-1;l1[i]=r[i-1]+1;}
        else {l1[i]=l[i]-val;val=0;}
    }
    int cur=int(1e7);
    num[cur]=1;
    long long sum=0,ans=0;
    for (int i=1;i<=n;i++)
    {
        for (int j=max(l1[i],r1[i-1]+1);j<=min(r1[i],l[i+1]-1);j++)
        {
            if (j>=l[i] && j<=r[i])
            {
                sum+=num[cur];
                cur++;
                num[cur]++;
            } else
            {
                cur--;
                sum-=num[cur];
                num[cur]++;
            }
            ans+=sum;
        }
    }
    cout<<ans<<endl;

}