#include<bits/stdc++.h>
using namespace std;
bool notprime[1000050];
int cnt,prime[100050];
void getprime()
{
	cnt=0,memset(notprime,false,sizeof(notprime));
	notprime[0]=notprime[1]=true;
	for (int i=2;i<=1000050;i++)
	{
		if (!notprime[i]) prime[++cnt]=i;
		for (int j=1;j<=cnt && i*prime[j]<=1000050;j++)
		{
			notprime[i*prime[j]]=true;
			if (i%prime[j]==0) break;
		}
	}
}
int main()
{
	getprime();
	int x,step=0;
	cin>>x;
	while (x>=4)
	{
		int loc=lower_bound(prime+1,prime+cnt+1,x)-prime;
		loc--;
		while (loc>0 && notprime[(x-prime[loc])]) loc--;
		x=prime[loc]-(x-prime[loc]);step++;
	}
	cout<<step<<endl;
	return 0;
}
