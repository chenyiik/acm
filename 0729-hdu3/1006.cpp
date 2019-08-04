#include <bits/stdc++.h>
using namespace std;
__int128 frac(__int128 x,__int128 p)
{
    __int128 ans=1;
    for (__int128 t=x;t>=1;t--) {ans*=t;ans%=p;}
    return ans%p;
}
bool isprime(__int128 x)
{
    for (__int128 p=2;p*p<=x;p++) if (x%p==0) return false;
    return true;
}
__int128 qpow(__int128 a,__int128 b,__int128 p)
{
    if (b==0) return 1;
    __int128 tmp=qpow(a,b>>1,p);
    tmp=(tmp*tmp)%p;
    if (b&1) tmp=tmp*a%p;
    return tmp%p;
}
__int128 inv(__int128 a,__int128 p)
{
    return qpow(a,p-2,p)%p;
}
__int128 getans(__int128 rg,__int128 rt)
{
    __int128 ans=1;
    for (__int128 t=rg+1;t<=rt-2;t++) {ans*=t;ans%=rt;}
    return ans%rt;
}

void print(__int128 x)
{
    if(!x)
    {
        puts("0");
        return ;
    }
    string ret="";
    while(x)
    {
        ret+=x%10+'0';
        x/=10;
    }
    reverse(ret.begin(),ret.end());
    cout<<ret<<endl;
}
int main() {
        int T;
        cin>>T;
        while (T--)
        {
            __int128 n;
            long long nn;
            cin>>nn; n=nn;
            for (__int128 k=n-1;k>=2;k--)
                if (isprime(k))
                {
                    __int128 tmp=frac(n-k-1,n);
                    __int128 invv=inv(tmp,n);
                    print(invv);
                    break;
                }
        }
    return 0;
}