#include<bits/stdc++.h>
using namespace std;
int len[4000050];
void manacher(string str,int len[])
{
	//string str=' '+strr;
	int n=str.size();len[0]=1;
	for (int i=1,j=0;i<(n<<1)-1;i++)
	{
		int p=i>>1,q=i-p,r=((j+1)>>1)+len[j]-1;
		len[i]=r<q?0:min(r-q+1,len[(j<<1)-i]);
		while (p>len[i]-1 && q+len[i]<n && str[p-len[i]]==str[q+len[i]]) ++len[i];
		if (q+len[i]-1>r) j=i;
	}
}
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	int T;
	cin>>T;
	while (T--)
	{
		string s1,s2;
		cin>>s1>>s2;
		if (s1==s2)
		{
			for (int i=0;i<=2*s1.size()-1;i++) len[i]=0;
			manacher(s1,len);
			long long val=0;
			for (int i=0;i<=2*s1.size()-1;i++) val+=len[i];
			cout<<val<<endl;
			continue;
		}
		else
		{
			int L = 0, R = s1.size() - 1;
			while (s1[L] == s2[L])
				L++;
			while (s1[R] == s2[R])
				R--;
			int b = true;
			for (int i = L, j = R; i <= R; i++, j--)
			{
				if (s1[i] != s2[j])
				{
					b = false;
					break;
				}
			}
			if (!b)
			{
				cout << 0 << endl;
				continue;
			}
			int ans = 1;
			L--, R++;
			while (L >= 0 && R < s1.size() && s1[L] == s1[R])
				ans++, L--, R++;
			cout << ans << endl;
		}

	}
	return 0;
}
