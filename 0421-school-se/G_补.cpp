#include<bits/stdc++.h>
using namespace std;
int arr[305];
bool prime(int n)
{	
	if (n==2) return true;
	for (int i=2;i<sqrt(n);i++)
	if (n%i==0) return false;
	return true;
}
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
	ios::sync_with_stdio(0);cin.tie(0);
	for (int i=1;i<=300;i++) cin>>arr[i];
	bool ok=false;
	for (int i=1;i<=300;i++)
	{
		int tl=arr[i]+1;
		if (prime(tl))
		{
			bool succ=true;
			for (int j=i-1;j>=1;j--)
			{
				int tmp=tl-(i-j);
				if (eular(tmp)!=arr[j]) 
				{
					succ=false;
					break;
				}
			}
			for (int j=i+1;j<=300;j++)
			{
				int tmp=tl+(j-i);
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

