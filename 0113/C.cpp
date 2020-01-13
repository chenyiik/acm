#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    static int a[55];
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            for (int k=1;k<=n;k++)
            if (i^j && j^k && i^k)
            {
                if (abs(a[i]-a[j])%a[k]!=0)
                {
                    cout<<"no"<<endl;
                    return 0;
                }
            }
    cout<<"yes"<<endl;
}