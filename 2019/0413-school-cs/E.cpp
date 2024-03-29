#include<bits/stdc++.h>
using namespace std;
const int N=9;
const int MaxN=N*N*N+10;
const int MaxM=N*N*4+10;
const int maxnode=MaxN*4+MaxM+10;
char g[MaxN];
struct DLX
{
	int n,m,size;
	int U[maxnode],D[maxnode],R[maxnode],L[maxnode],Row[maxnode],Col[maxnode];
	int H[MaxN],S[MaxM];
	int ansd,ans[MaxN];
	void init(int _n,int _m)
	{
		n=_n,m=_m;
		for (int i=0;i<=m;i++)
		{
			S[i]=0;
			U[i]=D[i]=i;
			L[i]=i-1;
			R[i]=i+1;
		}
		R[m]=0;L[0]=m;
		size=m;
		for (int i=1;i<=n;i++) H[i]=-1;
	}
	void Link(int r,int c)
	{
		++S[Col[++size]=c];
		Row[size]=r;
		D[size]=D[c];
		U[D[c]]=size;
		U[size]=c;
		D[c]=size;
		if (H[r]<0) H[r]=L[size]=R[size]=size;
		else
		{
			R[size]=R[H[r]];
			L[R[H[r]]]=size;
			L[size]=H[r];
			R[H[r]]=size;
		}
	}
	void remove(int c)
	{
		L[R[c]]=L[c];R[L[c]]=R[c];
		for (int i=D[c];i!=c;i=D[i])
		for (int j=R[i];j!=i;j=R[j])
		{
			U[D[j]]=U[j];
			D[U[j]]=D[j];
			--S[Col[j]];
		}
	}
	void resume(int c)
	{
		for (int i=U[c];i!=c;i=U[i])
		for (int j=L[i];j!=i;j=L[j])
		++S[Col[U[D[j]]=D[U[j]]=j]];
		L[R[c]]=R[L[c]]=c;
	}
	bool Dance(int d)
	{
		if (R[0]==0)
		{
			for (int i=0;i<d;i++) g[(ans[i]-1)/9]=(ans[i]-1)%9+'1';
			for (int i=0;i<N;i++) {
			for (int j=0;j<N;j++)
				printf("%c%c",g[i*N+j]," \n"[j==N-1]);
			}
			return true;
		}
		int c=R[0];
		for (int i=R[0];i!=0;i=R[i])
		if (S[i]<S[c]) c=i;
		remove(c);
		for (int i=D[c];i!=c;i=D[i])
		{
			ans[d]=Row[i];
			for (int j=R[i];j!=i;j=R[j]) remove(Col[j]);
			if (Dance(d+1)) return true;
			for (int j=L[i];j!=i;j=L[j]) resume(Col[j]);
		}
		resume(c);
		return false;
	}
};
void place(int &r,int &c1,int &c2,int &c3,int &c4,int i,int j,int k)
{
	r=(i*N+j)*N+k;c1=i*N+j+1;c2=N*N+i*N+k;
	c3=N*N*2+j*N+k;c4=N*N*3+((i/3)*3+(j/3))*N+k;
}
DLX dlx;
int main()
{
	dlx.init(N*N*N,N*N*4);
	int r,c1,c2,c3,c4;
	static int graph[N][N];
	for (int i=0;i<N;i++)
	for (int j=0;j<N;j++)
	scanf("%d",&graph[i][j]);
	for (int i=0;i<N;i++)
	for (int j=0;j<N;j++)
	g[i*N+j]=(graph[i][j]==0)?'.':'0'+graph[i][j];
	for (int i=0;i<N;i++)
	for (int j=0;j<N;j++)
	for (int k=1;k<=N;k++)
	if (g[i*N+j]=='.'||g[i*N+j]=='0'+k)
	{
		place(r,c1,c2,c3,c4,i,j,k);
		dlx.Link(r,c1);
		dlx.Link(r,c2);
		dlx.Link(r,c3);
		dlx.Link(r,c4);
	}
	dlx.Dance(0);
	return 0;
}