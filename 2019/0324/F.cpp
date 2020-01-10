#include<bits/stdc++.h>
using namespace std;
int main()
{
	static int f[1001];
	static int a[10000000];
	memset(f,0,sizeof(f));
	memset(a,0,sizeof(a));
	for (int i=0;i<=999999;i++)
	{
		int a1=i/100000,a2=(i%100000)/10000,a3=(i%10000)/1000,a4=(i%1000)/100,a5=(i%100)/10,a6=i%10;
		int l1=a1+a2+a3,l2=a4+a5+a6;
		int tmp=abs(l1-l2);
		/*if(tmp==0)
			printf("%d %d %d\n",i,l1,l2);*/
		f[tmp]++;
		for (int j=0;j<tmp;j++) a[i]+=f[j];
	}
	//cout<<f[0]<<endl;
	//cout<<f[1]<<endl;
	int n;
	ios::sync_with_stdio(0);//cin.tie(0);
	cin>>n;
	while (n--)
	{
		int smg;
		cin>>smg;
		cout<<a[smg]<<endl;
	}
	return 0;
}
