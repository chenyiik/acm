#include<bits/stdc++.h>
using namespace std;
long long arr[305];
bool prime(long long n)
{	
	if (n<2) return false;
	if (n==2) return true;
	for (long long i=2;i<sqrt(n);i++)
	if (n%i==0) return false;
	return true;
}
long long eular(long long n)
{
    long long ret=n;
    for(long long i=2;i<=sqrt(n);i++)
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
	ios::sync_with_stdio(0);cin.tie(0);
	for (long long i=1;i<=300;i++) cin>>arr[i];
	bool ok=false;
	for (long long i=1;i<=300;i++)
	{
		long long tl=arr[i]+1;
		if (prime(tl))
		{
			bool succ=true;
			long long st=tl-i+1;
			if (st+300>(long long)(1e9)+1) continue;
			for (long long j=i-1;j>=1;j--)
			{
				long long tmp=tl-(i-j);
				if (eular(tmp)!=arr[j]) 
				{
					succ=false;
					break;
				}
			}
			for (long long j=i+1;j<=300;j++)
			{
				long long tmp=tl+(j-i);
				if (eular(tmp)!=arr[j]) 
				{
					//cout<<tmp<<" "<<eular(tmp)<<" "<<arr[j]<<endl;
					succ=false;
					break;
				}
			}
			if (succ) {ok=true;cout<<tl-i+1<<endl;break;}
		}
	}
	if (!ok) cout<<"yang12138 laji"<<endl;
	return 0;
}

