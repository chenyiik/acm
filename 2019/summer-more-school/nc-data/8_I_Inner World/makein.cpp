#include<bits/stdc++.h>
#define LL long long
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
using namespace std;
const int Maxn=1000005;
int l[Maxn],r[Maxn];
pair<int,int> Shrink(int a,int b){
	if (a==b) return mp(a,b);
	if (b-a<1000){
		if (rand()&1) a++;
		else b--;
		return mp(a,b);
	}
	int M=b-a+1;
	M/=500;
	a+=rand()*rand()%M;
	b-=rand()*rand()%M;
	return mp(a,b);
}
int main(){
	freopen("13.in","w",stdout);
	srand(time(0));
	int n=300000,m=300000,q=300000;
	printf("%d %d\n",n,m);
	l[1]=1;r[1]=n;
	for (int i=2;i<=m+1;i++){
		int p=rand()%min((i-1),10)+1;
	//	int p=1;
		pair<int,int> v=Shrink(l[p],r[p]);
		l[i]=v.first,r[i]=v.second;
		printf("%d %d %d %d\n",p,i,l[i],r[i]);
	}
	printf("%d\n",q);
	for (int i=0;i<q;i++){
		int u=rand()*rand()%(m+1)+1;
		int lo=rand()*rand()%n+1,hi=rand()*rand()%n+1;
		if (lo>hi) swap(lo,hi);
		printf("%d %d %d\n",u,lo,hi);
	}
	return 0;
}
