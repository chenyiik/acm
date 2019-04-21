#include<bits/stdc++.h>
using namespace std;
int eular(int n)
{
    int ret=n;
    for(int i=2;i<=sqrt(n);i++)
    if(n%i==0)
    {
        ret=ret/i*(i-1);
        while(n%i==0) n/=i;
    }
    if(n>1) ret=ret/n*(n-1);
    return ret;
}
int main()
{
	freopen("gen.out","w",stdout);
	int ft=88888888;
	for (int i=ft+1;i<=ft+300;i++) 
	{
		cout<<eular(i)<<" ";
		if ((i-ft)%10==0) cout<<endl;
	}
	return 0;
}
