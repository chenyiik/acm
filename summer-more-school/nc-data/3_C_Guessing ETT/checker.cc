#include<bits/stdc++.h>
#include "testlib.h"
#define N 1000005
using namespace std;
int a[N],b[N],n;
int check(int *a,int n){
	if (a[1]!=1) return 0;
	static int pop[N],push[N],go[N];
	for (int i=1;i<=n;i++) pop[i]=0,push[i]=0,go[i]=0;
	
	static vector<int>now; now.clear();
	now.push_back(1);push[1]=1;
	for (int i=2;i<2*n;i++)
		if (a[i]<=0||a[i]>n) return 0;
		else if (now.size()>1&&a[i]==now[now.size()-2])
			push[now.back()]=0,pop[now.back()]=1,now.pop_back();
		else if (pop[a[i]]||push[a[i]]) return 0;
		else now.push_back(a[i]),push[a[i]]=1;
	for (int i=1;i<2*n;i++) go[a[i]]=1;
	for (int i=1;i<=n;i++) if (!go[i]) return 0;
	if (now.size()!=1||now[0]!=1) return 0;
	return 1;
}

int main(int argc, char* argv[])
{
    registerTestlibCmd(argc, argv);
	int T;
	//FILE *A = fopen(argv[1],"r"), *B = fopen(argv[2],"r");fscanf(A, "%d", &T);
	T=inf.readInt(1, 500000, "T");//inf.readEoln();
	
	while (T--){
		//fscanf(A, "%d", &n);
		n=inf.readInt(1, 250000, "n");//inf.readEoln();
		for (int i=1;i<2*n;i++){
			//fscanf(A, "%d", &b[i]);fscanf(B, "%d", &a[i]);
			b[i]=inf.readInt(-1, n, "b_i");
			a[i]=ouf.readInt(1, n, "a_i"); 
			//if (i==2*n-1) inf.readEoln(),ouf.readEoln();else inf.readSpace(),ouf.readSpace();
			if (!(b[i]==-1||a[i]==b[i])) quitf(_wa,"wa1");//return 1;
		}
		if (!check(a,n)) quitf(_wa,"wa2");//return 1;
	}
	quitf(_ok,"ac");
	return 0;
}
