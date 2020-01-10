#include<cstdio>
#include<cstring>
#define M 100005
char str[M],mp[500];
int main(){
	int cas,T;
	scanf("%d",&T);
	for(cas=1;cas<=T;cas++){
		scanf("%s %s",str,mp+'a');
		int len=strlen(str);
		int h=0,d=0,w=0;
		for(int i=0;i<len;i++){
			if(mp[(int)str[i]]=='h')h++;
			if(mp[(int)str[i]]=='d')d++;
			if(mp[(int)str[i]]=='w')w++;
		}
		if(4*h>=(h+d+w))printf("Case #%d: Harmful\n",cas);
		else if(10*h<=(h+d+w))printf("Case #%d: Recyclable\n",cas);
		else if(d>=2*w)printf("Case #%d: Dry\n",cas);
		else printf("Case #%d: Wet\n",cas);
	}
	return 0;
}
