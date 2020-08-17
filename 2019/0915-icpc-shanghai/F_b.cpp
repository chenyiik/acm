#include<bits/stdc++.h>
using namespace std;
inline void read(__int128& x)
{
	int w=0;x=0;
	char ch=getchar();
	while (!isdigit(ch)) {w|=(ch=='-');ch=getchar();}
	while (isdigit(ch)) x=x*10+ch-'0',ch=getchar();
	if (w) x=-x;
}
void out(__int128 x)
{
	if (!x) return;
	if (x<0) putchar('-'),x=-x;
	out(x/10);
	putchar(x%10+'0');
}
using ll=__int128;
ll f[105][105];
int main()
{
	ll T;
	for (char ch='A';ch<='Z';ch++) f[ch][0]=1,f[ch][1]=26;
	read(T);
	while (T--)
	{
		int n,k;
		
