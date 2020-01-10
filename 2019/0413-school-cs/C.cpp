#include<bits/stdc++.h>
using namespace std;
int main()
{
	static int blk[101],blk2[101];
	static int ans[201];
	int rev11,rev12,rev21,rev22,cur11,cur12,cur21,cur22;
	int cnt,cnt2;
	int T;
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>T;
	int cas=0;
	while (T--)
	{
		string s1,s2;
		cin>>s1>>s2;
		cnt=s1.length(),cnt2=s2.length();
		for (int i=1;i<=cnt;i++) blk[i]=s1[i-1]-'0';
		for (int i=1;i<=cnt2;i++) blk2[i]=s2[i-1]-'0';
		cur11=1,cur12=cnt,cur21=1,cur22=cnt2;
		int ansl=0;
		while (ansl!=cnt+cnt2)
		{
			int maxn=0;
			string maxv="0";
			int tag=0;
			string r1,r2,r3,r4;
			r1=r2=r3=r4="";
			if (cur11<cur12)
			{
				for (int i=cur11+1;i<=cur12;i++) r1+=char(blk[i]+'0');
				for (int i=cur12-1;i>=cur11;i--) r2+=char(blk[i]+'0');
			}
			if (cur21<cur22)
			{
				for (int i=cur21+1;i<=cur22;i++) r3+=char(blk2[i]+'0');
				for (int i=cur22-1;i>=cur21;i--) r4+=char(blk2[i]+'0');
			}
			if (cur11<cur12)
			{
				if (blk[cur11]>maxn||(blk[cur11]==maxn && r1>maxv))
				{
					maxn=blk[cur11],maxv=r1;
					tag=1;
				}
				if (blk[cur12]>maxn||(blk[cur12]==maxn && r2>maxv))
				{
					maxn=blk[cur12],maxv=r2;
					tag=2;
				}
			}
			else
			if (cur11==cur12)
			{
				if (blk[cur11]>maxn)
				{
					maxn=blk[cur11];
					tag=1;
				}
			}
			if (cur21<cur22)
			{
				if (blk2[cur21]>maxn||(blk2[cur21]==maxn && r3>maxv))
				{
					maxn=blk2[cur21],maxv=r3;
					tag=3;
				}
				if (blk2[cur22]>maxn||(blk2[cur22]==maxn && r4>maxv))
				{
					maxn=blk2[cur22],maxv=r4;
					tag=4;
				}
			}
			else
			if (cur21==cur22)
			{
				if (blk2[cur21]>maxn)
				{
					maxn=blk2[cur21];
					tag=3;
				}
			}
			if (tag==1) ++cur11;
			if (tag==2) --cur12;
			if (tag==3) ++cur21;
			if (tag==4) --cur22;
			ans[++ansl]=maxn;
		}
		cout<<"Case #"<<++cas<<": ";
		for (int i=1;i<=ansl;i++) cout<<ans[i];cout<<endl;
	}
	return 0;
}