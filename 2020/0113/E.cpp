#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        int k,l;
        cin>>k>>l;
        if (l>1999) {puts("-1");continue;}
        int n=1999;
        cout<<n<<endl;
        static int a[2000];
        a[1]=-1;
        for (int i=2;i<=n;i++) a[i]=1;
        int diffa=k/(n-1),diffp=k%(n-1)+1;
        for (int i=2;i<=n;i++) a[i]+=diffa;
        for (int i=2;i<=diffp+1;i++) a[i]++;
        for (int i=1;i<=n;i++) cout<<a[i]<<" \n"[i==n];
    }
}