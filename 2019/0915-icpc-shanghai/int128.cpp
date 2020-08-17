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
int main()
{
	__int128 a,b;
	read(a);read(b);
	out(a+b);
	return 0;
}
